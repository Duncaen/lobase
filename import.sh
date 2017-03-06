#!/bin/sh

: ${OPENBSD_BRANCH:=$(cat OPENBSD_BRANCH)}
: ${OPENBSD_CVS:=anoncvs@ftp.hostserver.de:/cvs}

import() {
	for x; do mods="$mods src/$x"; done
	cd "$tmp"
	cvs -d "${OPENBSD_CVS}" get -r "${OPENBSD_BRANCH}" $mods
	cd ..
}

tmp=$(mktemp -d ./import-XXXXXX)
trap 'rm -rf "$tmp"' INT

import $@
for x; do
	find "$tmp/src/$x" -type d -name CVS -prune -exec rm -rf {} \;
	if [ -d "$x" ]; then
		:
	else
		mkdir -p "${x%%/*}"
		cp -r "$tmp/src/$x" "$x"
		sed -i 's|.\(include\) <\(.*\)>|\1 \2|' "$x/Makefile"
		sed -i 's|.PATH:|VPATH+=|g' "$x/Makefile"
	fi
done

rm -rf "$tmp"

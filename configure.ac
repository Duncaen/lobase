AC_PREREQ([2.68])
AC_INIT([lobase], [0.0], [https://github.com/Duncaen/lobase/issues], [lobase])
AC_CONFIG_SRCDIR([])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_INSTALL
AC_PROG_YACC
AC_PROG_LEX
AN_MAKEVAR([AR], [AC_PROG_AR])
AN_PROGRAM([ar], [AC_PROG_AR])
AC_DEFUN([AC_PROG_AR], [AC_CHECK_TOOL(AR, ar, :)])
AC_PROG_AR

AC_SUBST([HOSTCC], [${HOSTCC:=${CC}}])

# Checks for libraries.
AC_CHECK_LIB(crypt, crypt)
AC_CHECK_LIB(rt, clock_gettime)

# Checks for header files.
AC_CHECK_HEADERS([sys/tree.h login_cap.h])
AC_HEADER_TIME
AC_HEADER_DIRENT
AC_PROG_RANLIB

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_INT64_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_FORK
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MMAP
AC_CHECK_FUNCS([strlcpy strlcat dl_iterate_phdr getentropy strptime issetugid fgetln reallocarray explicit_bzero getdtablecount])

AC_CHECK_DECLS([sys_siglist, sys_signame], [], [], [
#include <signal.h>
])

# AC_SUBST(HAVE_STRLCAT, "$have_strlcat")
# AC_SUBST(HAVE_STRLCPY, "$have_strlcpy")
# AC_SUBST(HAVE_GETENTROPY, "$have_getentropy")
# AC_SUBST(HAVE_FGETLN, "$ac_cv_func_fgetln")

AS_IF([test "x$ac_cv_func_fgetln" = "xyes"],[AC_SUBST(HAVE_FGETLN, 1)],[])
AS_IF([test "x$ac_cv_func_strlcat" = "xyes"],[AC_SUBST(HAVE_STRLCAT, 1)],[])
AS_IF([test "x$ac_cv_func_strlcpy" = "xyes"],[AC_SUBST(HAVE_STRLCPY, 1)],[])
AS_IF([test "x$ac_cv_func_getentropy" = "xyes"],[AC_SUBST(HAVE_GETENTROPY, 1)],[])
AS_IF([test "x$ac_cv_func_explicit_bzero" = "xyes"],[AC_SUBST(HAVE_EXPLICIT_BZERO, 1)],[])
AS_IF([test "x$ac_cv_func_reallocarray" = "xyes"],[AC_SUBST(HAVE_REALLOCARRAY, 1)],[])
AS_IF([test "x$ac_cv_func_recallocarray" = "xyes"],[AC_SUBST(HAVE_RECALLOCARRAY, 1)],[])
AS_IF([test "x$ac_cv_have_decl_sys_siglist" = "xyes"],[AC_SUBST(HAVE_SYS_SIGLIST, 1)],[])
AS_IF([test "x$ac_cv_have_decl_sys_signame" = "xyes"],[AC_SUBST(HAVE_SYS_SIGNAME, 1)],[])

AC_DEFINE_UNQUOTED([_PATH_TTY], ["/dev/tty"], [Path to tty.])
AC_DEFINE_UNQUOTED([_PATH_UUCPLOCK], ["/var/spool/lock"], [Serial device lock file path.])

AC_CONFIG_FILES([config.mk])
AC_OUTPUT

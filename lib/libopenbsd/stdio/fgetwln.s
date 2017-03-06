	.file	"fgetwln.c"
	.local	fb_pool
	.comm	fb_pool,768,32
	.local	fb_pool_cur
	.comm	fb_pool_cur,4,4
	.text
	.globl	fgetwln
	.type	fgetwln, @function
fgetwln:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	$0, -16(%rbp)
	movl	fb_pool_cur(%rip), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$fb_pool, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	-40(%rbp), %rax
	je	.L2
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L2
	movl	fb_pool_cur(%rip), %eax
	addl	$1, %eax
	movl	%eax, fb_pool_cur(%rip)
	movl	fb_pool_cur(%rip), %eax
	cltd
	shrl	$27, %edx
	addl	%edx, %eax
	andl	$31, %eax
	subl	%edx, %eax
	movl	%eax, fb_pool_cur(%rip)
	movl	fb_pool_cur(%rip), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$fb_pool, %rax
	movq	%rax, -8(%rbp)
.L2:
	movq	-8(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L3
.L10:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L4
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	-16(%rbp), %rax
	ja	.L5
.L4:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L6
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	leaq	(%rax,%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L7
.L6:
	movq	-8(%rbp), %rax
	movq	$128, 16(%rax)
.L7:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	reallocarray
	cltq
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	.L8
	movq	$0, -16(%rbp)
	jmp	.L9
.L8:
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L5:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -16(%rbp)
	salq	$2, %rax
	leaq	(%rcx,%rax), %rdx
	movl	-20(%rbp), %eax
	movl	%eax, (%rdx)
	cmpl	$10, -20(%rbp)
	je	.L14
.L3:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	fgetwc
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	jne	.L10
	jmp	.L9
.L14:
	nop
.L9:
	movq	-48(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	cmpq	$0, -16(%rbp)
	je	.L11
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	jmp	.L13
.L11:
	movl	$0, %eax
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	fgetwln, .-fgetwln
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits

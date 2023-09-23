	.file	"1-1.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "\307\353\312\344\310\353\272\364\275\320\302\245\262\343\241\242\304\277\265\304\302\245\262\343\322\324\274\260\265\347\314\335\313\371\324\332\302\245\262\343\0"
.LC1:
	.ascii "%d %d %d\0"
	.align 8
.LC2:
	.ascii "\265\347\314\335\324\332\265\332%d\262\343\243\254\265\347\314\335\277\252\312\274\324\313\320\320\243\254\264\313\312\261\265\347\314\335\300\357\323\320"
	.ascii "0\310\313\12\0"
	.align 8
.LC3:
	.ascii "\265\347\314\335\324\332\265\332%d\262\343\243\254\265\347\314\335\324\313\320\320\301\313%d\270\366\265\245\316\273\312\261\274\344\243\254\264\313\312\261\265\347\314\335\300\357\323\320"
	.ascii "1\310\313\12\0"
	.align 8
.LC4:
	.ascii "\265\347\314\335\324\332\265\332%d\262\343\243\254\265\347\314\335\324\313\320\320\301\313%d\270\366\265\245\316\273\312\261\274\344\243\254\264\313\312\261\265\347\314\335\300\357\323\320"
	.ascii "0\310\313\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	-8(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %edx
	subl	%edx, %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	movl	-4(%rbp), %edx
	movl	%eax, %r8d
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	xorl	%eax, %edx
	subl	%eax, %edx
	movl	-4(%rbp), %eax
	movl	-12(%rbp), %ecx
	subl	%ecx, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	xorl	%ecx, %eax
	subl	%ecx, %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	getch;	.scl	2;	.type	32;	.endef

.section .text
.globl main
main:
	call CALL1
	.string "ZmxhZy1lMzgxZjNiM2YwMjA="

# 666c 6167 2d64 6261 3939 3035 6230 3431  flag-dba9905b041
#                     9696 9f9a (^0xaf)
#                02 (-0x60)
#                  e0 (+0x7f)
# 9993 9e98 (^0xff)

CALL2:
	movl $0x31343062,16(%esp)
	xorb $0xaf,14(%esp)
	xorb $0xaf,15(%esp)
	movw $0x9399,4(%esp)
	call CALL3

CALL4:
	movw $0xe002,18(%esp)
	jmp CALL5

CALL1:
	movl $0x00000000,8(%esp)
	sub $0x8,%esp
	movl $0x9a9f9696,8(%esp)
	call CALL2

CALL3:
	movw $0x989e,10(%esp)
	xorb $0xaf,16(%esp)
	xorb $0xaf,17(%esp)
	movw $0x642d,12(%esp)
	addb $0xde,2(%esp)
	addb $0xad,1(%esp)
	addb $0xbe,2(%esp)
	addb $0xef,3(%esp)
	call CALL4

TEXT:
	.string "Il y 3 flags.\n"
TEXTLEN:
	.int TEXTLEN-TEXT
	.string "easy flag: flag-f1e62f4504da"

CALL5:
	subb $0x7f,19(%esp)
	addb $0x60,18(%esp)
	addl $12,%esp
	xorl $0xffffffff,(%esp)

	movl $0x4,%eax
	movl $0x1,%ebx
	movl $TEXT,%ecx
	movl TEXTLEN,%edx
	int $0x80

	movl $0x01,%eax
	movl $0x06,%ebx
	int	$0x80


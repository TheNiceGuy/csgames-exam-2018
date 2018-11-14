.section .text

.globl ask_credentials
.globl main

main:
	movl $0x1a,%eax
	movl $0x00,%ebx
	movl $0x00,%ecx
	movl $0x00,%edx
	movl $0x00,%esi
	int $0x80

	cmp $0x00,%eax
	je not_traced

being_traced:
	movl $0x01,%eax
	movl $0x00,%ebx
	int $0x80

not_traced:
	movl $0x02,%eax
	movl $0x00,%ebx
	int $0x80

	cmp $0x00,%eax
	je child

parent:
	movl $-1,%ebx
	movl $0x07,%eax
	movl $0x00,%ecx
	movl $0x00,%edx
	int $0x80

	movl $0x01,%eax
	movl $0x00,%ebx
	int $0x80

child:
	call ask_credentials

	movl $0x01,%eax
	movl $0x00,%ebx
	int $0x80
	
	
	

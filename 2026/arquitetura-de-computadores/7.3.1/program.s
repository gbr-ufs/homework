.data

mem_base:
	.word 10                # Equivalente ao Mem[0x2000] = 10
	.word 0                 # offset +4
	.word 0                 # offset +8
	.word 0                 # offset +12 (onde sw grava: x9 + 8)

	.text
	.globl _start

_start:
# Estado inicial conforme o livro:
la x9, mem_base + 4    # x9 aponta 4 bytes após a base.
li x5, 6               # x5 = 6

L7:
	lw  x6, -4(x9)          # x6 = Mem[mem_base] = 10
	sw  x6, 8(x9)           # Mem[mem_base + 12] = 10
	or  x4, x5, x6          # x4 = 6 | 10 = 14
	beq x4, x4, L7          # Loop infinito.

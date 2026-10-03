.data

# Dimensão da matriz quadrada (potências de 2).
N:
	.word 4

# Matrizes.

matriz_A:
	.word 1, 2, 3, 4
	.word 5, 6, 7, 8
	.word 9, 10, 11, 12
	.word 13, 14, 15, 16

matriz_B:
	.word 17, 18, 19, 20
	.word 21, 22, 23, 24
	.word 25, 26, 27, 28
	.word 29, 30, 31, 32

matriz_C:
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0

# Texto para impressão.

space:
	.asciz " "

newline:
	.asciz "\n"

.text
.globl main
.globl square_matrix_multiply_recursive

main:
	la   a0, matriz_A
	la   a1, matriz_B
	la   a2, matriz_C
	lw   a3, N
	lw   a4, N
	jal  ra, square_matrix_multiply_recursive

	la   s0, matriz_C
	lw   s1, N           # s1 = total de linhas (N)
	lw   s2, N           # s2 = total de colunas (N)
	li   s3, 0           # s3 = índice de linha (i = 0)

print_row:
	bge  s3, s1, exit
	li   s4, 0

print_col:
	bge  s4, s2, print_row_end

	# Cálculo do endereço.
	# &C[i][j] = matriz_C + ((i * N) + j) * 4
	mul  t0, s3, s2
	add  t0, t0, s4
	slli t0, t0, 2
	add  t0, s0, t0

	# Impressão do número.
	lw   a0, 0(t0)
	li   a7, 1
	ecall

	# Impressão do espaço.
	la   a0, space
	li   a7, 4
	ecall

	addi s4, s4, 1
	j    print_col

print_row_end:
	la   a0, newline
	li   a7, 4
	ecall
	addi s3, s3, 1
	j    print_row

exit:
	li   a7, 10
	ecall

square_matrix_multiply_recursive:
	li   t0, 1
	bne  a3, t0, recursive

	# n == 1
	# C += A * B
	lw   t0, 0(a0)       # t0 = *A
	lw   t1, 0(a1)       # t1 = *B
	mul  t2, t0, t1      # t2 = (*A) * (*B)
	lw   t3, 0(a2)       # t3 = *C
	add  t3, t3, t2      # t3 = *C + (*A) * (*B)
	sw   t3, 0(a2)       # *C = t3
	ret

recursive:
	addi sp, sp, -32
	sw   ra, 28(sp)
	sw   s0, 24(sp)
	sw   s1, 20(sp)
	sw   s2, 16(sp)
	sw   s3, 12(sp)
	sw   s4, 8(sp)
	sw   s5, 4(sp)
	sw   s6, 0(sp)

	mv   s0, a0
	mv   s1, a1
	mv   s2, a2
	srli s3, a3, 1
	mv   s4, a4

	slli s5, s3, 2

	mul  s6, s5, s4

	# 1. C11 += A11 * B11
	mv   a0, s0
	mv   a1, s1
	mv   a2, s2
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 2. C11 += A12 * B21
	add  a0, s0, s5
	add  a1, s1, s6
	mv   a2, s2
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 3. C12 += A11 * B12
	mv   a0, s0
	add  a1, s1, s5
	add  a2, s2, s5
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 4. C12 += A12 * B22
	add  a0, s0, s5
	add  t0, s5, s6
	add  a1, s1, t0
	add  a2, s2, s5
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 5. C21 += A21 * B11
	add  a0, s0, s6
	mv   a1, s1
	add  a2, s2, s6
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 6. C21 += A22 * B21
	add  t0, s5, s6
	add  a0, s0, t0
	add  a1, s1, s6
	add  a2, s2, s6
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 7. C22 += A21 * B12
	add  a0, s0, s6
	add  a1, s1, s5
	add  t0, s5, s6
	add  a2, s2, t0
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# 8. C22 += A22 * B22
	add  t0, s5, s6
	add  a0, s0, t0
	add  a1, s1, t0
	add  a2, s2, t0
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	lw   ra, 28(sp)
	lw   s0, 24(sp)
	lw   s1, 20(sp)
	lw   s2, 16(sp)
	lw   s3, 12(sp)
	lw   s4, 8(sp)
	lw   s5, 4(sp)
	lw   s6, 0(sp)
	addi sp, sp, 32
	ret

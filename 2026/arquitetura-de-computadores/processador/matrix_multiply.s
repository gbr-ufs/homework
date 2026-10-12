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

.text
.globl main
.globl square_matrix_multiply_recursive

main:
	# Inicializa stack pointer
	li   sp, 256

	# Carrega argumentos
	# matriz_A está no endereço 0
	# matriz_B está no endereço 64
	# matriz_C está no endereço 128
	li   a0, 0
	li   a1, 64
	li   a2, 128
	li   a3, 4
	li   a4, 4
	jal  ra, square_matrix_multiply_recursive

	# Sinaliza fim da execução escrevendo 1 no endereço 192
	li   t0, 1
	sw   t0, 192(zero)

done:
	beq  zero, zero, done

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

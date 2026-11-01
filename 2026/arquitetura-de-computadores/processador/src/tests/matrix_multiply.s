# Início da parte de dados.
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

# Matriz de resultado.
matriz_C:
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0
	.word 0, 0, 0, 0

# Início da parte do código.
.text

# Labels.
.globl main
.globl square_matrix_multiply_recursive

# Ponto de entrada do programa.
main:
	# Inicializa stack pointer.
        # 256 é o endereço do fim da memória de dados do processador (veja: dmem.v).
	li   sp, 256

	# Carrega argumentos.
        # Cada matriz tem dimensão 4 x 4 (16 words). Como cada word ocupa 4 bytes, a gente
        # carrega as matrizes de 64 em 64.
	li   a0, 0
	li   a1, 64
	li   a2, 128
	li   a3, 4 # 4 = N atual da submatriz. Dividido por 2 a cada recursão.
	li   a4, 4 # 4 = N global.
	jal  ra, square_matrix_multiply_recursive

	# Sinaliza fim da execução.
        # 1 é um valor arbitrário que é usado pela testbench para verificar se a execução terminou.
        # 192 foi escolhido pois a matriz C termina no endereço 191. Então, 192 é o próximo endereço livre.
	li   t0, 1
	sw   t0, 192(zero)

# Label para o fim da execução para evitar fall-through na função abaixo.
done:
	beq  zero, zero, done

# Função recursiva para multiplicação de matrizes quadradas.
#
# Argumentos:
# - a0: Endereço base da matriz A.
# - a1: Endereço base da matriz B.
# - a2: Endereço base da matriz C.
# - a3: Dimensão da submatriz (N atual).
# - a4: Dimensão da matriz original (N global).
# Retorna:
# - a2: Endereço base da matriz C (resultado).
square_matrix_multiply_recursive:
        # Caso recursivo.
	li   t0, 1
	bne  a3, t0, recursive

        # Caso base:
        # A, B e C são matrizes 1 x 1. Então, a multiplicação é simplesmente C[0][0] += A[0][0] * B[0][0].
	lw   t0, 0(a0)       # t0 = A[0][0]
	lw   t1, 0(a1)       # t1 = B[0][0]
	mul  t2, t0, t1      # t2 = A[0][0] * B[0][0]
	lw   t3, 0(a2)       # t3 = C[0][0]
	add  t3, t3, t2      # t3 = C[0][0] + A[0][0] * B[0][0]
	sw   t3, 0(a2)       # C[0][0] = C[0][0] + A[0][0] * B[0][0]
	ret

# Parte recursiva da função de multiplicação de matrizes quadradas.
#
# Argumentos:
# - a0: Endereço base da matriz A.
# - a1: Endereço base da matriz B.
# - a2: Endereço base da matriz C.
# - a3: Dimensão da submatriz (N atual).
# - a4: Dimensão da matriz original (N global).
# Retorna:
# - a2: Endereço base da matriz C (resultado).
recursive:
        # Alocando espaço na pilha. Por convenção, a pilha no RISC-V é descrescente.
        # 32 porque vamos salvar 8 registradores de 4 bytes cada (a função faz 8 chamadas recursivas).
	addi sp, sp, -32
	sw   ra, 28(sp) # Retorno.
	sw   s0, 24(sp) # Endereço base da matriz A.
	sw   s1, 20(sp) # Endereço base da matriz B.
	sw   s2, 16(sp) # Endereço base da matriz C.
	sw   s3, 12(sp) # Dimensão da submatriz (N atual).
	sw   s4, 8(sp)  # Dimensão da matriz original (N global).
	sw   s5, 4(sp)  # Passo horizontal para acessar os blocos da direita.
	sw   s6, 0(sp)  # Passo vertical para acessar os blocos de baixo.
        # Essa questão de "direita" e "baixo" vem do fato de que esse algoritmo divide a matriz em
        # 4 blocos (A11, A12, A21, A22) e (B11, B12, B21, B22).
        # Na memória, a matriz é armazenada em linha reta, então para ir para um bloco na direita,
        # a gente precisa pular n/2 colunas para a direita.
        # Enquanto para ir para um bloco embaixo, a gente precisa pular n/2 linhas pra baixo.

        # Divisão da matriz nos 4 blocos.

        # Guardando os registradores que serão usados para armazenar os argumentos das chamadas recursivas.
	mv   s0, a0
	mv   s1, a1
	mv   s2, a2
        # Cálculo da dimensão da submatriz (N atual) e dos passos para acessar os blocos.
	srli s3, a3, 1
        # Preservação da largura total.
	mv   s4, a4

        # Cálcuo do deslocamento para a direita.
        # É um shift para a esquerda de 2 bits porque cada elemento da matriz é uma word (4 bytes).
	slli s5, s3, 2

        # Cálculo do deslocamento para baixo.
        # Multiuplica pela largura total da matriz para pular n/2 linhas para baixo.
	mul  s6, s5, s4

	# C11 += A11 * B11
	mv   a0, s0
	mv   a1, s1
	mv   a2, s2
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C11 += A12 * B21
	add  a0, s0, s5
	add  a1, s1, s6
	mv   a2, s2
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C12 += A11 * B12
	mv   a0, s0
	add  a1, s1, s5
	add  a2, s2, s5
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C12 += A12 * B22
	add  a0, s0, s5
	add  t0, s5, s6
	add  a1, s1, t0
	add  a2, s2, s5
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C21 += A21 * B11
	add  a0, s0, s6
	mv   a1, s1
	add  a2, s2, s6
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C21 += A22 * B21
	add  t0, s5, s6
	add  a0, s0, t0
	add  a1, s1, s6
	add  a2, s2, s6
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C22 += A21 * B12
	add  a0, s0, s6
	add  a1, s1, s5
	add  t0, s5, s6
	add  a2, s2, t0
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

	# C22 += A22 * B22
	add  t0, s5, s6
	add  a0, s0, t0
	add  a1, s1, t0
	add  a2, s2, t0
	mv   a3, s3
	mv   a4, s4
	jal  ra, square_matrix_multiply_recursive

        # Desalocando espaço na pilha e restaurando os registradores salvos.
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

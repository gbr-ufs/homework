# Processador RISC-V (Ciclo Único)

Implementação em SystemVerilog de um microprocessador de ciclo único baseado na Seção 7.6.1 do livro *Digital Design and Computer Architecture: RISC-V Edition*, com algumas extensões.

## Arquitetura

Seguindo a nomenclatura padrão do RISC-V, este processador é um RV32IM.

RV
RISC-V.

32
32 bits.

I
Suporta números inteiros.

M
Suporta multiplicação de inteiros.

## Instruções Adicionadas

Além das instruções suportadas pelo processador disponibilizado pelo livro, este processador suporta algumas outras:

- `mul`: Multiplcação.
- `jalr`: Saldo indireto via registrador.
- `bne`: Desvio condicional se não igual.
- `sll`, `slli`: Deslocamento para a esquerda.
- `srl, srli`: Deslocamento para a direita.
- `andi`: `and` imediato.
- `ori`: `or` imediato.
- `slti`: `slt` imediato.

## Requerimentos

- [Icarus Verilog](https://github.com/steveicarus/iverilog)

## Execução

```bash
make
```


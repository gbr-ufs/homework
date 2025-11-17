class Minimercado {

    public static void main(String[] args) {
        // Entrada.
        double paoQuilo = 0.00;
        double leiteLitro = 0.00;
        int vinhoQuantidade = 0;
        // Saída.
        // Pão.
        double paoPrecoQuilo = 4.50;
        double paoDescontoInicio = 1.00;
        double paoDesconto = 5.00 / 100.00;
        double paoValor = 0.00;
        double paoValorDescontado = 0.00;
        // Leite.
        double leitePrecoLitro = 5.30;
        double leiteDescontoInicio = 3.00;
        double leiteDesconto = 10.00 / 100.00;
        double leiteValor = 0.00;
        double leiteValorDescontado = 0.00;
        // Vinho.
        double vinhoPrecoGarrafa = 25.00;
        // A cada três garrafas de vinho, uma sai de graça.
        int vinhoDescontoInicio = 3;
        double vinhoValor = 0.00;
        // Total.
        double valorTotal = 0.00;

        paoQuilo = Double.parseDouble(IO.readln("Insira quantos quilos de pão: "));
        leiteLitro = Double.parseDouble(IO.readln("Insira quantos litros de leite: "));
        vinhoQuantidade = Integer.parseInt(IO.readln("Insira quantas garrafas de vinho: "));

        paoValor = paoQuilo * paoPrecoQuilo;
        if (paoQuilo >= paoDescontoInicio) {
            paoValorDescontado = paoDesconto * paoValor;
        }

        leiteValor = leiteLitro * leitePrecoLitro;
        if (leiteLitro >= leiteDescontoInicio) {
            leiteValorDescontado = leiteDesconto * leiteValor;
        }

        vinhoQuantidade -= vinhoQuantidade / vinhoDescontoInicio;
        vinhoValor = vinhoQuantidade * vinhoPrecoGarrafa;

        valorTotal = paoValor + leiteValor + vinhoValor;

        if (paoQuilo != 0.0) {
            IO.println(String.format("Pão --------------------- R$ %.2f", paoValor));
        }

        if (paoValorDescontado != 0.00) {
            IO.println(String.format("Desconto no pão --------- R$ -%.2f", paoValorDescontado));
        }

        if (leiteValor != 0.00) {
            IO.println(String.format("Leite ------------------- R$ %.2f", leiteValor));
        }

        if (leiteValorDescontado != 0.00) {
            IO.println(String.format("Desconto no leite ------- R$ -%.2f", leiteValorDescontado));
        }

        if (vinhoValor != 0.00) {
            IO.println(String.format("Vinho ------------------- R$ %.2f", vinhoValor));
        }

        if (valorTotal != 0.00) {
            IO.println(String.format("Valor Total ------------- R$ %.2f", valorTotal));
        }
    }
}

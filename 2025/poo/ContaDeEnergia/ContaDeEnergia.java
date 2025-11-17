class ContaDeEnergia {
    private static double taxar(double valor, double taxa) {
        taxa *= valor;

        return valor + taxa;
    }

    private static boolean intervalo(int inicio, int valor, int fim) {
        return valor >= inicio && valor <= fim;
    }

    public static void main(String[] args) {
        // Entrada.
        int energiaConsumida;
        // Saída.
        double taxa = 10.0 / 100.0;
        double conta = 35.0;
        double valorImpresso;
        // Até 99 KWh.
        double valor1 = 1.35;
        // De 100 até 299 KWh.
        int intervalo2Inicio = 100, intervalo2Fim = 299;
        double valor2 = 1.55;
        // De 300 até 574 KWh.
        int intervalo3Inicio = 300, intervalo3Fim = 574;
        double valor3 = 1.75;
        // Maior ou igual a 575 KWh.
        double valor4 = 2.15;

        energiaConsumida = Integer.parseInt(IO.readln("Insira a quantidade de eneriga consumida: "));

        if (energiaConsumida <= 99) {
            conta = valor1 * energiaConsumida;
            valorImpresso = valor1;
        } else if (intervalo(intervalo2Inicio, energiaConsumida, intervalo2Fim)) {
            conta = valor2 * energiaConsumida;
            valorImpresso = valor2;
        } else if (intervalo(intervalo3Inicio, energiaConsumida, intervalo3Fim)) {
            conta = valor3 * energiaConsumida;
            valorImpresso = valor3;

            if (energiaConsumida > intervalo3Inicio) {
                conta = taxar(conta, taxa);
            }
        } else {
            conta = taxar(valor4 * energiaConsumida, taxa);
            valorImpresso = valor4;
        }

        if (conta < 35.0) {
            conta = 35.0;
        }

        IO.println(String.format("R$ %.2f", conta));
        IO.println(String.format("R$ %.2f", valorImpresso));
    }
}

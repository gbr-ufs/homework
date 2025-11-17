class DiaNoMesArray {
    private static boolean bissexto(int ano) {
        return ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0));
    }

    public static void main(String[] args) {
        // Entrada.
        int mes;
        int ano;
        // Saída.
        int[] diasDoMes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int dias;

        mes = Integer.parseInt(IO.readln("Digite o mês: "));
        ano = Integer.parseInt(IO.readln("Digite o ano: "));
        dias = diasDoMes[mes];

        if (bissexto(ano)) {
            dias++;
        }

        IO.println("Esse mês tem " + dias + " dias");
    }
}

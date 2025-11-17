import java.util.HashMap;

class DiasNoMes {
    private static boolean bissexto(int ano) {
        return ((ano % 4 == 0 & ano % 100 != 0) || (ano % 400 == 0));
    }

    public static void main(String[] args) {
        // Entrada.
        int mes;
        int ano;
        // Saída.
        HashMap<Integer, Integer> diasNosMeses = new HashMap<>();
        // Janeiro.
        diasNosMeses.put(1, 31);
        // Fevereiro.
        diasNosMeses.put(2, 28);
        // Março.
        diasNosMeses.put(3, 31);
        // Abril.
        diasNosMeses.put(4, 30);
        // Maio.
        diasNosMeses.put(5, 31);
        // Junho.
        diasNosMeses.put(6, 30);
        // Julho.
        diasNosMeses.put(7, 31);
        // Agosto.
        diasNosMeses.put(8, 31);
        // Setembro.
        diasNosMeses.put(9, 30);
        // Outubro.
        diasNosMeses.put(10, 31);
        // Novembro.
        diasNosMeses.put(11, 30);
        // Dezembro.
        diasNosMeses.put(12, 31);
        int dias;

        mes = Integer.parseInt(IO.readln("Digite o mês: "));
        ano = Integer.parseInt(IO.readln("Digite o ano: "));
        dias = diasNosMeses.get(mes);

        if (bissexto(ano)) {
            dias++;
        }

        IO.println("Esse mês tem " + dias + " dias");
    }
}

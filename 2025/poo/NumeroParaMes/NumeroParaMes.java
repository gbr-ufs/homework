import java.util.HashMap;

import org.w3c.dom.ranges.RangeException;

class NumeroParaMes {
    public static void main(String[] args) throws Exception{
        // Entrada
        int numero = 0;
        // Saída.
        HashMap<Integer, String> numeroParaMes = new HashMap<>();
        numeroParaMes.put(1, "Janeiro");
        numeroParaMes.put(2, "Fevereiro");
        numeroParaMes.put(3, "Março");
        numeroParaMes.put(4, "Abril");
        numeroParaMes.put(5, "Maio");
        numeroParaMes.put(6, "Junho");
        numeroParaMes.put(7, "Julho");
        numeroParaMes.put(8, "Agosto");
        numeroParaMes.put(9, "Setembro");
        numeroParaMes.put(10, "Outubro");
        numeroParaMes.put(11, "Novembro");
        numeroParaMes.put(12, "Dezembro");

        numero = Integer.parseInt(IO.readln("Digite o número: "));

        if (numero == 0) {
            throw new ArithmeticException("Valor fora do intervalo 1-12");
        }

        IO.println(numeroParaMes.get(numero));
    }
}

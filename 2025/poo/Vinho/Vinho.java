import java.io.Console;

public class Vinho {
    public static void main(String[] args) throws Exception {
        int quantidade = 0;
        // Preço de um vinho Tabali Talinay Sauvignon Blanc.
        // Veja: <https://www.grandeadega.com.br/vinho-tabali-talinay-sauvignon-blanc/p>
        double valor = 340.90;
        double valorTotal = valor;
        String mensagemValor = "Valor: R$";
        String mensagemValorTotal = "Valor total: R$";
        Console console = System.console();

        quantidade = Integer.parseInt(console.readLine("Quantos vinhos você comprou? "));

        if (quantidade < 0) {
            throw new ArithmeticException("Quantidade inesperada, deve ser maior ou igual a zero");
        }

        if (quantidade == 0) {
            valor = 0.00;
            valorTotal = valor;
            System.out.println(mensagemValor + valor);
            System.out.println(mensagemValorTotal + valorTotal);
        } else if (quantidade == 3) {
            valorTotal = valor * (quantidade - 1);
            System.out.println(mensagemValor + valor);
            System.out.println(mensagemValorTotal + valorTotal);
        } else {
            valorTotal = valor * quantidade;
            System.out.println(mensagemValor + valor);
            System.out.println(mensagemValorTotal + valorTotal);
        }
    }
}

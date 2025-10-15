import java.io.Console;

public class ParOuImpar {
    public static void main(String[] args) {
        int numero;
        Console console = System.console();

        numero = Integer.parseInt(console.readLine("Digite um número: "));

        if (numero % 2 == 0) {
            System.out.println("É par");
        } else {
            System.out.println("É ímpar");
        }
    }
}

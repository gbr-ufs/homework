import java.io.Console;

public class Sinal {
    public static void main(String[] args) {
        int numero;
        Console console = System.console();

        numero = Integer.parseInt(console.readLine("Digite um número: "));

        if (numero == 0) {
            System.out.println("Nulo");
        } else if (numero > 0) {
            System.out.println("Positivo " + numero);
        } else {
            // Módulo do número.
            System.out.println("Negativo " + (numero * -1));
        }
    }
}

import java.io.Console;

public class MediaAritmetica {
    public static void main(String[] args) {
        double primeiro, segundo, terceiro, media;
        String mensagem = "A média aritmética destes três números é: ";
        Console console = System.console();

        primeiro = Double.parseDouble(console.readLine("Digite o primeiro número: "));
        segundo = Double.parseDouble(console.readLine("Digite o segundo número: "));
        terceiro = Double.parseDouble(console.readLine("Digite o terceiro número: "));

        media = (primeiro + segundo + terceiro) / 3;
        mensagem += media;
        System.out.println(mensagem);
    }
}

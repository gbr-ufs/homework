class Media {

    public double mediaAritmetica(double[] valores) {
        double soma = 0;

        for (int i = 0; i < valores.length; i++) {
            soma += valores[i];
        }

        return soma / valores.length;
    }
}

public class MediaAritmetica {
    public static void main(String[] args) {
        double primeiro, segundo, terceiro;
        String mensagem = "A média aritmética destes três números é: ";
        Media media = new Media();

        primeiro = Double.parseDouble(IO.readln("Digite o primeiro número: "));
        segundo = Double.parseDouble(IO.readln("Digite o segundo número: "));
        terceiro = Double.parseDouble(IO.readln("Digite o terceiro número: "));

        double[] valores = {primeiro, segundo, terceiro};
        mensagem += media.mediaAritmetica(valores);
        System.out.println(mensagem);
    }
}

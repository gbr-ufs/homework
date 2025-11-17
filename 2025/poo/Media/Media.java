public class Media {
    public static void main(String[] args) {
        double[] numeros = {0, 0, 0};
        double soma = 0.0;
        double media = 0.0;
        int contagem = 0;

        for (int i = 0; i < 3; i++) {
            numeros[i] = Double.parseDouble(IO.readln("Digite um número: "));
            soma += numeros[i];
        }

        media = soma / 3.0;

        for (int i = 0; i < 3; i++) {
            if (numeros[i] > media) {
                contagem++;
            }
        }

        IO.println(contagem);
    }
}

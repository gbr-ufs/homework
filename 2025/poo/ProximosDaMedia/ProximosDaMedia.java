class ProximosDaMedia {
    public static void main(String[] args) {
        double[] numeros = {0, 0, 0};
        double soma = 0.0;
        double media = 0.0;
        double resultado = 0.0;
        double diferencaAtual = 0.0;
        double diferencaAnterior = 0.0;

        for (int i = 0; i < 3; i++) {
            numeros[i] = Double.parseDouble(IO.readln("Digite um número: "));
            soma += numeros[i];
        }

        media = soma / 3.0;

        for (int i = 0; i < 3; i++) {
            if (i == 0) {
                diferencaAnterior = media % numeros[i];
            }

            diferencaAtual = media % numeros[i];

            if (diferencaAtual >= 0 && diferencaAtual <= 2) {
                resultado = numeros[i];
            }

            if (diferencaAtual > diferencaAnterior) {
                resultado = numeros[i - 1];
                break;
            }

            diferencaAnterior = diferencaAtual;
        }

        if (resultado != 0.0) {
            IO.println(media);
            IO.println(resultado);
        }
    }
}

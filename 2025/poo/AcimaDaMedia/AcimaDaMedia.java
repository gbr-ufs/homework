class AcimaDaMedia {
    public static void main(String[] args) {
        int n = 0;
        int[] numeros;
        int contagem = 0;
        int soma = 0;
        double media = 0;

        n = Integer.parseInt(IO.readln());
        numeros = new int[n];

        for (int i = 0; i < n; i++) {
            numeros[i] = Integer.parseInt(IO.readln());
            soma += numeros[i];
        }

        media = (double) soma / (double) n;

        for (var numero : numeros) {
            if (numero > media) {
                contagem++;
            }
        }

        IO.println(contagem);
    }
}

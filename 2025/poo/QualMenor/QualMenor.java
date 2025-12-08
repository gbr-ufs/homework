class QualMenor {
    public static void main(String[] args) throws Exception {
        int n = 0;
        int menor = 0;
        int[] numeros;

        n = Integer.parseInt(IO.readln());

        if (n == 0) {
            throw new Exception("Programa deve ler n > 0 números");
        }

        numeros = new int[n];

        for (int i = 0; i < n; i++) {
            numeros[i] = Integer.parseInt(IO.readln());
        }

        menor = numeros[0];

        for (int i = 1; i < n; i++) {
            if (numeros[i] < menor) {
                menor = numeros[i];
            }
        }

        IO.println(menor);
    }
}

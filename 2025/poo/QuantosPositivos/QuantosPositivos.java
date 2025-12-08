class QuantosPositivos {
    public static void main(String[] args) {
        int n = 0;
        int valor = 0;
        int contagem = 0;

        n = Integer.parseInt(IO.readln());

        for (int i = 0; i < n; i++) {
            valor = Integer.parseInt(IO.readln());
            if (valor > 0) {
                contagem++;
            }
        }

        IO.println(contagem);
    }
}

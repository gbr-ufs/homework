class SomaSequencia {
    public static void main(String[] args) {
        int soma = 0;

        int n = Integer.parseInt(IO.readln());

        while (n != 0) {
            soma += n;
            n = Integer.parseInt(IO.readln());
        }

        IO.println(soma);
    }
}

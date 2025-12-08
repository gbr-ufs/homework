class QuantosDivisores {
    public static void main(String[] args) {
        int n = 0;
        int contagem = 0;

        n = Integer.parseInt(IO.readln());

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                contagem++;
            }
        }

        IO.println(contagem);
    }
}

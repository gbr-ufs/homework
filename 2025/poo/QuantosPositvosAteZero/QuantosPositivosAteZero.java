class QuantosPositivosAteZero {
    public static void main(String[] args) {
        int contagem = 0;

        int n = Integer.parseInt(IO.readln());

        while (n != 0) {
            if (n > 0) {
                contagem++;
            }
            n = Integer.parseInt(IO.readln());
        }

        IO.println(contagem);
    }
}

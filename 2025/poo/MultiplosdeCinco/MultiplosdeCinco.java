class MultiplosdeCinco {
    public static void main(String[] args) {
        // Entrada.
        int primeiro = 0;
        int ultimo = 0;

        primeiro = Integer.parseInt(IO.readln());
        ultimo = Integer.parseInt(IO.readln());

        // Assumindo que o "entre" é exclusivo.
        for (int i = primeiro + 1; i < ultimo; i++) {
            if (i % 5 == 0) {
                IO.println(i);
            }
        }
    }
}

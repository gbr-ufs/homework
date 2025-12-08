class PrimoSequencial {
    // "É primo?"
    public boolean ePrimo(int n) {
        // Começando a partir do 2 pois 1 divide todos os números.
        int divisor = 2;
        boolean resultado = true;

        while (divisor < n) {
            if (n % divisor == 0) {
                resultado = false;
            }
            divisor++;
        }

        return resultado;
    }

    public static void main(String[] args) {
        PrimoSequencial primoSequencial = new PrimoSequencial();
        int n = 0;

        n = Integer.parseInt(IO.readln());

        if (primoSequencial.ePrimo(n)) {
            IO.println("É primo");
        } else {
            IO.println("Não é primo");
        }
    }
}

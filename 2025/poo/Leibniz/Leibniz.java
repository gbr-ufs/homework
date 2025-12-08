class Leibniz {
    public double aproximarPI(int n) {
        double resultado = 1.0;
        double step = 2.0;

        if (n == 0) {
            IO.println(resultado);
        } else {
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) {
                    resultado += 1.0 / (step + i);
                } else {
                    resultado -= 1.0 / (step + i);
                }
            }
        }

        return resultado;
    }

    public static void main(String[] args) {
        int n = 0;
        Leibniz leibniz = new Leibniz();

        n = Integer.parseInt(IO.readln());
        IO.println(leibniz.aproximarPI(n));
    }
}

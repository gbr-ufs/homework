class RaizQuadradaFormula {
    public int calcular (int n) {
        int r = 0;

        while (r * r <= n && r < n + 1) {
            r++;
        }

        // O resultado é o resultado verdadeiro + 1 por algum motivo.
        return r - 1;
    }

    public static void main(String[] args) {
        RaizQuadradaFormula raizQuadradaFormula = new RaizQuadradaFormula();
        int n = 0;

        n = Integer.parseInt(IO.readln());
        IO.println(raizQuadradaFormula.calcular(n));
    }
}

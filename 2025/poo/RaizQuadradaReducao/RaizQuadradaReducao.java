class RaizQuadradaReducao {
    public int calcular (int n) {
        int contagem = 0;
        int step = 1;

        while (n >= 0) {
            n -= step;
            step += 2;
            contagem++;
        }

        // Mesmo esquema aqui, o resultado dá um a mais.
        return contagem - 1;
    }

    public static void main(String[] args) {
        RaizQuadradaReducao raizQuadradaReducao = new RaizQuadradaReducao();
        int n = 0;

        n = Integer.parseInt(IO.readln());
        IO.println(raizQuadradaReducao.calcular(n));
    }
}

class LeitorDeNumeros {
    int[] ler(int n) {
        int[] resultado = new int[n];

        for (int i = 0; i < n; i++) {
            resultado[i] = Integer.parseInt(IO.readln());
        }

        return resultado;
    }
}

class ImpressorDePares {
    public static void main(String[] args) {
        int[] resultado;
        int n;
        LeitorDeNumeros leitorDeNumeros = new LeitorDeNumeros();

        n = Integer.parseInt(IO.readln());
        resultado = leitorDeNumeros.ler(n);

        for (int i = 0; i < n; i += 2) {
            IO.println(resultado[i]);
        }
    }
}

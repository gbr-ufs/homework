class LeitorDeNumeros {
    int[] ler(int n) {
        int[] resultado = new int[n];

        for (int i = 0; i < n; i++) {
            resultado[i] = Integer.parseInt(IO.readln());
        }

        return resultado;
    }
}

class DobradorDeArray {
    int[] dobrar(int[] numeros) {
        for (int i = 0; i < numeros.length; i++) {
            numeros[i] *= 2;
        }

        return numeros;
    }

    public static void main(String[] args) {

        int[] resultado;
        int n;
        LeitorDeNumeros leitorDeNumeros = new LeitorDeNumeros();
        DobradorDeArray dobradorDeArray = new DobradorDeArray();

        n = Integer.parseInt(IO.readln());
        resultado = leitorDeNumeros.ler(n);
        resultado = dobradorDeArray.dobrar(resultado);

        for (var numero : resultado) {
            IO.println(numero);
        }
    }
}

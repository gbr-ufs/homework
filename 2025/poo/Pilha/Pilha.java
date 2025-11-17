class Pilha {
    private int capacidade;
    public int[] valores;

    public Pilha(int capacidade) {
        this.capacidade = capacidade;
        this.valores = new int[capacidade];
    }

    public int get() {
        int resultado = 0;

        for (var valor : valores) {
            if (valor != 0) {
                resultado = valor;
                break;
            }
        }

        return resultado;
    }

    public void add(int valor) {
        for (int i = valores.length - 1; i != 0; i--) {
            if (valores[i] == 0) {
                valores[i] = valor;
                break;
            }
        }
    }

    public static void main(String[] args) {
        Pilha pilha = new Pilha(10);

        // Adicionando valores de um até cinco.
        for (int i = 1; i < 6; i++) {
            pilha.add(i);
        }

        IO.println(pilha.get());
    }
}

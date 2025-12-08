class FilaIlimitada {
    // Tamanho máximo que um array pode suportar.
    private final int CAPACIDADE = Integer.MAX_VALUE - 1999999990;
    private final int[] elementos = new int[CAPACIDADE];
    private int tamanho;
    private int inicio;
    private int fim;

    public FilaIlimitada() {
        this.tamanho = 0;
        this.inicio = 0;
        this.fim = 0;
    }

    public boolean vazia() {
        return tamanho == 0;
    }

    public int tamanho() {
        return tamanho;
    }

    public int primeiro() {
        if (tamanho > 0) {
            return elementos[inicio];
        } else {
            throw new IndexOutOfBoundsException("Pegando o primeiro de uma fila vazia");
        }
    }

    public void enfileirar(int elem) {
        elementos[fim] = elem;
        fim = (fim + 1) % CAPACIDADE;
        tamanho++;
    }

    public int desenfileirar() {
        if (tamanho > 0) {
            int primeiro = elementos[inicio];
            inicio = (inicio + 1) % CAPACIDADE;
            tamanho--;

            return primeiro;
        } else {
            throw new IndexOutOfBoundsException("Tirando de fila vazia");
        }
    }

    public static void main(String[] args) {
        FilaIlimitada filaIlimitada = new FilaIlimitada();

        IO.println(filaIlimitada.vazia());
        IO.println(filaIlimitada.tamanho());
        filaIlimitada.enfileirar(1);
        IO.println(filaIlimitada.tamanho());
        IO.println(filaIlimitada.primeiro());
        IO.println(filaIlimitada.desenfileirar());
        filaIlimitada.enfileirar(2);
        IO.println(filaIlimitada.primeiro());
    }
}

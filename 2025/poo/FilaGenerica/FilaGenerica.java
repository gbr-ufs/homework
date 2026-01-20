import java.util.ArrayList;
import java.util.List;

class FilaGenerica<E> {
    private final E[] elementos;
    private int tamanho;
    private int inicio;
    private int fim;
    private final int CAPACIDADE;

    public FilaGenerica(int capacidade) {
        CAPACIDADE = capacidade;
        tamanho = 0;
        inicio = 0;
        fim = 0;
        elementos = (E[]) new Object[CAPACIDADE];
    }

    public boolean vazia() {
        return tamanho == 0;
    }

    public boolean cheia() {
        return tamanho == CAPACIDADE;
    }

    public void enfileirar(E elem) throws ArrayIndexOutOfBoundsException {
        if (tamanho < CAPACIDADE) {
            elementos[fim] = elem;
            fim = (fim + 1) % CAPACIDADE;
            tamanho++;
        } else {
            throw new ArrayIndexOutOfBoundsException("Fila sem capacidade suficiente");
        }
    }

    public E desenfilerar() throws ArrayIndexOutOfBoundsException {
        if (tamanho > 0) {
            E primeiro = elementos[inicio];
            inicio = (inicio + 1) % CAPACIDADE;
            tamanho--;

            return primeiro;
        } else {
            throw new ArrayIndexOutOfBoundsException("Retirando de uma fila vazia");
        }
    }

    public E primeiro() throws ArrayIndexOutOfBoundsException {
        if (tamanho > 0) {
            return elementos[inicio];
        } else {
            throw new ArrayIndexOutOfBoundsException("Pegando o primeiro item de uma fila vazia");
        }
    }

    public int tamanho() {
        return tamanho;
    }

    public String toString() {
        String result = "[";

        for (int i = 0; i < CAPACIDADE; i++) {
            if (i == 0) {
                result += elementos[i];
            } else {
                result += ", " + elementos[i];
            }
        }
        result += "]";

        return  result;
    }

    static void main(String[] args) {
        FilaGenerica filaGenerica = new FilaGenerica(5);

        IO.println(filaGenerica.vazia());
        IO.println(filaGenerica.cheia());
        for (int i = 5; i > 0 ; --i) {
            filaGenerica.enfileirar(i);
        }
        IO.println(filaGenerica.cheia());
        IO.println(filaGenerica.primeiro());
        IO.println(filaGenerica.desenfilerar());
        IO.println(filaGenerica.primeiro());
        IO.println(filaGenerica.tamanho());
        IO.println(filaGenerica);
    }
}

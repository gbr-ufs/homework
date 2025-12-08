import java.util.Arrays;
import java.util.concurrent.ExecutionException;

class AssentosMaior {
    private final int QUANTIDADE = 40;
    private boolean[] posicoes = new boolean[QUANTIDADE];
    private static final int[] primeiraClasse = {1, 5, 9, 13, 17, 21, 25, 29, 33, 37};

    public int quantidade() {
        return QUANTIDADE;
    }

    public void mostrarOcupacao() {
        for (int i = 0; i < QUANTIDADE; i++) {
            IO.print(i + 1);
            if (posicoes[i]) {
                IO.print("X");
            }
            if (i % 10 == 0) {
                IO.println();
            } else {
                IO.print(" ");
            }
        }
        IO.println();
    }

    public void ocuparAssento(int posicao) {
        posicoes[posicao - 1] = !posicoes[posicao - 1];
    }

    // "É primeira classe?".
    public boolean ePrimeiraClasse(int posicao) {
        boolean resultado = false;

        for (var entrada : primeiraClasse) {
            if (posicao == entrada) {
                resultado = true;
            }
        }

        return resultado;
    }

    public boolean estaOcupado(int posicao) {
        return posicoes[posicao - 1];
    }

    public boolean estaLotado() {
        boolean resultado = true;

        for (var entrada : posicoes) {
            resultado = entrada;
        }

        return resultado;
    }

    public void mensagemEscolhaDeClasse() {
        IO.println("Escolha a classe na qual você irá viajar: ");
        IO.println("[0] Primeira classe");
        IO.println("[1] Classe Econômica");
    }

    public void mensagemDeAssento() {
        IO.println("Deseja escolher o assento ou deixar o sistema escolher pra você?");
        IO.println("[0] Escolher");
        IO.println("[1] Deixar o sistema");
    }

    public int primeiroVago() {
        int resultado = 0;

        for (int i = 0; i < QUANTIDADE; i++) {
            if (!posicoes[i]) {
                resultado = i +1;
                break;
            }
        }

        return resultado;
    }

    public static void main(String[] args) throws Exception {
        final int PRIMEIRA_CLASSE = 0;
        // 0 é primeira classe, 1 é classe econômica.
        int decisaoClasse = 0;
        // 0 serve para deixar o usuário escolher por conta própria, 1 deixa
        // o sistema escolher.
        int decisaoPosicao = 0;
        int posicao = 0;
        AssentosMaior assentosMaior = new AssentosMaior();

        if (assentosMaior.estaLotado()) {
            IO.println("O avião está lotado, que azar!");
            System.exit(0);
        }

        assentosMaior.mostrarOcupacao();

        assentosMaior.mensagemEscolhaDeClasse();
        decisaoClasse = Integer.parseInt(IO.readln());

        if (decisaoClasse < 0 || decisaoClasse > 1) {
            throw new Exception("Valor inválido");
        }

        assentosMaior.mensagemDeAssento();

        if (decisaoPosicao < 0 || decisaoPosicao > 1) {
            throw new Exception("Valor inválido");
        }

        if (decisaoPosicao == 0) {
            IO.println("Escolha a posição:");
            posicao = Integer.parseInt(IO.readln());
        } else {
            posicao = assentosMaior.primeiroVago();
        }

        if (assentosMaior.estaOcupado(posicao)) {
            throw new Exception("Assento ocupado");
        }

        if (posicao > assentosMaior.quantidade()) {
            throw new ArrayIndexOutOfBoundsException("Posição maior que a esperada");
        }

        if (decisaoClasse == PRIMEIRA_CLASSE && !assentosMaior.ePrimeiraClasse(posicao)) {
            throw new Exception("Assento não é de primeira classe");
        }

        if (decisaoClasse != PRIMEIRA_CLASSE && assentosMaior.ePrimeiraClasse(posicao)) {
            throw new Exception("Assento é de primeira classe");
        }

        assentosMaior.ocuparAssento(posicao);
        assentosMaior.mostrarOcupacao();
    }
}

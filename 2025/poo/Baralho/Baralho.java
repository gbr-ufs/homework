import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Baralho {
    public static List<Carta> criarBaralho() {
        List<Carta> baralho = new ArrayList<>();

        for (Naipe naipe : Naipe.values()) {
            for (Valor valor : Valor.values()) {
                Carta carta = new Carta(valor, naipe);

                baralho.add(carta);
            }
        }

        return baralho;
    }

    public static List<List<Carta>> distribuirCartas(List<Carta> baralho, int m, int n) {
        if (m * n > baralho.size()) {
            throw new IllegalArgumentException("Não há cartas suficientes no baralho");
        }

        Collections.shuffle(baralho);

        List<List<Carta>> maosDosJogadores = new ArrayList<>();

        Comparator<Carta> comparadorPorNaipe = Comparator.comparing(Carta::getNaipe).thenComparing(Carta::getValor);

        for (int i = 0; i < m; i++) {
            List<Carta> maoAtual = new ArrayList<>();

            for (int j = 0; j < n; j++){
                maoAtual.add(baralho.remove(0));
            }

            Collections.sort(maoAtual, comparadorPorNaipe);

            maosDosJogadores.add(maoAtual);
        }

        return maosDosJogadores;
    }

    public static void main(String[] args) {
        List<Carta> baralho = criarBaralho();

        IO.println("Total de cartas: " + baralho.size());
        IO.println("Cartas: " + baralho);

        List<List<Carta>> jogo = distribuirCartas(baralho, 4, 5);

        for (int i = 0; i < jogo.size(); i++){
            IO.println("Jogador " + (i + 1) + ": " + jogo.get(i));
        }

        IO.println("Cartas restantes: " + baralho.size());
    }
}

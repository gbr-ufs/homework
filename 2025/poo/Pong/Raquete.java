/**
 * Classe para as raquetes no jogo Pong.
 * @author Gabriel Santos de Souza.
 * @version 1.0.0
 */
public class Raquete {
    private double y, velocidade;

    public Raquete() {
        this.y = 0.00;
    }

    public Raquete(double y) {
        this.y = y;
    }

    public void acelerar(int tempo) {
        if (tempo != 0) {
            velocidade *= tempo;
        }
    }

    public void mover(double y) {
        this.y += y;
    }
}

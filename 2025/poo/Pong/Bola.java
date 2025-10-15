/**
 * Classe para a bola no jogo Pong.
 * @author Gabriel Santos de Souza.
 * @version 1.0.0
 */
public class Bola {
    private double x, y, z, velocidade;

    public Bola() {
        this.x = 0.00;
        this.y = 0.00;
        this.z = 0.00;
        this.velocidade = 0.00;
    }

    public Bola(double x, double y, double z, double velocidade) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.velocidade = velocidade;
    }

    public void acelerar(int tempo) {
        if (tempo != 0) {
            velocidade *= tempo;
        }
    }

    public void moverHorizontal(double x) {
        this.x += x;
    }

    public void moverVertical(double y) {
        this.y += y;
    }

    public void moverDiagonal(double z) {
        this.z += z;
    }
}

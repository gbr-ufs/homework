public class Ponto2D {
    private Double x;
    private Double y;

    public Ponto2D(Double x, Double y) {
        this.x = x;
        this.y = y;
    }

    public Double getX() {
        return x;
    }

    public void setX(Double x) {
        this.x = x;
    }

    public Double getY() {
        return y;
    }

    public void setY(Double y) {
        this.y = y;
    }

    public Double distanciaAoOrigem() {
        return Math.hypot(x, y);
    }

    public Double distancia(Ponto2D ponto2d) {
        Double deltaX = (ponto2d.x - x);
        Double deltaY = (ponto2d.y - y);

        return Math.hypot(deltaX, deltaY);
    }
}

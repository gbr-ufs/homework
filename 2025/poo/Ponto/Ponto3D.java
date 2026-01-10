public class Ponto3D extends Ponto2D {
    protected Double z;

    public Ponto3D(Double x, Double y, Double z) {
        super(x, y);
        this.z = z;
    }

    public Double getZ() {
        return z;
    }

    public void setZ(Double z) {
        this.z = z;
    }

    public Double distanciaAoOrigem() {
        // Temos que usar os getters aqui porque os campos são privados.
        Double somaDosQuadrados = Math.pow(getX(), 2.0) + Math.pow(getY(), 2.0) + Math.pow(z, 2.0);

        return Math.sqrt(somaDosQuadrados);
    }

    public Double distancia(Ponto3D ponto3d) {
        Double deltaX = Math.pow((ponto3d.x - getX()), 2.0); // O mesmo.
        Double deltaY = Math.pow((ponto3d.y - getY()), 2.0); // O mesmo.
        Double deltaZ = Math.pow((ponto3d.z - z), 2.0);

        return Math.sqrt(deltaX + deltaY + deltaZ);
    }
}

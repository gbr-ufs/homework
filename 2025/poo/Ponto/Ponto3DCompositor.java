public class Ponto3DCompositor {
    private Double x;
    private Double y;
    private Double z;

    public Ponto3DCompositor(Ponto2D ponto2d, Double z) {
        this.x = ponto2d.x;
        this.y = ponto2d.y;
        this.z = z;
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

    public Double getZ() {
        return z;
    }

    public void setZ(Double z) {
        this.z = z;
    }

    public Double distanciaAoOrigem() {
        Double somaDosQuadrados = Math.pow(x, 2.0) + Math.pow(y, 2.0) + Math.pow(z, 2.0);

        return Math.sqrt(somaDosQuadrados);
    }

    public Double distancia(Ponto3D ponto3d) {
        Double resultadoX = Math.pow((ponto3d.x - x), 2.0);
        Double resultadoY = Math.pow((ponto3d.y - y), 2.0);
        Double resultadoZ = Math.pow((ponto3d.z - z), 2.0);

        return Math.sqrt(resultadoX + resultadoY + resultadoZ);
    }
}

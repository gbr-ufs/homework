public class Circulo extends FiguraBidimensional {
    private final Double raio;

    public Circulo(String cor, Double raio) {
        super(cor);
        this.raio = raio;
    }

    @Override
    public Double getArea() {
        return Math.PI * Math.pow(raio, 2.0);
    }

    @Override
    protected String getMedidas() {
        return "Raio: " + raio + System.lineSeparator();
    }
}

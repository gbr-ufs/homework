public class Esfera extends FiguraTridimensional {
    private final Double raio;

    public Esfera(String cor, Double raio) {
        super(cor);
        this.raio = raio;
    }

    public Double getRaio() {
        return raio;
    }

    @Override
    public Double getArea() {
        return 4.0 * Math.PI * Math.pow(raio, 3.0);
    }

    @Override
    public Double getVolume() {
        return (4.0 / 3.0) * Math.PI * Math.pow(raio, 3.0);
    }

    @Override
    protected String getMedidas() {
        return "Raio: " + raio + System.lineSeparator();
    }
}

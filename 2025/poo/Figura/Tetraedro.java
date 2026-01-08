public class Tetraedro extends FiguraTridimensional {
    private final Double aresta;

    public Tetraedro(String cor, Double aresta) {
        super(cor);
        this.aresta = aresta;
    }

    public Double getArestra() {
        return aresta;
    }

    @Override
    public Double getArea() {
        return Math.pow(aresta, 2.0) * Math.sqrt(3.0);
    }

    @Override
    public Double getVolume() {
        Double numerador = Math.pow(aresta, 3.0) * Math.sqrt(2.0);

        return numerador / 12.0;
    }

    @Override
    protected String getMedidas() {
        return "Aresta: "+ aresta + System.lineSeparator();
    }
}

// StringBuilders são uma das melhores ferramentas para concatenação.
// Veja: https://redfin.engineering/java-string-concatenation-which-way-is-best-8f590a7d22a8

public class Retangulo extends FiguraBidimensional {
    private final Double base;
    private final Double altura;

    public Retangulo(String cor, Double base, Double altura) {
        super(cor);
        this.base = base;
        this.altura = altura;
    }

    public Double getBase() {
        return base;
    }

    public Double getAltura() {
        return altura;
    }

    @Override
    public Double getArea() {
        return base * altura;
    }

    @Override
    protected String getMedidas() {
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder
                .append("Base: ")
                .append(base)
                .append(System.lineSeparator())
                .append("Altura: ")
                .append(altura)
                .append(System.lineSeparator());

        return stringBuilder.toString();
    }
}

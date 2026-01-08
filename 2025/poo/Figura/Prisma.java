// StringBuilders são uma das melhores ferramentas para concatenação.
// Veja: https://redfin.engineering/java-string-concatenation-which-way-is-best-8f590a7d22a8

class Prisma extends FiguraTridimensional {
    private final Double base;
    private final Double altura;
    private final Double profundidade;

    public Prisma(String cor, Double base, Double altura, Double profundidade) {
        super(cor);
        this.base = base;
        this.altura = altura;
        this.profundidade = profundidade;
    }

    public Double getBase() {
        return base;
    }

    public Double getAltura() {
        return altura;
    }

    public Double getProfundidade() {
        return profundidade;
    }

    @Override
    public Double getArea() {
        Double baseVezesAltura = base * altura;
        Double alturaVezesProfundidade = altura * profundidade;
        Double baseVezesProfundidade = base * profundidade;

        return 2.0 * (baseVezesAltura + alturaVezesProfundidade + baseVezesProfundidade);
    }

    @Override
    public Double getVolume() {
        return base * altura * profundidade;
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
                .append(System.lineSeparator())
                .append("Profundidade: ")
                .append(profundidade)
                .append(System.lineSeparator());

        return stringBuilder.toString();
    }
}

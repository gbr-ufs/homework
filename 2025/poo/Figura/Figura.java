// StringBuilders são uma das melhores ferramentas para concatenação.
// Veja: https://redfin.engineering/java-string-concatenation-which-way-is-best-8f590a7d22a8

public abstract class Figura implements AreaCalculavel {
    private final String cor;

    public Figura(String cor) {
        this.cor = cor;
    }

    public String getCor() {
        return cor;
    }

    // protected é parecido com private, mas permite o uso do método
    // em classes derivadas.
    protected abstract String getMedidas();

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder
                .append(getClass().getSimpleName())
                .append(System.lineSeparator())
                .append("Cor: ")
                .append(cor)
                .append(System.lineSeparator())
                .append(getMedidas())
                .append("Área: ")
                .append(getArea())
                .append(System.lineSeparator());

        return stringBuilder.toString();
    }
}

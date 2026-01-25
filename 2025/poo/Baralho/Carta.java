public class Carta implements Comparable<Carta>{
    private final Valor valor;
    private final Naipe naipe;

    public Carta(Valor valor, Naipe naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }

    public Valor getValor() {
        return valor;
    }

    public Naipe getNaipe() {
        return naipe;
    }

    @Override
    public String toString(){
        return valor + " de " + naipe;
    }

    @Override
    public int compareTo(Carta outra) {
        return this.valor.compareTo(outra.valor);
    }
}

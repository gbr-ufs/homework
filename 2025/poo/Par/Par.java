class Par<E extends Comparable> implements Comparable<Par> {
    private E primeiro;
    private E segundo;

    public Par(E primeiro, E segundo) {
        this.primeiro = primeiro;
        this.segundo = segundo;
    }

    public E getPrimeiro() {
        return primeiro;
    }

    public E getSegundo() {
        return segundo;
    }

    @Override
    public int compareTo(Par p) {
        int comparacaoPrimeiro = this.getPrimeiro().compareTo(p.getPrimeiro());
        int comparacaoSegundo = this.getSegundo().compareTo(p.getSegundo());

        if (comparacaoPrimeiro == 0) {
            return comparacaoSegundo;
        }

        return comparacaoPrimeiro;
    }

    public static <E> void main(String[] args) {
        Par<Double> doubles1 = new Par<Double>(1.2, 2.5);
        Par<Double> doubles2 = new Par<Double>(2.4, 0.5);
        Par<Integer> integers1 = new Par<Integer>(1, 2);
        Par<Integer> integers2 = new Par<Integer>(0, 4);
        Par<String> strings1 = new Par<String>("lixo", "gambá");
        Par<String> strings2 = new Par<String>("lixo", "gambá");
        Par[] pares1 = {doubles1, integers1, strings1};

        for (var par : pares1) {
            IO.println(par.getPrimeiro());
        }
        for (var par : pares1) {
            IO.println(par.getSegundo());
        }
        IO.println(doubles1.compareTo(doubles2));
        IO.println(integers1.compareTo(integers2));
        IO.println(strings1.compareTo(strings2));
    }
}

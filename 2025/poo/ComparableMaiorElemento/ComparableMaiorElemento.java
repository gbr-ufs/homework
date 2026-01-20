import java.util.HashSet;

class ComparableMaiorElemento {
    public static Comparable[] bubbleSort(Comparable[] comparaveis) {
        Comparable[] comparaveisCopia = comparaveis.clone();

        for (int i = comparaveisCopia.length - 1; i > 0; i--) {
            for (int j = 0; j < comparaveisCopia.length - 1; j++) {
                if (comparaveisCopia[j].compareTo(comparaveisCopia[j + 1]) > 0) {
                    Comparable tmp = comparaveisCopia[j];
                    comparaveisCopia[j] = comparaveisCopia[i];
                    comparaveisCopia[i] = tmp;
                }
            }
        }

        return comparaveisCopia;
    }
    public static Comparable maiorElemento(Comparable[] comparaveis) {
        return ComparableMaiorElemento.bubbleSort(comparaveis)[comparaveis.length - 1];
    }
    public static void main(String[] args) {
        Comparable boolean1[] = {true, false, true, true, false};
        Comparable double1[] = {1.2, 2.5, 3.26, 7.21, 5.21};
        Comparable integer[] = {1, 2, 3, 7, 5};
        Comparable string[] = {"lixo", "gambá", "Amazônia", "Sabiá", "Lustre"};
        Comparable ascendente[] = {"a", "b", "c", "d", "e"};
        Comparable[] comparaveis[] = {boolean1, double1, integer, string, ascendente};

        for (Comparable[] comparavel : comparaveis) {
            IO.println(ComparableMaiorElemento.maiorElemento(comparavel));
        }
    }
}

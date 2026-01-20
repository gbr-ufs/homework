import java.lang.Comparable;


class ComparadorAscendente {
    public static boolean compararAscendente(Comparable[] comparaveis) {
        for (int i = 0; i < comparaveis.length - 1; i++) {
            if (comparaveis[i].compareTo(comparaveis[i + 1]) > 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Comparable boolean1[] = {true, false, true, true, false};
        Comparable double1[] = {1.2, 2.5, 3.26, 7.21, 5.21};
        Comparable integer[] = {1, 2, 3, 7, 5};
        Comparable string[] = {"lixo", "gambá", "Amazônia", "Sabiá", "Lustre"};
        Comparable ascendente[] = {"a", "b", "c", "d", "e"};
        Comparable[] comparaveis[] = {boolean1, double1, integer, string, ascendente};

        for (Comparable[] comparavel : comparaveis) {
            IO.println(ComparadorAscendente.compararAscendente(comparavel));
        }
    }
}

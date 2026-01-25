import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class SequenciaDeNomes {
    public static List<String> sequenciaDeNomes(String[] nomes) {
        List<String> list = new ArrayList<>();

        for (var nome : nomes) {
            list.add(nome);
        }

        return list;
    }

    public static void semDuplicados(String[] nomes) {
        Set<String> set = new LinkedHashSet<>();

        for (var nome : nomes) {
            if (!set.add(nome)) {
                IO.println("Nome duplicado: " + nome);
            }
        }

        IO.println(set);
    }

    public static int diferenca(String[] primeira, String[] segunda) {
        int contagem = 0;

        for (var primeiro : primeira) {
            boolean visto = false;

            for (var segundo : segunda) {
                if (primeiro.equals(segundo)) {
                    visto = true;
                    break;
                }
            }

            if (!visto) {
                contagem++;
            }
        }

        return contagem;
    }

    public static void duplicadosComNumeros(String[] nomes) {
        Map<String, Integer> map = new HashMap<>();

        for (var nome : nomes) {
            map.put(nome, map.getOrDefault(nome, 0) + 1);
        }

        IO.println(map);
    }

    public static void main(String[] args) {
        List<String> list = sequenciaDeNomes(args);
        int metade = args.length / 2;
        String[] primeiraMetade = new String[metade];
        String[] segundaMetade = new String[args.length - metade];

        IO.println(list);

        for (int i = 0; i < metade; i++) {
            primeiraMetade[i] = args[i];
        }

        for (int j = 0; j < args.length / 2; j++) {
            segundaMetade[j] = args[metade + j];
        }

        semDuplicados(args);

        IO.println(diferenca(primeiraMetade, segundaMetade));

        duplicadosComNumeros(args);
    }
}

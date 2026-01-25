import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Eleicao {
    public static void main(String[] args) {
        Candidato foo = new Candidato(97645323567L);
        Candidato bar = new Candidato(89789709809L);
        Candidato baz = new Candidato(89867865645L);
        Candidato quux = new Candidato(76567734562L);
        List<Candidato> candidatos = new ArrayList<Candidato>();

        candidatos.add(foo);
        candidatos.add(bar);
        candidatos.add(baz);
        candidatos.add(quux);

        Collections.sort(candidatos);

        foo.serVotado(bar);
        foo.serVotado(baz);

        bar.serVotado(foo);

        for (var candidato : candidatos) {
            candidato.imprimirEleitores();
        }

        for (var candidato : candidatos) {
            float porcentagem = (float) candidato.getVotos() / candidatos.size() * 100;

            StringBuilder stringBuilder = new StringBuilder();

            stringBuilder
                    .append(candidato.getCPF())
                    .append(" ")
                    .append(String.format("%.2f%%", porcentagem));

            IO.println(stringBuilder);
        }
    }
}

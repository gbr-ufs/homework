import java.util.LinkedHashSet;
import java.util.Set;

public class Candidato implements Comparable<Candidato> {
    private final Long cpf;
    private Set<Long> eleitores = new LinkedHashSet<>();
    private Integer votos = 0;
    private boolean votou = false;

    public Candidato(long cpf) {
        this.cpf = cpf;
    }

    public long getCPF() {
        return cpf;
    }

    public Integer getVotos() {
        return votos;
    }

    public void imprimirEleitores() {

        if (eleitores.isEmpty()) {
            IO.println(cpf + " não teve eleitores.");
            return;
        }

        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder
                .append("Os votos para ")
                .append(cpf)
                .append(" foram de:")
                .append(System.lineSeparator());

        for (var eleitor : eleitores) {
            stringBuilder
                    .append(eleitor)
                    .append(System.lineSeparator());
        }

        IO.print(stringBuilder);
    }

    public void serVotado(Candidato eleitor) {

        if (eleitor.votou) {
            throw new IllegalArgumentException("Eleitor já votou");
        }

        eleitores.add(eleitor.getCPF());
        votos++;
        eleitor.votou = true;
    }

    @Override
    public int compareTo(Candidato outro) {
        return this.votos.compareTo(outro.votos);
    }
}

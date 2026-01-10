import java.time.LocalDate;
import java.util.ArrayList;

public abstract class Docente extends Funcionario implements SalarioCalculavel {
    private ArrayList<String> disciplinas;

    public Docente(String nome, String cpf, LocalDate dataDeNascimento, ArrayList<String> disciplinas) {
        super(nome, cpf, dataDeNascimento);
        this.disciplinas = disciplinas;
    }

    public ArrayList<String> getDisciplinas() {
        return disciplinas;
    }

    public void retirarDisciplina(String disciplina) {
        disciplinas.remove(disciplina);
    }

    public void adicionarDisciplina(String disciplina) {
        disciplinas.add(disciplina);
    }

    public abstract Double calcularPagamento();
}

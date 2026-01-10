import java.time.LocalDate;
import java.util.ArrayList;

public abstract class DocenteSubstituto extends Docente {
    public DocenteSubstituto(String nome, String cpf, LocalDate dataDeNascimento, ArrayList<String> disciplina) {
        super(nome, cpf, dataDeNascimento, disciplina);
    }
}

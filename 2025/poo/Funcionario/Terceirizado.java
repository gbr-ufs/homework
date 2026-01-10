import java.time.LocalDate;
import java.util.ArrayList;

public class Terceirizado extends Funcionario {
    private ArrayList<String> dependencias;

    public Terceirizado(String nome, String cpf, LocalDate dataDeNascimento, ArrayList<String> dependencias) {
        super(nome, cpf, dataDeNascimento);
        this.dependencias = dependencias;
    }

    public ArrayList<String> getDependencias() {
        return dependencias;
    }

    public void retirarDependencia(String dependencia) {
        dependencias.remove(dependencia);
    }

    public void adicionarDependencia(String dependencia) {
        dependencias.add(dependencia);
    }
}

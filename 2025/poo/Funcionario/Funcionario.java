import java.time.LocalDate;
import java.time.Period;

public abstract class Funcionario {
    private String nome;
    private final String cpf;
    private final LocalDate dataDeNascimento;

    public Funcionario(String nome, String cpf, LocalDate dataDeNascimento) {
        this.nome = nome;
        this.cpf = cpf;
        this.dataDeNascimento = dataDeNascimento;
    }

    public String getNome() {
        return nome;
    }

    protected void setNome(String nome) {
        this.nome = nome;
    }

    public String getCPF() {
        return cpf;
    }

    public LocalDate getDataDeNascimento() {
        return dataDeNascimento;
    }

    public Period idade() {
        return Period.between(dataDeNascimento, LocalDate.now());
    }
}

import java.time.LocalDate;

public class Administrativo extends Funcionario {
    private static Double SALARIO = 10534.1;

    public Administrativo(String nome, String cpf, LocalDate dataDeNascimento) {
        super(nome, cpf, dataDeNascimento);
    }

    public Double calcularPagamento() {
        return SALARIO;
    }
}

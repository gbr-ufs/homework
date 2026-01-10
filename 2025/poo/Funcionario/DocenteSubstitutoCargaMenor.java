import java.time.LocalDate;
import java.util.ArrayList;

// Veja: https://prodep.ufba.br/sites/prodep.ufba.br/files/4Tabela%20Remunera%C3%A7%C3%A3o%20MS_Titular_Livre_2025.pdf

public class DocenteSubstitutoCargaMenor extends DocenteSubstituto {
    private static Double SALARIO = 3090.43;

    public DocenteSubstitutoCargaMenor(String nome, String cpf, LocalDate dataDeNascimento, ArrayList<String> disciplina) {
        super(nome, cpf, dataDeNascimento, disciplina);
    }

    public Double calcularPagamento() {
        return SALARIO;
    }
}

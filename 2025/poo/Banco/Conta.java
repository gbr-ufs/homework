/**
 * Classe para contas bancárias.
 * @author Gabriel Santos de Souza.
 * @version 1.0.0
 */
public class Conta {
    private String cpf;
    private Double saldo = 0.0;

    public Conta(String cpf) {
        this.cpf = cpf;
    }

    public void depositar(Double valor) {
        if (valor < 0.0) {
            throw new ArithmeticException("Valor inesperado - Deve ser positivo");
        }

        saldo += valor;
    }

    public void sacar(Double valor) {
        if (valor < 0.0) {
            throw new ArithmeticException("Valor inesperado - Deve ser positivo");
        }

        if (valor > saldo) {
            throw new ArithmeticException("Valor inesperado - Maior que o saldo atual");
        }

        saldo -= valor;
    }

    /**
     * Mostra o saldo da conta.
     * @return O saldo atual da conta.
     */
    public Double verSaldo() {
        return saldo;
    }
}

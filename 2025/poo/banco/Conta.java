/**
 * Classe para contas bancárias.
 * @author Gabriel Santos de Souza.
 * @version 1.0.0
 */
public class Conta {
    private String cpf;
    private Double saldo = 0.0;

    public Conta(String nome, String cpf) {
        this.cpf = cpf;
    }

    public void depositar(Double valor) {
        saldo += valor;
    }

    public void sacar(Double valor) {
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

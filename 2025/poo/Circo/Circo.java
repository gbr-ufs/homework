import java.io.Console;

class Ingresso {
    private int idade = 0;
    private double preco = 0.00;

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }
}

public class Circo {
    public static void main(String[] args) throws Exception {
        // Menores de 18 anos.
        int limiteMenor = 18;
        // A partir dos 60 anos.
        int inicioMaior = 60;
        // Para pessoas de menor (até 18) e maior (a partir dos 50) idade.
        double descontoMaior = 0.5;
        // Para o restante da população.
        double descontoMenor = 0.1;
        String mensagem = "Preço descontado: R$";
        Ingresso ingresso = new Ingresso();
        Console console = System.console();

        ingresso.setIdade(Integer.parseInt(console.readLine("Qual a sua idade? ")));
        ingresso.setPreco(Double.parseDouble(console.readLine("Qual o preço do seu ingresso? R$")));

        // Idade negativa, preço negativo.
        if (ingresso.getIdade() < 0 || ingresso.getPreco() < 0) {
            throw new ArithmeticException("Idade ou preço inesperado, devem ser maiores ou iguais a zero");
        }

        if (ingresso.getIdade() < limiteMenor || ingresso.getIdade() >= inicioMaior) {
            double desconto = ingresso.getPreco() * descontoMaior;
            System.out.println(mensagem + (ingresso.getPreco() - desconto));
        } else {
            double desconto = ingresso.getPreco() * descontoMenor;
            System.out.println(mensagem + (ingresso.getPreco() - desconto));
        }

    }
}

public class Vinho {
    public static void main(String[] args) throws Exception {
        int quantidade;
        double valor, valorTotal;
        String mensagemValor = "Valor: R$";
        String mensagemValorTotal = "Valor total: R$";

        quantidade = Integer.parseInt(IO.readln("Quantos vinhos você comprou? "));
        valor = Double.parseDouble(IO.readln("Qual o valor do vinho? "));

        if (quantidade < 0 || valor < 0.0) {
            throw new ArithmeticException("Quantidade ou valor inesperado, deve ser maior ou igual a zero");
        }

        if (quantidade == 0) {
            valor = 0.00;
            valorTotal = valor;
            System.out.println(mensagemValor + valor);
            System.out.println(mensagemValorTotal + valorTotal);
        } else {
            quantidade -= quantidade / 3;
            valorTotal = valor * quantidade;
            System.out.println(mensagemValor + valor);
            System.out.println(mensagemValorTotal + valorTotal);
        }
    }
}

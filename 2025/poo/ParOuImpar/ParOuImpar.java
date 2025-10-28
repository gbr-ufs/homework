public class ParOuImpar {
    public static void main(String[] args) {
        int numero;

        numero = Integer.parseInt(IO.readln("Digite um número: "));

        if (numero % 2 == 0) {
            System.out.println("É par");
        } else {
            System.out.println("É ímpar");
        }
    }
}

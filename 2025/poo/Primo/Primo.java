class QuantosDivisores {
    public int contar(int n) {
        int contagem = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                contagem++;
            }
        }

        return contagem;
    }
}

class Primo {
    public static void main(String[] args) {
        QuantosDivisores quantosDivisores = new QuantosDivisores();
        int n = 0;

        n = Integer.parseInt(IO.readln());

        if (quantosDivisores.contar(n) == 2) {
            IO.println("É primo");
        } else {
            IO.println("Não é primo");
        }
    }
}

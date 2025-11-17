public class MEC {
    private static boolean intervalo(float inicio, float valor, float fim) {
        if (valor <= inicio && valor >= fim) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        // Entrada.
        int livros;
        int alunos;
        // Saída.
        float escalaLivroAluno;
        float conceitoA = 1f / 8f;
        float conceitoBInicio = 1f / 9f, conceitoBFim = 1f / 12f;
        float conceitoCInicio = 1f / 13f, conceitoCFim = 1f / 18f;

        livros = Integer.parseInt(IO.readln("Digite a quantidade de livros: "));
        alunos = Integer.parseInt(IO.readln("Digite a quantidade de alunos: "));
        escalaLivroAluno = (float)livros / (float)alunos;

        if (escalaLivroAluno >= conceitoA) {
            IO.println("A");
        } else if (intervalo(conceitoBInicio, escalaLivroAluno, conceitoBFim)) {
            IO.println("B");
        } else if (intervalo(conceitoCInicio, escalaLivroAluno, conceitoCFim)) {
            IO.println("C");
        } else {
            IO.println("D");
        }
    }
}

public class SaoJoao {
    public static void main(String[] args) {
        int dia;
        int diaSaoJoao = 24;
        int mes;
        int mesSaoJoao = 6;
        int diasNoAno = 365;

        dia = Integer.parseInt(IO.readln("Digite o dia: "));
        mes = Integer.parseInt(IO.readln("Digite o mês: "));

        if (mes > mesSaoJoao || mes == mesSaoJoao && dia > 24) {
            IO.println("São João já passou!");
        } else {
            int diasAte = diaSaoJoao - dia;
            int mesesAte = mesSaoJoao - mes;

            IO.println("Faltam " + diasAte + " dia(s) e " + mesesAte + " mês (meses) para o próximo São João.");
        }
    }
}

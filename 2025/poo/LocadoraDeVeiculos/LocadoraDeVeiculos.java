public class LocadoraDeVeiculos {
    public static void main(String[] args) {
        // Entrada.
        int dias;
        int quilometragem;
        // Saída.
        double valorPago = 90.0;
        double limiteDiario = 100.0;

        dias = Integer.parseInt(IO.readln("Digite o número de dias: "));
        quilometragem = Integer.parseInt(IO.readln("Digite a quantidade de quilômetros: "));
        valorPago *= dias;
        limiteDiario *= dias;

        if (quilometragem > limiteDiario) {
            valorPago += (quilometragem - limiteDiario) * 12.0;
        }

        IO.println(String.format("%.2f", valorPago));
    }
}

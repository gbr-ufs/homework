/**
 * Relógio implementado em código.
 * @author Gabriel Santos de Souza
 * @version 1.0.0
 */
public class RelogioDigital {
    private int horas = 0, minutos = 0, segundos = 0;
    
    // Adiciona o zero precedente caso o número seja menor que zero.
    private String acrescentarZero(int numero) {
        if (numero < 10) {
            return "0" + numero;
        } else {
            // Conversão para String.
            return numero + "";
        }
    }

    // Faz o tempo avançar.
    public void tick() {
        /*
         * Tentei fazer um método privado que faz algo parecido com isso aqui,
         * mas não funcionou.
         */
        if (segundos < 60) {
            segundos++;
        } else {
            segundos = 0;
            if (minutos < 60) {
                minutos++;
            } else {
                minutos = 0;
                horas++;
            }
        }

        if (horas > 23) {
            horas = 0;
        }
    }

    /**
     * Mostra a hora atual no formato "hora:minuto".
     * @return A hora atual registrada no relógio.
     */
    public String mostrarHora() {
        return acrescentarZero(horas) + ":" + acrescentarZero(minutos) +
               ":" + acrescentarZero(segundos);
    }

    public void alarme(int horas, int minutos, int segundos) {
        boolean horasIguais = this.horas == horas;
        boolean minutosIguais = this.minutos == minutos;
        boolean segundosIguais = this.segundos == segundos;

        if (horasIguais && minutosIguais && segundosIguais) {
            System.out.println("Alarme!!!!!!!!!");
        }
    }
}

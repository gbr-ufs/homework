/**
 * Classe para interruptores paralelos, aqueles ligados a uma só lâmpada.
 * @author Gabriel Santos de Souza.
 * @version 1.0.0
 */
public class InterruptoresParalelos {
    private boolean estaLigado1 = false, estaLigado2 = false;
    
    public void interagirPrimeiro() {
        estaLigado1 = !estaLigado1;
    }

    public void interagirSegundo() {
        estaLigado2 = !estaLigado2;
    }
}

class Candidato {
    private static int numero = 1;
    private String nome;
    private int numeroPessoal;
    private int votos = 0;

    public Candidato(String nome) {
        this.nome = nome;
        this.numeroPessoal = numero++;
        IO.println(numeroPessoal);
    }

    public int numeroPessoal() {
        return numeroPessoal;
    }

    public void serVotado() {
        votos++;
    }

    public int votos() {
        return votos;
    }

    public String nome() {
        return nome;
    }
}

class RegistroCandidatos {
    Candidato[] registro;
    private static int indice = 0;
    private int limite;

    public RegistroCandidatos(int limite) {
        this.limite = limite;
        registro = new Candidato[this.limite];
    }

    public void cadastrar(String nome) {
        registro[indice++] = new Candidato(nome);
    }

    public Candidato[] elementos() {
        return registro;
    }

    public int quantidadeDeCandidatos() {
        return limite;
    }
}

class UrnaEleitoral {
    RegistroCandidatos registro;
    private Candidato[] candidatos;
    private int votosEmBranco = 0;
    private int votosNulos = 0;

    public UrnaEleitoral(RegistroCandidatos registro) {
        this.registro = registro;
        candidatos = registro.elementos();
    }

    public void abrirVotacao() {
        IO.println("Votação aberta!");
    }

    // Java não possui destrutores. A minha ideia era de fazer o objeto
    // "se apagar" com este método.
    public void fecharVotacao() {
        IO.println("Votação fechada!");
    }

    public void realizarVotacao(int numeroCandidato) {
        if (numeroCandidato == 0) {
            votosEmBranco++;
        } else {
            boolean nulo = true;
            for (int i = 0; i < registro.quantidadeDeCandidatos(); i++) {
                Candidato candidato = candidatos[i];
                if (candidato.numeroPessoal() == numeroCandidato) {
                    candidato.serVotado();
                    nulo = false;
                }
            }
            if (nulo == true) {
                votosNulos++;
            }
        }
    }

    private String determinarVencedor() {
        Candidato candidatoVencedor = candidatos[0];
        int votosDoVencedor = candidatoVencedor.votos();

        for (int i = 0; i < registro.quantidadeDeCandidatos(); i++) {
            Candidato candidatoAtual = candidatos[i];
            int candidatoAtualVotos = candidatoAtual.votos();

            if (candidatoAtualVotos > votosDoVencedor) {
                candidatoVencedor = candidatoAtual;
            }
        }

        return candidatoVencedor.nome();
    }

    public void apurarResultados() {
        String vencedor = determinarVencedor();

        IO.println("Vencedor: " + vencedor);

        for (var candidato : candidatos) {
            IO.println(candidato.nome() + ": " + candidato.votos());
        }

        IO.println("Votos em branco: " + votosEmBranco);
        IO.println("Votos nulos: " + votosNulos);
    }
}

class SistemaDeVotacao {
    public static void main(String[] args) {
        int limite = 5;
        RegistroCandidatos registroCandidatos = new RegistroCandidatos(limite);
        for (int i = 0; i < limite; i++) {
            registroCandidatos.cadastrar(IO.readln("Insira o nome do candidato: "));
        }
        UrnaEleitoral urnaEleitoral = new UrnaEleitoral(registroCandidatos);

        urnaEleitoral.abrirVotacao();
        urnaEleitoral.realizarVotacao(1); // Voto no primeiro.
        urnaEleitoral.realizarVotacao(1); // Voto no primeiro.
        urnaEleitoral.realizarVotacao(1); // Voto no primeiro.
        urnaEleitoral.realizarVotacao(5); // Voto no quinto.
        urnaEleitoral.realizarVotacao(20); // Voto nulo.
        urnaEleitoral.realizarVotacao(0); // Voto em branco.
        urnaEleitoral.fecharVotacao();
        urnaEleitoral.apurarResultados();
    }
}

class Comparador {
    static boolean compararStrings(String primeira, String segunda) {
        return primeira.equals(segunda);
    }
}

class Contato {
    private String nome;
    private String numero;

    public Contato(String nome, String numero) {
        this.nome = nome;
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }
}

class SistemaTelefonico {
    Contato[] contatos;
    private static int indice = 0;
    private final int LIMITE;

    public SistemaTelefonico(int limite) {
        this.LIMITE = limite;
        contatos = new Contato[this.LIMITE];
    }

    public void cadastrar(String nome, String numero) throws Exception {
            contatos[indice++] = new Contato(nome, numero);
    }

    public void cadastrar(Contato contato) throws Exception {
                contatos[indice++] = contato;
    }

    public void remover(String nome) {
        for (var contato : contatos) {
            if (contato == null) {
                continue;
            } else if (Comparador.compararStrings(contato.getNome(), nome)) {
                contato = null;
            }
        }
    }

    public void remover(Contato contato) {
        for (var contatoInterno : contatos) {
            if (contatoInterno.equals(contato)) {
                contatoInterno = null;
            }
        }
    }

    public void atualizarNumero(String nome, String numero) {
        for (var contato : contatos) {
            if (Comparador.compararStrings(contato.getNome(), nome)) {
                contato.setNumero(numero);
            }
        }
    }

    public void atualizarNumero(Contato contato, String numero) {
        for (var contatoInterno : contatos) {
            if (contatoInterno == null) {
                continue;
            } else if (contatoInterno.equals(contato)) {
                contatoInterno.setNumero(numero);
            }
        }
    }

    public String pesquisarNumero(String nome) {
        String resultado = "";
        for (var contato : contatos) {
            if (contato == null) {
                continue;
            } else if (Comparador.compararStrings(contato.getNome(), nome)) {
                resultado = contato.getNumero();
            }
        }

        return resultado;
    }

    public static void main(String[] args) throws Exception {
        Contato policia = new Contato("Polícia", "190");
        SistemaTelefonico sistemaTelefonico = new SistemaTelefonico(10);

        sistemaTelefonico.cadastrar(policia);
        sistemaTelefonico.cadastrar("SAMU", "192");
        sistemaTelefonico.remover("SAMU");
        sistemaTelefonico.atualizarNumero(policia, "911");
        IO.println(sistemaTelefonico.pesquisarNumero("Polícia"));
    }
}

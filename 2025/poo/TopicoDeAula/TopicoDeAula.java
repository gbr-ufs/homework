import java.time.LocalDateTime;

class TopicoDeAula {
    private static final int LIMITE_DE_TOPICOS = 100;
    public static TopicoDeAula[] topicos = new TopicoDeAula[LIMITE_DE_TOPICOS];
    private static int indiceDeTopicos = 0;
    private LocalDateTime data;
    private String titulo;
    private String assunto;

    public static void printTopicos() {
        // Uma parada meio JSON, achei legal.
        if (topicos[0] != null) {
            IO.println("{");
            int i = 0;
            while (topicos[i] != null) {
                IO.println("  {");
                IO.println("    titulo: " + topicos[i].titulo);
                IO.println("    assunto: " + topicos[i].assunto);
                IO.println("  }");
                i++;
            }
            IO.println("}");
        }
    }

    public TopicoDeAula(LocalDateTime data, String titulo, String assunto) {
        this.data = data;
        this.titulo = titulo;
        this.assunto = assunto;
    }

    public TopicoDeAula(String titulo, String assunto) {
        this.data = LocalDateTime.now();
        this.titulo = titulo;
        this.assunto = assunto;
    }

    public void adicionarTopico() {
        // Coloca o valor de topicos[0], e aumenta para topicos[1] caso
        // apareça mais um tópico.
        topicos[indiceDeTopicos++] = this;
    }

    public static void main(String[] args) {
        String titulo;
        String assunto;

        titulo = IO.readln("Insira o título do tópico de aula: ");
        assunto = IO.readln("Insira o assunto do tópico de aula: ");

        TopicoDeAula topicoDeAula = new TopicoDeAula(titulo, assunto);
        topicoDeAula.adicionarTopico();
        TopicoDeAula array = new TopicoDeAula("Arrays", "Essa aula fala sobre arrays");
        array.adicionarTopico();
        TopicoDeAula.printTopicos();
    }
}

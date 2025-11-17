import java.time.LocalDate;

public abstract class Participante {
    public String nome;

    public String getNome() {
	return nome;
    }

    // 0 representa um professor.
    public long matricula = 0;

    public Participante(String nome, long matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }
}

class Professor extends Participante {
    public Professor(String nome) {
        super(nome, 0);
    }
}

class Aluno extends Participante {
    public Aluno(String nome, long matricula) {
	super(nome, matricula);
    }
}

class Turma {
    private Professor professor;
    // Nunca vi chegar a esse ponto, mas não vou colocar 50 porque a nossa
    // própria turma já passa disso.
    private static final int LIMITE_DE_ALUNOS = 100;
    private Aluno[] alunos = new Aluno[LIMITE_DE_ALUNOS];
    private static int indiceDeAlunos = 0;
    private String nome;
    private String disciplina;
    private LocalDate periodo;

    public Turma(Professor professor, String nome, String disciplina, LocalDate periodo) {
        this.professor = professor;
        this.nome = nome;
        this.disciplina = disciplina;
        this.periodo = periodo;
    }

    public Turma(Professor professor, String nome, String disciplina) {
        this.professor = professor;
        this.nome = nome;
        this.disciplina = disciplina;
        this.periodo = LocalDate.now();
    }

    public void printAlunos() {
        for (var aluno : alunos) {
            if (aluno != null) {
                IO.println(aluno.getNome());
            }
        }
    }

    public void adicionarAluno(Aluno aluno) {
        alunos[indiceDeAlunos++] = aluno;
    }
}

class SistemaDeAlunos {
    public static void main(String[] args) {
        Professor giovanny = new Professor("Giovanny Fernando Lucero Palma");
        Aluno fulano = new Aluno("Fulano Silva", 202500012345l);
        Aluno ciclano = new Aluno("Ciclano Santos", 202500067890l);
        Aluno beltrano = new Aluno("Beltrano Souza", 202500010112l);
        Turma t01 = new Turma(giovanny, "Turma 01", "Programação Orientada a Objetos");

        t01.adicionarAluno(fulano);
        t01.adicionarAluno(ciclano);
        t01.printAlunos();
        IO.println();
        t01.adicionarAluno(beltrano);
        t01.printAlunos();
    }
}

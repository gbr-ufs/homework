import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main {
    public static void main(String[] args) {
        Administrativo administrador = new Administrativo("Foo", "123.456.789-00", LocalDate.of(2000, 9, 25));
        ArrayList<String> poo = new ArrayList<String>(Arrays.asList("Programação Orientada a Objetos"));
        DocenteExclusivo docenteExclusivo = new DocenteExclusivo("Bar", "456.789.123-00", LocalDate.of(1997, 1, 1), poo);
        ArrayList<String> pi = new ArrayList<String>(Arrays.asList("Programação Imperativa"));
        DocenteParcial docenteParcial = new DocenteParcial("Bob", "101.101.101-00", LocalDate.of(1970, 2, 13), pi);
        ArrayList<String> pf = new ArrayList<String>(Arrays.asList("Programação Funcional"));
        DocenteSubstitutoCargaMaior docenteSubstitutoCargaMaior = new DocenteSubstitutoCargaMaior("Alice", "011.235.813-21", LocalDate.of(2001, 5, 15), pf);
        ArrayList<String> ies = new ArrayList<String>(Arrays.asList("Informática, Ética e Sociedade", "Interface Humano-Computador"));
                DocenteSubstitutoCargaMenor docenteSubstitutoCargaMenor = new DocenteSubstitutoCargaMenor("Roger", "301.321.372-10", LocalDate.of(1973, 11, 1), ies);
        ArrayList<String> didatica2 = new ArrayList<String>(Arrays.asList("Didática 2"));
        Terceirizado terceirizado = new Terceirizado("David", "198.121.210-08", LocalDate.of(1971, 1, 7), didatica2);

        IO.println(administrador.getNome());
        administrador.setNome("Baz");
        IO.println(administrador.getNome());
        IO.println(administrador.calcularPagamento());
        IO.println(docenteExclusivo.getCPF());
        IO.println(docenteExclusivo.calcularPagamento());
        IO.println(docenteParcial.getDataDeNascimento());
        IO.println(docenteParcial.calcularPagamento());
        IO.println(docenteSubstitutoCargaMaior.idade());
        IO.println(docenteSubstitutoCargaMaior.calcularPagamento());
        IO.println(docenteSubstitutoCargaMenor.getDisciplinas());
        IO.println(docenteSubstitutoCargaMenor.calcularPagamento());
        docenteSubstitutoCargaMenor.retirarDisciplina("Informática, Ética e Sociedade");
        IO.println(docenteSubstitutoCargaMenor.getDisciplinas());
        docenteSubstitutoCargaMenor.adicionarDisciplina("Engenharia de Software");
        IO.println(docenteSubstitutoCargaMenor.getDisciplinas());
        IO.println(terceirizado.getDependencias());
        terceirizado.retirarDependencia("Didática 2");
        IO.println(terceirizado.getDependencias());
        terceirizado.adicionarDependencia("Didática 3");
    }
}

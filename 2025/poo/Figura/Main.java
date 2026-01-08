import java.util.HashSet;
import java.util.Set;

class Main {
    private static Boolean temCorRepetida(Figura figuras[]) {
        Set<String> coresVistas = new HashSet<>();

        for (var figura: figuras) {
            if (!coresVistas.add(figura.getCor())) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Circulo circulo = new Circulo("Vermelho", 2.0);
        Esfera esfera = new Esfera("Laranja", 1.354);
        Prisma prisma = new Prisma("Amarelo", 2.63, 7.71, 5.62);
        Retangulo retangulo = new Retangulo("Amarelo", 2.0, 4.0);
        Triangulo triangulo = new Triangulo("Verde", 4.0, 2.0);
        Figura figuras[] = {circulo, esfera, prisma, retangulo, triangulo};
        Boolean corRepetida = temCorRepetida(figuras);

        IO.println("Figuras:");
        for (var figura: figuras) {
            IO.println(figura);
        }

        IO.println("Tem alguma cor repetida? Se sim, exiba true.");
        IO.println(corRepetida);
        IO.println();

        IO.println("Área das figuras:");
        for (var figura: figuras) {
            IO.println(figura.getClass().getSimpleName());
            IO.println(figura.getArea());
        }
        IO.println();

        IO.println("Volume das figuras:");
        for (var figura: figuras) {
            if (figura instanceof VolumeCalculavel figuraComVolume) {
                IO.println(figuraComVolume.getClass().getSimpleName());
                IO.println(figuraComVolume.getVolume());
            }
        }
    }
}

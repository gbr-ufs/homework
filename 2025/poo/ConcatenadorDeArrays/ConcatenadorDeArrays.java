import java.util.Arrays;

class ConcatenadorDeArrays {
    public static <T> T[] concatenarArrays(T[] arr1, T[] arr2) {
        T[] resultado = Arrays.copyOf(arr1, arr1.length + arr2.length);

        for (int i = 0; i < arr2.length; i++) {
            resultado[arr1.length + i] = arr2[i];
        }

        return resultado;
    }
    public static void main(String[] args) {
        Integer integer1[] = {1, 2, 3, 7, 5};
        Integer integer2[] = {5, 1, 7, 10, 9};
        Double double1[] = {2.12, 6.13, 7.19, 2.15, 7.1};
        Double double2[] = {10.5, 7.1, 8.125, 6.12, 91.3};
        String string1[] = {"a", "b", "c", "d", "e"};
        String string2[] = {"f", "g", "h", "i", "j"};

        for (var item : ConcatenadorDeArrays.concatenarArrays(integer1, integer2)) {
            IO.println(item);
        }
        for (var item : ConcatenadorDeArrays.concatenarArrays(double1, double2)) {
            IO.println(item);
        }
        for (var item : ConcatenadorDeArrays.concatenarArrays(string1, string2)) {
            IO.println(item);
        }
    }
}

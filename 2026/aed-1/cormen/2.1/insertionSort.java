public class insertionSort {
    public static void sort(int[] a, int n) {
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
    }
    public static void main(String[] args) {
        int a[] = {4, 3, 1, 6, 10};
        int n = a.length;

        IO.println("Unsorted.");

        for (int i = 0; i < n; i++) {
            IO.println(a[i]);
        }

        sort(a, n);

        IO.println("Sorted.");

        for (int i = 0; i < n; i++) {
            IO.println(a[i]);
        }
    }
}

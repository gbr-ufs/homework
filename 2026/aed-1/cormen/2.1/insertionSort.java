public class insertionSort {
    public static void sort(int[] A, int n) {
        for (int i = 1; i < n; i++) {
            int key = A[i];
            int j = i - 1;

            while (j >= 0 && A[j] > key) {
                A[j + 1] = A[j];
                j = j - 1;
            }

            A[j + 1] = key;
        }
    }
    public static void main(String[] args) {
        int A[] = {4, 3, 1, 6, 10};
        int n = A.length;

        IO.println("Unsorted.");

        for (int i = 0; i < n; i++) {
            IO.println(A[i]);
        }

        sort(A, n);

        IO.println("Sorted.");

        for (int i = 0; i < n; i++) {
            IO.println(A[i]);
        }
    }
}

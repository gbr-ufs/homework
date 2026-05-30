public class mergeSort {
    public static void merge(int[] A, int p, int q, int r) {
        int n_L = q - p + 1;
        int n_R = r - q;
        int[] L = new int[n_L];
        int[] R = new int[n_R];

        for (int i = 0; i < n_L; i++) {
            L[i] = A[p + i];
        }

        for (int i = 0; i < n_R; i++) {
            R[i] = A[q + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = p;

        while (i < n_L && j < n_R) {
            if (L[i] <= R[j]) {
                A[k++] = L[i++];
            } else {
                A[k++] = R[j++];
            }
        }

        while (i < n_L) {
            A[k++] = L[i++];
        }

        while (j < n_R) {
            A[k++] = R[j++];
        }
    }

    public static void sort(int[] A, int p, int r) {
        if (p >= r) {
            return;
        }

        int q = ((p + r) / 2);

        sort(A, p, q);
        sort(A, q + 1, r);
        merge(A, p, q, r);
    }

    public static void main(String[] args) {
        int A[] = {4, 3, 1, 6, 10};
        int n = A.length;
        int p = 0;
        int r = 4;

        IO.println("Unsorted.");

        for (int i = 0; i < n; i++) {
            IO.println(A[i]);
        }

        sort(A, p, r);

        IO.println("Sorted.");

        for (int i = 0; i < n; i++) {
            IO.println(A[i]);
        }
    }
}

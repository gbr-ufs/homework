public class addBinaryIntegers {
    public static int[] solve(int[] A, int[] B, int n) {
        int[] C = new int[n];
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i] * i << i;
            sum += B[i] * i << i;
        }

        for (int i = 0; sum != 0; i++) {
            C[i] = sum % 2;
            sum = sum / 2;
        }

        return C;
    }
    public static void main(String[] args) {
        int[] A = {1, 0, 0, 0, 0};
        int[] B = {1, 1, 0, 0, 0};
        int n = 5;
        int[] C = solve(A, B, n);

        for (int i = 0; i < n; i++) {
            IO.println(C[i]);
        }
    }
}

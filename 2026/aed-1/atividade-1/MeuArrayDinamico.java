public class MeuArrayDinamico {
    private int[] dados;
    private int tamanho;

    public MeuArrayDinamico(int capacidadeInicial) {
        // Não precisa do this.
        dados = new int[capacidadeInicial];
        tamanho = 0;
    }

    private void resize() {
        int[] tmp = new int[tamanho * 2];

        for (int i = 0; i < tamanho; i++) {
            tmp[i] = dados[i];
        }

        dados = tmp;
    }

    public void add(int valor) {
        if (tamanho == dados.length){
            resize();
        }

        dados[tamanho++] = valor;
    }

    public int get(int indice) {
        if (indice < 0 || indice >= tamanho) {
            throw new IndexOutOfBoundsException("Índice inválido: " + indice);
        }

        return dados[indice];
    }

    public int size() {
        return tamanho;
    }

    public void remove(int indice) {
        if (indice < 0 || indice >= tamanho) {
            throw new IndexOutOfBoundsException("Índice inválido: " + indice);
        }

        for (int i = indice; i < tamanho - 1; i++) {
            dados[i] = dados[i + 1];
        }

        tamanho--;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");

        for (int i = 0; i < tamanho; i++) {
            sb.append(dados[i]);
            if (i < tamanho - 1) {
                sb.append(", ");
            }
        }

        sb.append("]");

        return sb.toString();
    }

    public static void main(String[] args) {
        MeuArrayDinamico arr = new MeuArrayDinamico(2);

        arr.add(10);
        arr.add(20);
        // IO.println(arr);
        System.out.println(arr);
        arr.add(30);
        arr.add(40);
        // IO.println(arr);
        System.out.println(arr);
        // IO.println("Tamanho: " + arr.size());
        System.out.println("Tamanho: " + arr.size());
        arr.remove(1);
        // IO.println(arr);
        System.out.println(arr);
        arr.remove(0);
        // IO.println(arr);
        System.out.println(arr);
        // IO.println("Tamanho: " + arr.size());
        System.out.println("Tamanho: " + arr.size());
    }
}

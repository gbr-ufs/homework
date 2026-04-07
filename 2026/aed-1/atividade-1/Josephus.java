public class Josephus {
    public static void main(String[] args) {
        int N = 6;
        int M = 3;

        Node primeiro = new Node(1);
        Node atual = primeiro;
        for (int i = 2; i <= N; i++) {
            Node novo = new Node(i);
            atual.next = novo;
            atual = novo;
        }
        atual.next = primeiro;

        Node anterior = atual;
        atual = primeiro;

        // IO.println("Ordem de eliminação:");
        System.out.println("Ordem de eliminação:");

        while (atual.next != atual) {
            for (int i = 0; i < M - 1; i++) {
                anterior = atual;
                atual = atual.next;
            }

            anterior.next = atual.next;
            // IO.println(atual.item);
            System.out.println(atual.item);
            atual = anterior.next;
        }

        // IO.println("Sobrevivente: " + atual.item);
        System.out.println("Sobrevivente: " + atual.item);
    }
}

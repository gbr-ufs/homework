public class ListaSimples {
    private Node head;

    public ListaSimples() {
        this.head = null;
    }

    public void insertFirst(Object item) {
        Node tmp = new Node(item, head);

        head = tmp;
    }

    public Node find(Object item) {
        Node atual = head;

        while (atual != null) {
            if (atual.item.equals(item)) {
                return atual;
            }

            atual = atual.next;
        }

        return null;
    }

    public void insertAfter(Node x, Object item) {
        if (x == null) {
            return;
        }

        Node novo = new Node(item);

        novo.next = x.next;
        x.next = novo;
    }

    @Override
    public String toString() {
        Node atual = head;

        StringBuilder sb = new StringBuilder();

        while (atual != null) {
            sb.append(atual.item);
            sb.append(" -> ");
            atual = atual.next;
        }

        sb.append("null");

        return sb.toString();
    }

    public static void main(String[] args) {
        ListaSimples lista = new ListaSimples();
        lista.insertFirst("C");
        lista.insertFirst("B");
        lista.insertFirst("A");
        // IO.println(lista);
        System.out.println(lista);
        Node noB = lista.find("B");
        if (noB != null) {
            lista.insertAfter(noB, "B2");
        }
        // IO.println(lista);
        System.out.println(lista);
        Node noZ = lista.find("Z");
        // IO.println("Busca por Z: " + noZ);
        System.out.println("Busca por Z: " + noZ);
    }
}

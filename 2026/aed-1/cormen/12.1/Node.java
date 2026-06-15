public class Node<T> {
    public int key;
    public T data;
    public Node<T> left = null;
    public Node<T> right = null;
    public Node<T> p = null;

    Node(int key, T data) {
        this.key = key;
        this.data = data;
    }
}

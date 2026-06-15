public class Main {
    public static void main(String[] args) {
        Tree<Integer> tree = new Tree<>(6, 6);
        Node<Integer> sevenNode = new Node<Integer>(7, 7);

        tree.insert(new Node<Integer>(5, 5));
        tree.insert(new Node<Integer>(2, 2));
        tree.insert(new Node<Integer>(5, 5));
        tree.insert(sevenNode);
        tree.insert(new Node<Integer>(8, 8));

        Node<Integer> found = tree.search(tree.root, 8);

        if (found != null) {
            IO.println("found: " + found.data);
        }

        Node<Integer> minimum = tree.minimum(tree.root);

        if (minimum != null) {
            IO.println("minimum: " + minimum.data);
        }

        Node<Integer> maximum = tree.maximum(tree.root);

        if (maximum != null) {
            IO.println("maximum: " + maximum.data);
        }

        Node<Integer> predecessor = tree.predecessor(sevenNode);

        if (predecessor != null) {
            IO.println("predecessor of 7: " + predecessor.data);
        }

        Node<Integer> successor = tree.successor(sevenNode);

        if (successor != null) {
            IO.println("successor of 7: " + successor.data);
        }

        IO.println("preorder walk:");

        tree.preorderWalk(tree.root);

        IO.println("inorder wak:");

        tree.inorderWalk(tree.root);

        IO.println();

        tree.inorderWalkNonRecursive(tree.root);

        IO.println("postorder walk:");

        tree.postorderWalk(tree.root);

        IO.println("inorder walk after deleting 7:");

        tree.delete(sevenNode);

        tree.inorderWalk(tree.root);
    }
}

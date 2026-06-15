public class Tree<T> {
    public Node<T> root;

    Tree(int key, T data) {
        root = new Node<T>(key, data);
    }

    Node<T> search(Node<T> x, int k) {
        if (x == null || k == x.key) {
            return x;
        }

        if (k < x.key) {
            return search(x.left, k);
        } else {
            return search(x.right, k);
        }
    }

    Node<T> minimum(Node<T> x) {
        while (x.left != null) {
            x = x.left;
        }

        return x;
    }


    Node<T> maximum(Node<T> x) {
        while (x.right != null) {
            x = x.right;
        }

        return x;
    }

    Node<T> predecessor(Node<T> x) {
        if (x.left != null) {
            return maximum(x.left);
        } else {
            Node<T> y = x.p;

            while (y != null && x == y.left) {
                x = y;
                y = y.p;
            }

            return y;
        }
    }

    Node<T> successor(Node<T> x) {
        if (x.right != null) {
            return minimum(x.right);
        } else {
            Node<T> y = x.p;

            while (y != null && x == y.right) {
                x = y;
                y = y.p;
            }

            return y;
        }
    }

    void insert(Node<T> z) {
        Node<T> x = root;
        Node<T> y = null;

        while (x != null) {
            y = x;

            if (z.key < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }

        z.p = y;

        if (y == null) {
            root = z;
        } else if (z.key < y.key) {
            y.left = z;
        } else {
            y.right = z;
        }
    }

    void transplant(Node<T> u, Node<T> v) {
        if (u.p == null) {
            root = v;
        } else if (u == u.p.left) {
            u.p.left = v;
        } else {
            u.p.right = v;
        }

        if (v != null) {
            v.p = u.p;
        }
    }

    void delete(Node<T> z) {
        if (z.left == null) {
            transplant(z, z.right);
        } else if (z.right == null) {
            transplant(z, z.left);
        } else {
            Node<T> y = minimum(z.right);

            if (y != z.right) {
                transplant(y, y.right);
                y.right = z.right;
                y.right.p = y;
            }

            transplant(z, y);
            y.left = z.left;
            y.left.p = y;
        }

        z = null;
    }

    void preorderWalk(Node<T> x) {
        if (x != null) {
            IO.println(x.key);

            preorderWalk(x.left);

            preorderWalk(x.right);
        }
    }

    void inorderWalk(Node<T> x) {
        if (x != null) {
            inorderWalk(x.left);

            IO.println(x.key);

            inorderWalk(x.right);
        }
    }

    void postorderWalk(Node<T> x) {
        if (x != null) {
            postorderWalk(x.left);

            postorderWalk(x.right);

            IO.println(x.key);
        }
    }

    void inorderWalkNonRecursive(Node<T> x) {
        Node<T> previous = null;
        Node<T> current = root;

        while (current != null) {
            if (previous == current.p) {
                if (current.left != null) {
                    previous = current;
                    current = current.left;
                } else {
                    IO.println(current.key);

                    if (current.right != null) {
                        previous = current;
                        current = current.right;
                    } else {
                        previous = current;
                        current = current.p;
                    }
                }
            } else if (previous == current.left) {
                IO.println(current.key);

                if (current.right != null) {
                    previous = current;
                    current = current.right;
                } else {
                    previous = current;
                    current = current.p;
                }
            } else {
                previous = current;
                current = current.p;
            }
        }
    }
}

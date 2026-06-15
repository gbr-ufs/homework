from Node import Node
from Tree import Tree

def main() -> None:
    tree: Tree = Tree(6, 6)
    sevenNode: Node = Node(7, 7)

    tree.insert(Node(5, 5))
    tree.insert(Node(2, 2))
    tree.insert(Node(5, 5))
    tree.insert(sevenNode)
    tree.insert(Node(8, 8))

    found: Node | None = tree.search(tree.root, 8)

    if found:
        print(f"found: {found.data}")

    minimum: Node | None = tree.minimum(tree.root)

    if minimum:
        print(f"minimum: {minimum.data}")

    maximum: Node | None = tree.maximum(tree.root)

    if maximum:
        print(f"maximum: {maximum.data}")

    predecessor: Node | None = tree.predecessor(sevenNode)

    if predecessor:
        print(f"predecessor of 7: {predecessor.data}")

    successor: Node | None = tree.successor(sevenNode)

    if successor:
        print(f"successor of 7: {successor.data}")

    print("preorder walk:")

    tree.preorder_walk(tree.root)

    print("inorder wak:")

    tree.inorder_walk(tree.root)

    print("")

    tree.inorder_walk_non_recursive(tree.root)

    print("postorder walk:")

    tree.postorder_walk(tree.root)

    print("inorder walk after deleting 7:")

    tree.delete(sevenNode)

    tree.inorder_walk(tree.root)


if __name__ == '__main__':
    main()

from typing import Any, Optional

from Node import Node


class Tree:
    def __init__(self, key: int, data: Any) -> None:
        self.root = Node(key, data)

    def search(self, x: Optional[Node], k: int) -> Node | None:
        if x is None or k == x.key:
            return x

        if k < x.key:
            return self.search(x.left, k)
        else:
            return self.search(x.right, k)

    def minimum(self, x: Optional[Node]) -> Node | None:
        while x.left is not None:
            x = x.left

        return x

    def maximum(self, x: Optional[Node]) -> Node | None:
        while x.right is not None:
            x = x.right

        return x

    def predecessor(self, x: Optional[Node]) -> Node | None:
        if x.left is not None:
            return self.maximum(x.left)
        else:
            y: Node | None = x.p

            while y is not None and x is y.left:
                x = y
                y = y.p

            return y

    def successor(self, x: Optional[Node]) -> Node | None:
        if x.right is not None:
            return self.minimum(x.right)
        else:
            y: Node | None = x.p

            while y is not None and x is y.right:
                x = y
                y = y.p

            return y

    def insert(self, z: Node) -> None:
        x: Node | None = self.root
        y: Node | None = None

        while x is not None:
            y = x

            if (z.key < x.key):
                x = x.left
            else:
                x = x.right

        z.p = y

        if y is None:
            root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def transplant(self, u: Node, v: Node | None) -> None:
        if u.p is None:
            root = v
        elif u is u.p.left:
            u.p.left = v
        else:
            u.p.right = v

        if v is not None:
            v.p = u.p

    def delete(self, z: Node | None) -> None:
        if z.left is None:
            self.transplant(z, z.right)
        elif z.right is None:
            self.transplant(z, z.left)
        else:
            y: Node | None = self.minimum(z.right)

            if y is not z.right:
                self.transplant(y, y.right)
                y.right = z.right
                y.right.p = y

            self.transplant(z, y)
            y.left = z.left
            y.left.p = y

        z = None

    def preorder_walk(self, x: Node | None) -> None:
        if x is not None:
            print(x.key)

            self.preorder_walk(x.left)

            self.preorder_walk(x.right)

    def inorder_walk(self, x: Node | None) -> None:
        if x is not None:
            self.inorder_walk(x.left)

            print(x.key)

            self.inorder_walk(x.right)

    def postorder_walk(self, x: Node | None) -> None:
        if x is not None:
            self.postorder_walk(x.left)

            self.postorder_walk(x.right)

            print(x.key)

    def inorder_walk_non_recursive(self, x: Node | None) -> None:
        previous: Node | None = None
        current: Node | None = self.root

        while (current is not None):
            if previous is current.p:
                if current.left is not None:
                    previous = current
                    current = current.left
                else:
                    print(current.key)

                    if current.right is not None:
                        previous = current
                        current = current.right
                    else:
                        previous = current
                        current = current.p
            elif previous is current.left:
                print(current.key)

                if current.right is not None:
                    previous = current
                    current = current.right
                else:
                    previous = current
                    current = current.p
            else:
                previous = current
                current = current.p

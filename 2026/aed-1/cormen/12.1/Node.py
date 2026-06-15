from typing import Any

class Node:
    def __init__(self, key: int, data: Any) -> None:
        self.key: int = key
        self.data: Any = data
        self.left: Node | None = None
        self.right: Node | None = None
        self.p: Node | None = None

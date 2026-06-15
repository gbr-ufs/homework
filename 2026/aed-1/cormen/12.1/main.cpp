#include "Node.hpp"
#include "Tree.hpp"

int main() {
  Tree<int> *tree = new Tree(6, 6);
  Node<int> *sevenNode = new Node(7, 7);

  tree->insert(new Node(5, 5));
  tree->insert(new Node(2, 2));
  tree->insert(new Node(5, 5));
  tree->insert(sevenNode);
  tree->insert(new Node(8, 8));

  Node<int> *found = tree->search(tree->root, 8);

  if (found) {
    std::cout << "found: " << found->data << '\n';
  }

  Node<int> *minimum = tree->minimum(tree->root);

  if (minimum) {
    std::cout << "minimum: " << minimum->data << '\n';
  }

  Node<int> *maximum = tree->maximum(tree->root);

  if (maximum) {
    std::cout << "maximum: " << maximum->data << '\n';
  }

  Node<int> *predecessor = tree->predecessor(sevenNode);

  if (predecessor) {
    std::cout << "predecessor of 7: " << predecessor->data << '\n';
  }

  Node<int> *successor = tree->successor(sevenNode);

  if (successor) {
    std::cout << "successor of 7: " << successor->data << '\n';
  }

  std::cout << "preorder walk:" << '\n';

  tree->preorderWalk(tree->root);

  std::cout << "inorder walk:" << '\n';

  tree->inorderWalk(tree->root);

  std::cout << '\n';

  tree->inorderWalkNonRecursive(tree->root);

  std::cout << "postorder walk:" << '\n';

  tree->postorderWalk(tree->root);

  std::cout << "inorder walk after deleting 7:" << '\n';

  tree->Delete(sevenNode);

  tree->inorderWalk(tree->root);

  return 0;
}

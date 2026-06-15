#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>

template <typename T> class Tree {
public:
  Node<T> *root;

  Tree(int key, T data) { root = new Node<T>(key, data); }

  Node<T> *search(Node<T> *x, int k) {
    if (x == nullptr || k == x->key) {
      return x;
    }

    if (k < x->key) {
      return search(x->left, k);
    } else {
      return search(x->right, k);
    }
  }

  Node<T> *minimum(Node<T> *x) {
    while (x->left != nullptr) {
      x = x->left;
    }

    return x;
  }

  Node<T> *maximum(Node<T> *x) {
    while (x->right != nullptr) {
      x = x->right;
    }

    return x;
  };

  Node<T> *predecessor(Node<T> *x) {
    if (x->left != nullptr) {
      return maximum(x->left);
    } else {
      Node<T> *y = x->p;

      while (y != nullptr && x == y->left) {
        x = y;
        y = y->p;
      }

      return y;
    }
  }

  Node<T> *successor(Node<T> *x) {
    if (x->right != nullptr) {
      return minimum(x->right);
    } else {
      Node<T> *y = x->p;

      while (y != nullptr && x == y->right) {
        x = y;
        y = y->p;
      }

      return y;
    };
  }

  void insert(Node<T> *z) {
    Node<T> *x = root;
    Node<T> *y = nullptr;

    while (x != nullptr) {
      y = x;

      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    z->p = y;

    if (y == nullptr) {
      root = z;
    } else if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }

  void transplant(Node<T> *u, Node<T> *v) {
    if (u->p == nullptr) {
      root = v;
    } else if (u == u->p->left) {
      u->p->left = v;
    } else {
      u->p->right = v;
    }

    if (v != nullptr) {
      v->p = u->p;
    }
  }

  void Delete(Node<T> *z) {
    if (z->left == nullptr) {
      transplant(z, z->right);
    } else if (z->right == nullptr) {
      transplant(z, z->left);
    } else {
      Node<T> *y = minimum(z->right);

      if (y != z->right) {
        transplant(y, y->right);
        y->right = z->right;
        y->right->p = y;
      }

      transplant(z, y);
      y->left = z->left;
      y->left->p = y;
    }

    delete z;
  }

  void preorderWalk(Node<T> *x) {
    if (x != nullptr) {
      std::cout << x->key << '\n';

      preorderWalk(x->left);

      preorderWalk(x->right);
    }
  }

  void inorderWalk(Node<T> *x) {
    if (x != nullptr) {
      inorderWalk(x->left);

      std::cout << x->key << '\n';

      inorderWalk(x->right);
    }
  }

  void postorderWalk(Node<T> *x) {
    if (x != nullptr) {
      postorderWalk(x->left);

      postorderWalk(x->right);

      std::cout << x->key << '\n';
    }
  }

  void inorderWalkNonRecursive(Node<T> *x) {
    Node<T> *previous = nullptr;
    Node<T> *current = root;

    while (current != nullptr) {
      if (previous == current->p) {
        if (current->left != nullptr) {
          previous = current;
          current = current->left;
        } else {
          std::cout << current->key << '\n';

          if (current->right != nullptr) {
            previous = current;
            current = current->right;
          } else {
            previous = current;
            current = current->p;
          }
        }
      } else if (previous == current->left) {
        std::cout << current->key << '\n';

        if (current->right != nullptr) {
          previous = current;
          current = current->right;
        } else {
          previous = current;
          current = current->p;
        }
      } else {
        previous = current;
        current = current->p;
      }
    }
  }
};

#endif

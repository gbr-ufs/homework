#ifndef NODE_HPP
#define NODE_HPP

template <typename T> class Node {
public:
  int key;
  T data;
  Node *left;
  Node *right;
  Node *p;

  Node(int key, T data)
      : key(key), data(data), left(nullptr), right(nullptr), p(nullptr) {}
};

#endif

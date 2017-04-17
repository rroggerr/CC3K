#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next): data(data), next(next) {}

  Node(const Node &n):
    data(n.data),
    next(n.next==NULL ? NULL : new Node(*n.next)) {}

  explicit Node(int n): data(n), next(NULL) {}

  ~Node() {
    delete next;
  }

  Node &operator=(const Node &other) {
    if (this == &other) return *this;
    data = other.data;
    Node *tmp = next;
    next = other.next ? new Node(*other.next) : 0;
    delete tmp;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, const Node &n);
#endif

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
    std::cout << "Destructor called" << std::endl;
    delete next;
  }
};

std::ostream &operator<<(std::ostream &out, const Node &n);
#endif

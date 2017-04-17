#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next);
  Node(const Node &n);
  explicit Node(int n);

  ~Node();

  Node &operator=(const Node &other);

  void swap(Node &other);
};

std::ostream &operator<<(std::ostream &out, const Node &n);

#endif


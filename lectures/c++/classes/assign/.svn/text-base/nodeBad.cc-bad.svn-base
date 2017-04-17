#include <iostream>
#include "node.h"
using namespace std;

Node::Node(int data, Node *next): data(data), next(next) {}

Node::Node(const Node &n):
  data(n.data),
  next(n.next==NULL ? NULL : new Node(*n.next)) {}

Node::Node(int n): data(n), next(NULL) {}

Node::~Node() {
  delete next;
}

Node &Node::operator=(const Node &other) {
  data = other.data;
  delete next;
  next = other.next? new Node(*other.next): 0;
  return *this;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << "," << *n.next;
  }
  return out;
}

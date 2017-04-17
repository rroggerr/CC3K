#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next=0);

  Node(const Node &n);
};

std::ostream &operator<<(std::ostream &out, const Node &n);

#endif


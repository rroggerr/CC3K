#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next=0): data(data), next(next) {}

  Node(const Node &n): data(n.data),
                       next(n.next == NULL ? NULL : new Node(*n.next)) {}
};

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << ",";
    out << *n.next;
  }
  return out;
}

int main() {
  Node myNode = 4;
  Node myNode2(5, &myNode);

  cout << "myNode2: " << myNode2 << endl;
}

#include <iostream>
#include "window.h"

using namespace std;

int main() {
  Xwindow w;

  w.fillRectangle(100, 200, 50, 250, Xwindow::Blue);

  w.drawString(50, 50, "Hello!");

  char c;
  cin >> c;
}


#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;
  const int gridSize;
 public:
  TextDisplay(int n);

  void notify(int r, int c, bool alive); // Pass true to indicate that the
                                         // cell at r,c is alive; false for
                                         // dead.

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

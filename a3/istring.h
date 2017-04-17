#ifndef __ISTRING_H__
#define __ISTRING_H__

struct iString{
  char * chars;
  unsigned int length;
  unsigned int capacity;
  iString();
  iString(const char *);
  iString(const iString&);
  iString &operator=(const iString&);
  ~iString();
};

// Add other declarations here:

#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "stack.h"

bool check(char *st) {
  Stack s;
  int k = 0;
  bool isvalid = true;
  while (st[k] && isvalid) {
    char c = st[k];
    if (c == '(' || c == '{' || c == '[') {
      s.push(c);
    } else {
      char k = s.pop();
      if (
        c == ')' && k != '(' ||
        c == '}' && k != '{' ||
        c == ']' && k != '['
      ) {
        isvalid = false;
        break;
      }
    }

    k++;
  }
  int size = s.get_size();
  if (size != 0) {
    isvalid = false;
  }
  return isvalid;
}

int main(int argc, char **argv){
  for (int i = 1; i < argc; i++) {
    bool isvalid = check(argv[i]);
    printf("argv %d %s\n", i, isvalid ? "correct" : "incorrect");
  }
  
  return 0;
}

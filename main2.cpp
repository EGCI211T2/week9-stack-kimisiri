#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "stack.h"

int check(char *st) {
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
    return 2;
  }
  return isvalid ? 1 : 0;
}

int main(int argc, char **argv){
  for (int i = 1; i < argc; i++) {
    int isvalid = check(argv[i]);
    printf("argv %d ", i);
    if (isvalid == 0) {
      printf("incorrect\n");
    } else if (isvalid == 1) {
      printf("correct\n");
    } else if (isvalid == 2) {
      printf("incorrect too many open parentheses\n");
    }
  }
  
  return 0;
}

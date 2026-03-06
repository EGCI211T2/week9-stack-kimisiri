
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
    int get_size() {
      return size;
    }
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(!new_node){
    return;
  }
  size++;
  if (!top) {
    top = new_node;
    return;
  }
  new_node->set_next(top);
  top = new_node;
}

int Stack::pop(){
  if (!top) {
    return 0;
    //throw exception(":((");
  }
  int val = top->get_value();
  NodePtr tmp = top;
  top = top->get_next();
  delete tmp;
  size -= 1;
  return val;
}

Stack::Stack(){
  top = NULL;
  size = 0;
}
Stack::~Stack(){
  while (top) {
    pop();
  }
}


#endif

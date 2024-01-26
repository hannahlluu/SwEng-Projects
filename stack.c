#include "stack.h"
// create a new stack
struct double_stack * double_stack_new(int max_size) {
struct double_stack * result;
result = malloc(sizeof(struct double_stack));
result->items = malloc(sizeof(double)*max_size); //items is the stack
result->max_size = max_size;  // 1st max size is local variable
result->top = 0;
return result;
}

// push a value onto the stack
void double_stack_push(struct double_stack * this, double value) {
assert(this->top < this->max_size) ; // checks if its valid
this->items[this->top] = value;
this->top++;
}

// pop a value from the stack
double double_stack_pop(struct double_stack * this) {
  //  assert(this->top >= 0);

  if(this->top >= 0){
    this->top--;
    return this->items[this->top];
  }
  return 0;
}

//check if stack is empty
int double_stack_empty(struct double_stack * this){
if (this->top ==0){
    return 1; // stack is empty (true)
}
return 0; // stack is NOT empty (false)
}

int is_operator(char*token){
    switch(token[0]){
      case '+':
      case '-':
      case 'X':
      case '/':
      case '^':
      return 1;
      default:
      return 0;
    }
  return 0; // if token doesnt match any operator
}


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) { 
  Node *new = (Node *)calloc(1, sizeof(Node));
  if (new == NULL) 
    return false;
  new->item = item;
  new->next = s->top;
  s->top = new;
  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  if (!stack_empty(s)){
	  CalculatorItem result = s->top -> item;
	  *output = result;
	  Node* remove = s-> top;
	  s -> top = s-> top -> next;
	  free(remove);	
	  return true;
  }
  return false;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  return s -> top == NULL;
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s){
  while ((*s)-> top != NULL){
    (*s) -> top  = ((*s)-> top -> next);
    free((*s)-> top);
  }
  (*s) = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) { 
  CalculatorItem node1;
  CalculatorItem node2;
  CalculatorItem result;

  //If the element we read is a number, we push it onto the calculation stack.
  if(item.type == NUMBER){
    stack_push(s, item);
    return true;
  }
  
  if(item.type == ADD){
    stack_pop(s, &node1);
    stack_pop(s, &node2);
    result.value = node1.value + node2.value ;
    stack_push(s, result);
    return true;
  }

  if(item.type == SUBTRACT){
    stack_pop(s, &node1);
    stack_pop(s, &node2);
    result.value = (node1.value - node2.value);
    stack_push(s, result);
    return true;
  }

if(item.type == MULTIPLY){
    stack_pop(s, &node1);
    stack_pop(s, &node2);
    result.value = node1.value * node2.value ;
    stack_push(s, result);
    return true;
  }

  if(item.type == DIVIDE){
  	stack_pop(s, &node1);
	  stack_pop(s, &node2);
  	result.value = node2.value / node1.value;
	  stack_push(s, result);
	  return true;
  }
  return false;
}

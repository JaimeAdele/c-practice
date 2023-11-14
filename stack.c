// implement a stack using a linked list

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// INT_MIN to be returned as value when pop() is called on an empty stack
#define STACK_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef node *stack;

bool push(stack *s, int value) {
  // create (malloc) a newnode
  node *newnode = malloc(sizeof (node));

  // return false if unsuccessful
  if (newnode == NULL) return false;

  // initialize newnode value
  newnode->value = value;

  // add new node as top of list
  newnode->next = *s;
  *s = newnode;

  // return true if successful
  return true;
}

int pop(stack *s) {
  // if stack is empty, return STACK_EMPTY
  if (*s == NULL) return STACK_EMPTY;

  // save top as tmp and get value
  node *tmp = *s;
  int value = tmp->value;

  // move top to next value
  *s = (*s)->next;

  // free tmp
  free(tmp);

  // return value
  return value;
}

int main() {
  // initialize stack
  stack s1 = NULL;

  // push values onto stack
  push(&s1, 1);
  push(&s1, 2);
  push(&s1, 3);

  // pop values off of stack and print to console
  int n;
  while ((n = pop(&s1)) != STACK_EMPTY) {
    printf("%d\n", n);
  }

  return 0;
}
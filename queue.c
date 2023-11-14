// implement a queue using a linked list
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

// INT_MIN to be returned as value when dequeue() is called on an empty queue
#define QUEUE_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

void init_queue(queue *q) {
  q->head = NULL;
  q->tail = NULL;
}

// add node as tail of list
bool enqueue(queue *q, int value) {
  // create newnode (return false if unsuccessful)
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL) return false;

  // initialize value of newnode and make it the new head of the queue
  newnode->value = value;
  newnode->next = NULL;
  if (q->tail != NULL) q->tail->next = newnode;
  q->tail = newnode;

  // if head is null, set tail to newnode (because that's the first node added after being empty)
  if (q->head == NULL) {
    q->head = newnode;
  }

  return true;
}

// remove head of list and return value
int dequeue(queue *q) {
  // if queue is empty, return QUEUE_EMPTY
  if (q->head == NULL) return QUEUE_EMPTY;

  // save head as tmp and get value
  node *tmp = q->head;
  int result = tmp->value;

  // change head to be the next node
  q->head = q->head->next;

  // if head is null, make tail null also
  if (q->head == NULL) q->tail = NULL;

  // release memory of tmp
  free(tmp);

  return result;
}

int main() {
  // initialize new queue to NULL
  queue q1;

  init_queue(&q1);

  // add values to queue
  enqueue(&q1, 1);
  enqueue(&q1, 2);
  enqueue(&q1, 3);

  // remove values from queue and print to console
  int n;
  while ((n = dequeue(&q1)) != QUEUE_EMPTY) {
    printf("%d\n", n);
  }

  return 0;
}
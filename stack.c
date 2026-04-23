#include "stack.h"

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, int value) {
  if (!isFull(s)) {
    s->top++;
    s->data[s->top] = value;
  }
}

int pop(Stack *s) {
  if (!isEmpty(s)) {
    int value = s->data[s->top];
    s->top--;
    return value;
  }
  return 0;
}

#include "stack.h"
#include <assert.h>

void test_stack_init_and_empty() {
  Stack s;
  initStack(&s);

  assert(isEmpty(&s) == 1);
}

void test_stack_push_pop() {
  Stack s;
  initStack(&s);
  push(&s, 42);
  push(&s, 15);

  assert(isEmpty(&s) == 0);

  int res1 = pop(&s);
  assert(res1 == 15);
  int res2 = pop(&s);
  assert(res2 == 42);

  assert(isEmpty(&s) == 1);
}

void test_stack_full() {
  Stack s;
  initStack(&s);
  for (int i = 0; i < MAX_SIZE; i++) {
    push(&s, i);
  }

  assert(isFull(&s) == 1);
  assert(isEmpty(&s) == 0);
}

int main() {
  test_stack_init_and_empty();
  test_stack_push_pop();
  test_stack_full();
  return 0;
}
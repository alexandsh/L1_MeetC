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
  int value;
  assert(push(&s, 42) == 1);
  assert(push(&s, 15) == 1);
  assert(isEmpty(&s) == 0);

  assert(pop(&s, &value) == 1);
  assert(value == 15);

  assert(pop(&s, &value) == 1);
  assert(value == 42);

  assert(isEmpty(&s) == 1);
}

void test_stack_overflow() {
  Stack s;
  initStack(&s);
  for (int i = 0; i < MAX_SIZE; i++) {
    assert(push(&s, i) == 1);
  }

  assert(isFull(&s) == 1);
  assert(push(&s, 999) == 0);
}

void test_stack_underflow() {
  Stack s;
  initStack(&s);
  int value;

  assert(pop(&s, &value) == 0);
}

int main() {
  test_stack_init_and_empty();
  test_stack_push_pop();
  test_stack_overflow();
  test_stack_underflow();
  return 0;
}

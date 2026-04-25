#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

void test_create_node(void) {
  Node *node1 = create_node(4);
  assert(node1->data == 4);
  assert(node1->next == NULL);
}

void test_add_node_and_count(void) {
  Node *list = NULL;
  list = add_node(list, 1, 0);
  list = add_node(list, 1, 1);
  assert(count_nodes(list) == 2);
}

void test_insert_by_index(void) {
  Node *list = NULL;
  list = add_node(list, 1, 0);
  list = add_node(list, 1, 1);
  list = add_node(list, 2, 1);
  assert(count_nodes(list) == 3);
  assert(node_by_index(list, 1)->data == 2);
}

void test_delete_node(void) {
  Node *list = NULL;
  list = add_node(list, 1, 0);
  list = add_node(list, 1, 1);
  list = add_node(list, 2, 1);
  list = del_node(list, 2);
  assert(count_nodes(list) == 2);
}

int main(void) {
  test_create_node();
  test_add_node_and_count();
  test_insert_by_index();
  test_delete_node();

  return 0;
}

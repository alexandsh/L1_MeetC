#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

int main() {
  Node *node1 = create_node(4);
  assert(node1->data == 4);
  assert(node1->next == NULL);

  Node *list = NULL;
  list = add_node(list, 1, 0);
  list = add_node(list, 1, 1);
  assert(count_nodes(list) == 2);

  list = add_node(list, 2, 1);
  assert(count_nodes(list) == 3);
  assert(node_by_index(list, 1)->data == 2);

  list = del_node(list, 2);
  assert(count_nodes(list) == 2);

  return 0;
}
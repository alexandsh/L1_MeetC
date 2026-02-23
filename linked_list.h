#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data);
int count_nodes(Node *node);
Node *node_by_index(Node *node, int index);
Node *add_node(Node *node, int data, int index);
Node *del_node(Node *node, int data);

#endif

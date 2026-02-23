#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

int count_nodes(Node *node) {
  int count = 0;

  while (node) {
    count++;
    node = node->next;
  }

  return count;
}

Node *find_node_by_index(Node *node, int index) {
  int i = 0;

  while (node && i < index) {
    node = node->next;
    i++;
  }

  return node;
}

Node *add_node(Node *node, int data, int index) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->data = data;
  new_node->next = node;
  if (index <= 0 || !node) {
    new_node->next = node;
    return new_node;
  }

  Node *prev = node;
  int i = 0;

  while (prev->next && i < index - 1) {
    prev = prev->next;
    i++;
  }

  new_node->next = prev->next;
  prev->next = new_node;

  return node;
}

Node *del_node(Node *node, int data) {
  Node *prev = NULL;
  Node *next = NULL;
  Node *link = node;

  while (link && (link->data != data)) {
    prev = link;
    node = node->next;
  }

  if (!link)
    return node;

  if (!prev) {
    next = link->next;
    free(link);
    return next;
  } else {
    prev->next = link->next;
    free(link);
    return node;
  }
}

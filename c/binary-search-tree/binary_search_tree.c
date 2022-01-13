#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void insert_node(node_t *node, int item)
{
  if (item <= node->data)
  {
    if (node->left == NULL)
    {
      node_t *left = malloc(sizeof(node_t));
      node->left = left;
      node->left->data = item;
      return;
    }

    insert_node(node->left, item);
  }

  if (item > node->data)
  {
    if (node->right == NULL)
    {
      node_t *right = malloc(sizeof(node_t));
      node->right = right;
      node->right->data = item;
      return;
    }

    insert_node(node->right, item);
  }
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
  // initialize head node
  node_t *head = malloc(sizeof(node_t));

  head->data = tree_data[0];
  head->left = NULL;
  head->right = NULL;

  // build the tree
  for (size_t i = 1; i < tree_data_len; i++)
  {
    insert_node(head, tree_data[i]);
  }

  return head;
}

void free_tree(node_t *tree)
{
  free(tree);
}

#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

// find the node whose left or right branch will be assigned the new item
void find_and_insert_node(node_t *node, int item)
{
  if (item <= node->data)
  {
    if (node->left == NULL)
    {
      node_t *left = malloc(sizeof(node_t));
      node->left = left;
      insert_item(node->left, item);
      return;
    }

    find_and_insert_node(node->left, item);
  }

  if (item > node->data)
  {
    if (node->right == NULL)
    {
      node_t *right = malloc(sizeof(node_t));
      node->right = right;
      insert_item(node->right, item);
      return;
    }

    find_and_insert_node(node->right, item);
  }
}

void insert_item(node_t *node, int item)
{
  node->data = item;
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
    find_and_insert_node(head, tree_data[i]);
  }

  return head;
}

void free_tree(node_t *tree)
{
  free(tree);
}

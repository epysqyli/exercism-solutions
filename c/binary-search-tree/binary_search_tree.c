#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

// generalize algorithm to assign elements to the right place
// until the whole input data has been cycled through

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
    node_t *node = find_node(head, tree_data[i]);
    insert_item(node, tree_data[i]);
  }

  return head;
}

// find the node whose left or right branch will be assigned the new item
node_t *find_node(node_t *node, int item)
{
  // case where item initially falls on the left
  if (item <= node->data)
  {
    if (node->left == NULL)
    {
      node_t *left = malloc(sizeof(node_t));
      node->left = left;
      return node->left;
    }

    find_node(node->left, item);
  }

  // case where item initially falls on the right
  if (item > node->data)
  {
    if (node->right == NULL)
    {
      node_t *right = malloc(sizeof(node_t));
      node->right = right;
      return node->right;
    }

    find_node(node->right, item);
  }

  return node;
}

void insert_item(node_t *node, int item)
{
  node->data = item;
}

void free_tree(node_t *tree)
{
  free(tree);
}

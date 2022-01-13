#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

// generalize algorithm to assign elements to the right place
// until the whole input data has been cycled through

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
  node_t *head = malloc(sizeof(node_t));

  head->data = tree_data[0];
  head->left = NULL;
  head->right = NULL;

  // build the whole tree
  for (size_t i = 1; i < tree_data_len; i++)
  {
    node_t *current = find_node(head, tree_data[i]);
    insert_item(current, tree_data[i]);
  }

  return head;
}

// find the node whose left or right branch will be assigned the new item
node_t *find_node(node_t *tree, int item)
{
  if (tree->left == NULL && tree->right == NULL)
  {
    printf("%d", item);
    return tree;
  }

  return tree;
}

void insert_item(node_t *node, int item)
{
  if (item <= node->data)
  {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    node->left = new_node;
  }

  if (item > node->data)
  {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    node->right = new_node;
  }
}

void free_tree(node_t *tree)
{
  free(tree);
}

#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void insert_node(node_t *node, int item)
{
  if (item <= node->data)
  {
    if (node->left == NULL)
    {
      node->left = malloc(sizeof(node_t));
      node->left->data = item;
      return;
    }

    insert_node(node->left, item);
  }

  if (item > node->data)
  {
    if (node->right == NULL)
    {
      node->right = malloc(sizeof(node_t));
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
    insert_node(head, tree_data[i]);

  return head;
}

void free_tree(node_t *tree)
{
  free(tree);
}

int sort_data(node_t *tree, int *sorted_array, int counter)
{
  node_t *head = tree;

  if (head->left != NULL)
    counter = sort_data(head->left, sorted_array, counter);

  counter++;
  sorted_array = realloc(sorted_array, counter * sizeof(int));
  sorted_array[counter - 1] = head->data;

  if (head->right != NULL)
    counter = sort_data(head->right, sorted_array, counter);

  return counter;
}

int *sorted_data(node_t *tree)
{
  int counter = 0;
  int *sorted_array = malloc(sizeof(int));
  sort_data(tree, sorted_array, counter);
  return sorted_array;
}

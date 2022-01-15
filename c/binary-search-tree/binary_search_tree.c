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

void print_data(node_t *node)
{
  printf("Node data: %d\n", node->data);
}

int count_tree_len(node_t *tree, int len)
{
  node_t *head = tree;

  if (head->left != NULL)
  {
    len = count_tree_len(head->left, len);
  }

  // print_data(head);
  len++;

  if (head->right != NULL)
  {
    len = count_tree_len(head->right, len);
  }

  return len;
}

int *sort_data(node_t *tree, int *sorted_array, int len)
{
  node_t *head = tree;
  // printf("Length arg is %d\n", len);

  if (head->left != NULL)
  {
    sort_data(head->left, sorted_array, len);
  }

  // print_data(head);

  if (head->right != NULL)
  {
    sort_data(head->right, sorted_array, len);
  }

  return sorted_array;
}

int *sorted_data(node_t *tree)
{
  int len = 0;

  len = count_tree_len(tree, len);
  printf("Length is: %d\n", len);

  int *sorted_array = malloc(len * sizeof(int));
  return sort_data(tree, sorted_array, len);
}

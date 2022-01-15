#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

typedef struct node node_t;

struct node
{
   node_t *right;
   node_t *left;
   int data;
};

node_t *build_tree(int *tree_data, size_t tree_data_len);

void insert_node(node_t *tree, int item);

void free_tree(node_t *tree);

int count_tree_len(node_t *tree, int len);

int sort_data(node_t *tree, int *sorted_array, int counter);

int *sorted_data(node_t *tree);

void print_data(node_t *node);

#endif

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

node_t *find_node(node_t *tree, int item);

void insert_item(node_t *node, int item);

void free_tree(node_t *tree);

int *sorted_data(node_t *tree);

#endif

#include "linked_list.h"

struct list_node
{
   struct list_node *prev;
   ll_data_t data;
   struct list_node *next;
};

struct list
{
   struct list_node *first;
   struct list_node *last;
};

struct list *list_create(void)
{
   struct list_node *first = malloc(sizeof(struct list_node));
   struct list_node *last = malloc(sizeof(struct list_node));

   first->prev = NULL;
   first->next = last;

   last->prev = first;
   last->next = NULL;

   struct list *list = malloc(sizeof(struct list));
   list->first = first;
   list->last = last;

   return list;
}

void list_push(struct list *list, ll_data_t value)
{
   // find last non empty node in order
   struct list_node *second_last;
   second_last = (list->first->next == list->last) ? list->first : list->last->prev;

   // initialize new_node
   struct list_node *new_node = malloc(sizeof(struct list_node));

   new_node->data = value;
   new_node->prev = second_last;
   new_node->next = list->last;

   second_last->next = new_node;
   list->last->prev = new_node;
}

ll_data_t list_pop(struct list *list)
{
   // select second last list
   struct list_node *second_last = list->last->prev;
   int data = second_last->data;

   // reorder pointers
   list->last = list->last->prev;
   list->last->data = (long int)NULL;
   list->last->next = NULL;

   return data;
}

void list_destroy(struct list *list)
{
   free(list);
}

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
   struct list *list = malloc(2 * sizeof(struct list_node));
   struct list_node f = {
       .prev = NULL,
   };

   struct list_node l = {
       .prev = &f,
       .next = NULL,
   };

   f.next = &l;

   list->first = &f;
   list->last = &l;

   return list;
}

void list_destroy(struct list *list)
{
   free(list);
}

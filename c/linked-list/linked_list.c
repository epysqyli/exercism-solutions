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

ll_data_t list_shift(struct list *list)
{
   // select second node
   ll_data_t data = list->first->next->data;

   // reorder pointers
   list->first->next = list->first->next->next;
   list->first->next->prev = list->first;

   return data;
}

void list_unshift(struct list *list, ll_data_t value)
{
   // find second node in list
   struct list_node *second = list->first->next;

   // initialize new node
   struct list_node *new_node = malloc(sizeof(struct list_node));
   new_node->data = value;
   new_node->prev = list->first;
   new_node->next = second;

   // reorder pointers
   list->first->next = new_node;
   second->prev = new_node;
}

size_t list_count(const struct list *list)
{
   size_t count = 0;
   struct list_node *current = list->first;

   while (current->next != list->last)
   {
      count++;
      current = current->next;
   }

   return count;
}

void list_delete(struct list *list, ll_data_t value)
{
   struct list_node *current = list->first->next;
   struct list_node *to_be_deleted = NULL;

   while (!to_be_deleted)
   {
      if (current->data == value)
      {
         to_be_deleted = current;

         struct list_node *prev = to_be_deleted->prev;
         struct list_node *next = to_be_deleted->next;

         prev->next = next;
         next->prev = prev;

         break;
      }
      current = current->next;
   }
}

void list_destroy(struct list *list)
{
   free(list);
}

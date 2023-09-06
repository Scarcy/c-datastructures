#include "../linkedlist/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  LinkedList *list = linkedlist_create();
  linkedlist_append(list, 5);
  linkedlist_append(list, 5);
  linkedlist_append(list, 10);
  linkedlist_append(list, 15);
  linkedlist_append(list, 20);
  linkedlist_append(list, 25);
  linkedlist_append(list, 30);
  linkedlist_print(list);
  printf("- - - - - - - - -\n");
  printf("Value of head: %d\n", list->head->data);
  printf("- - - - - - - - -\n");
  linkedlist_prepend(list, 1);
  printf("New first Value: %d\n", list->head->data);
  linkedlist_print(list);
  int *count;
  int *allFives = linkedlist_find_all_count(list, 5, count);
  printf("- - - - - - - - -\n");
  printf("Count of 5s (Should be 2): %d\n", *count);
  for (int i = 0; i < *count; i++) {
    printf("Index of 5: %d\n", allFives[i]);
  }

  printf("- - - - - - - - -\n");
  printf("Removing range 3-5 (Expected: 10 and 15 removed)\n");
  linkedlist_remove_range(list, 3, 5);
  linkedlist_print(list);
  printf("- - - - - - - - -\n");
  printf("Reversing list\n");
  printf("Pre-Reverse: ");
  linkedlist_print(list);
  linkedlist_reverse(list);
  printf("Post-Reverse: ");
  linkedlist_print(list);

  printf("- - - - - - - - -\n");
  printf("Removing 2nd index (Expected: 20 removed)\n");
  linkedlist_remove_index(list, 2);
  linkedlist_print(list);

  printf("- - - - - - - - -\n");
  printf("Checking if LinkedList size is correctly updated this far (Expected "
         "5)\n");
  printf("Size: %d\n", list->size);
  printf("- - - - - - - - -\n");
  printf("Converting to array\n");
  int *arr = linkedlist_to_array(list);
  for (int i = 0; i < list->size; i++) {
    printf("arr[%d] =  %d\n", i, arr[i]);
  }
}

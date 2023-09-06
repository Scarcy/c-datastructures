#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct Node{
  int data;
  struct Node* next;
} Node;

typedef struct LinkedList{
  Node* head;
  int size;
} LinkedList;
LinkedList* linkedlist_create();
Node* create_node(int data);
void linkedlist_append(LinkedList* list, int data);
void linkedlist_prepend(LinkedList* list, int data);
void linkedlist_remove_index(LinkedList* list, int index);
void linkedlist_remove_range(LinkedList* list, int startIndex, int stopIndex);
int linkedlist_get(LinkedList* list, int index);
int linkedlist_find_first(LinkedList* list, int data);
int* linkedlist_find_all(LinkedList* list, int data);
int* linkedlist_find_all_count(LinkedList* list, int data, int* count);
void linkedlist_reverse(LinkedList* list);
int* linkedlist_to_array(LinkedList* list);
void linkedlist_print(LinkedList* list);
#endif

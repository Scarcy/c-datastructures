#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

LinkedList *linkedlist_create() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (!list) {
    printf("Memory Allocation of Linked List failed");
    return NULL;
  }

  list->head = NULL;
  list->size = 0;
  return list;
}

void linkedlist_append(LinkedList *list, int new_data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    int listSizeAtFailure = list->size;
    fprintf(
        stderr,
        "Error: unable to create node. Memory Allocation for node creation.\n\
    LinkedList size at failure: %d",
        listSizeAtFailure);
    exit(EXIT_FAILURE);
  }

  new_node->data = new_data;
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->size += 1;
  } else {
    Node *temp =
        list->head; // Creates a pointer to the first Node in the Linked List

    while (temp->next !=
           NULL) { // Traverses the LinkedList until it hits the last Node
      temp = temp->next;
    }
    if (temp->next == NULL) { // Not neccesary, but makes the code clearer
      temp->next = new_node;  // The prev last Node now points to the new Node
      list->size += 1;
    }
  }
}

void linkedlist_prepend(LinkedList *list, int new_data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    int listSizeAtFailure = list->size;
    fprintf(
        stderr,
        "Error: unable to create node. Memory Allocation for node creation.\n\
         LinkedList size at failure: %d\n",
        listSizeAtFailure);
    exit(EXIT_FAILURE);
  }
  new_node->data = new_data;

  if (list->head == NULL) {
    list->head = new_node;
    list->size += 1;
  } else {
    new_node->next = list->head;
    list->head = new_node;
    list->size += 1;
  }
}

void linkedlist_remove_index(LinkedList *list, int index) {
  if (list->head == NULL) {
    printf("LinkedList is empty, nothing to remove");
    return;
  }
  if (list->size < index) {
    printf(
        "Out of Bounds: LinkedList contains less elements than index argument\n\
        LinkedList Size: %d\n Index argument: %d\n",
        list->size, index);
  }

  Node *temp = list->head;
  for (int i = 0; i < index - 1; i++) {
    temp = temp->next;
  }
  // The loop stops at the element before the Node that we want to remove.
  // Therefore temp->next is the Node at the param index
  Node *node_to_remove = temp->next;

  temp->next = node_to_remove->next; // The (index-1) node now points to the
                                     // element after the removed node

  free(node_to_remove);
  list->size -= 1;
}

int linkedlist_get(LinkedList *list, int index) {
  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty, nothing to get");
    exit(EXIT_FAILURE);
  } else if (list->size <= index) {
    fprintf(stderr, "Index argument is larger than List Size");
    exit(EXIT_FAILURE);
  }
  Node *temp = list->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->data;
}

int linkedlist_find_first(LinkedList *list, int data) {

  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty, nothing to find");
    return -1;
  }

  Node *temp = list->head;
  int index = 0;
  while (temp != NULL) {
    if (temp->data == data)
      return index;

    temp = temp->next;
    index++;
  }
  printf("Warning: Data not found, returning default -1\n");
  return -1;
}

void linkedlist_reverse(LinkedList *list) {
  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty");
    return;
  }

  Node *prev = NULL, *current = list->head, *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  list->head = prev;
}

int *linkedlist_to_array(LinkedList *list) {
  if (list->head == NULL) {
    fprintf(stderr, "The LinkedList is empty");
    return NULL;
  }
  int *array = (int *)malloc(list->size * sizeof(int));
  if (!array) {
    fprintf(stderr, "error: Memory allocation for Array failed");
  }
  Node *temp = list->head;
  int i = 0;
  while (temp != NULL) {
    array[i] = temp->data;
    i++;
    temp = temp->next;
  }

  return array;
}

void linkedlist_print(LinkedList *list) {
  if (list->head == NULL) {
    printf("{}\n");
    return;
  }
  if (list->head != NULL && list->head->next == NULL) {
    printf("{%d}\n", list->head->data);
    return;
  }
  Node *temp = list->head;
  printf("{");
  while (temp->next != NULL) {
    printf("%d,", temp->data);
    temp = temp->next;
  }
  printf("%d}\n", temp->data);
}

int *linkedlist_find_all(LinkedList *list, int data) {
  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty");
    return NULL;
  }

  int *array_of_finds = (int *)malloc(1 * sizeof(int));
  Node *temp = list->head;
  int index = 0, finds = 0;
  while (temp != NULL) {
    if (temp->data == data) {
      array_of_finds = realloc(array_of_finds, (finds + 1) * sizeof(int));
      array_of_finds[finds] = index;
      finds++;
      if (!array_of_finds) {
        fprintf(stderr, "error: Memory reallocation failed at: %d finds",
                finds);
        free(array_of_finds);
        return NULL;
      }
    }
    temp = temp->next;
    index++;
  }
  return array_of_finds;
}
int *linkedlist_find_all_count(LinkedList *list, int data, int *count) {
  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty");
    return NULL;
  }

  int *array_of_finds = (int *)malloc(1 * sizeof(int));
  Node *temp = list->head;
  int index = 0, finds = 0;
  while (temp != NULL) {
    if (temp->data == data) {
      array_of_finds = realloc(array_of_finds, (finds + 1) * sizeof(int));
      array_of_finds[finds] = index;
      finds++;
      if (!array_of_finds) {
        fprintf(stderr, "error: Memory reallocation failed at: %d finds",
                finds);
        free(array_of_finds);
        return NULL;
      }
    }
    temp = temp->next;
    index++;
  }
  *count = finds;
  return array_of_finds;
}

void linkedlist_remove_range(LinkedList *list, int startIndex, int stopIndex) {
  if (list->head == NULL) {
    fprintf(stderr, "LinkedList is empty");
    return;
  }

  if (startIndex < 0 || stopIndex >= list->size || startIndex > stopIndex) {
    fprintf(stderr, "Invalid indices");
    return;
  }
  int delete_amount = stopIndex - startIndex;
  Node *current = list->head;
  Node *prevNode = NULL;
  for (int i = 0; i < startIndex; i++) {
    prevNode = current;
    current = current->next;
  }
  Node *nextNode = NULL;
  for (int i = 0; i < delete_amount; i++) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  if (prevNode != NULL) {
    prevNode->next = nextNode;
  } else {
    list->head = nextNode;
  }
  list->size -= delete_amount;
}

// list.c
// Implementation for linked list.
// Rijan Khatri

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

list_t *list_alloc() { 
  list_t* new_list =  (list_t *) malloc(sizeof(list_t)); 
  new_list->head = NULL;
  return new_list;
}

void list_free(list_t *linked_list) {
  node_t *current_node = linked_list->head;
  node_t *next_node;
  while(current_node != NULL){
    next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(linked_list);
}

node_t * create_new_node(elem value) {
  node_t *new_node;

  new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}


void list_print(list_t *linked_list) {
  node_t* current_node = linked_list->head;
  while (current_node != NULL) {
    printf("%d ", current_node->value);
    current_node = current_node->next;
  }
  printf("\n");
}

char *listToString(list_t *linked_list) {
  char *buffer = (char *) malloc(sizeof(char) * 10024);
  char temp_buffer[20];

  node_t *current_node = linked_list->head;
  while (current_node != NULL) {
    sprintf(temp_buffer, "%d->", current_node->value);
    strcat(buffer, temp_buffer);
    current_node = current_node->next;
  }
  strcat(buffer, "NULL");

  return buffer;
}

int list_length(list_t *linked_list) {
  int length = 0;
  node_t *current_node = linked_list->head;
  while(current_node != NULL){
    length++;
    current_node = current_node->next;
  }
  return length;
}

void list_add_to_back(list_t *linked_list, elem value) {
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node ->value = value;
  new_node -> next = NULL;

  if(linked_list->head == NULL){
    linked_list->head = new_node;
  }else{
    node_t *current_node = linked_list->head;
    while (current_node ->next != NULL){
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

}
void list_add_to_front(list_t *linked_list, elem value) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = linked_list->head;
  linked_list->head = new_node;
}

void list_add_at_index(list_t *linked_list, elem value, int index) {

  if (index < 1 || index > list_length(linked_list)) {
    return;
  };

  if (index == 1) {
    list_add_to_front(linked_list, value);
    return;
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  node_t *current_node = linked_list->head;
  int i = 1;

  while (i < index - 1) {
    if (current_node == NULL) {
      free(new_node);
      return;
    }
    current_node = current_node->next;
    i += 1;
  }
  if (current_node == NULL) {
    free(new_node);
    return;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
}

elem list_remove_from_back(list_t *linked_list) { 
  
  if (linked_list == NULL || linked_list->head == NULL) {
    return -1;
  };

  node_t *current_node = linked_list->head;
  if (current_node->next == NULL) {
    elem val = current_node->value;
    free(current_node);
    linked_list->head = NULL;
    return val;
  };

  while (current_node->next->next != NULL) {
    current_node = current_node->next;
  };

  elem val = current_node->next->value;
  free(current_node->next);
  current_node->next = NULL;
  return val;
}

elem list_remove_from_front(list_t *linked_list) {
  if (linked_list == NULL || linked_list->head == NULL) {
    return -1;
  }
  
  node_t *current_node = linked_list->head;
  elem val = current_node->value;
  linked_list->head = current_node->next;
  free(current_node);

  return val;
}

elem list_remove_at_index(list_t *linked_list, int index) { 
  if (linked_list->head == NULL) {
    return -1;
  }

  if (index == 1) {
    return list_remove_from_front(linked_list);
  }

  node_t *current_node = linked_list->head;
  int i = 1;

  while (current_node != NULL && i != index - 1) {
    current_node = current_node->next;
    i += 1;
  }

  if (current_node == NULL || current_node->next == NULL) {
    return -1;
  }

  node_t *next_node = current_node->next;
  elem val = next_node->value;
  current_node->next = next_node->next;
  free(next_node);

  return val;
}

bool list_is_in(list_t *linked_list, elem value) {
  node_t *current_node =linked_list->head;
  while (current_node !=NULL){
    if (current_node->value == value) return true;
    current_node = current_node->next;
  }
  return false;
}

elem list_get_elem_at(list_t *linked_list, int index) { 
  node_t *current_node;
  current_node = linked_list->head;
  int i = 1;

  while (current_node != NULL && i != index) {
    current_node = current_node->next;
    i += 1;
  };

  if (current_node == NULL) {
    return -1;
  }

  return current_node->value;
}

int list_get_index_of(list_t *linked_list, elem value) { 
  node_t *current_node;
  current_node = linked_list->head;
  int i = 1;

  while (current_node != NULL) {
    if (current_node->value == value) {
      return i;
    }
    current_node = current_node->next;
    i += 1;
  }
  return -1;
}

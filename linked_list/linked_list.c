/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the
 * license.
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// List implementation
void init_list(linked_list *p_list, DataType type) {
  p_list->front = NULL;
  p_list->size = 0;
  p_list->type = type;
}

void insert(void *value, linked_list *p_list) {

  ++p_list->size;

  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    printf("Failed to allocate memory.\n");
    return;
  }
  temp->value = value;
  temp->prev = NULL;

  // First element in list
  if (p_list->front == NULL) {
    p_list->front = temp;
    return;
  }

  // Add value to the right position
  Node *tmp_ptr = p_list->front;
  Node *prev_node = NULL;

  while (tmp_ptr != NULL) {
    prev_node = tmp_ptr;
    tmp_ptr = tmp_ptr->prev;
  }

  temp->prev = tmp_ptr;
  prev_node->prev = temp;

  return;
}

void *get(int idx, linked_list *p_list) {
  Node *tmp_ptr = p_list->front;
  for (int i = 0; i < idx; ++i) {
    if (tmp_ptr == NULL)
      return NULL;
    tmp_ptr = tmp_ptr->prev;
  }

  return tmp_ptr->value;
}

int contains(void *value, linked_list *p_list) {
  CompareFunc compare = get_compare_func(p_list->type);
  Node *ptr = p_list->front;
  int idx = 0;
  while (idx <= p_list->size) {
    if (compare(ptr->value, value) == 0)
      return idx;
    ptr = ptr->prev;
    ++idx;
  }
  return -1;
}

void remove_item(int idx, linked_list *p_list) {
  Node *tmp_ptr = p_list->front;
  Node *prev_node = NULL;
  for (int i = 0; i < idx; ++i) {
    if (tmp_ptr == NULL)
      return;
    prev_node = tmp_ptr;
    tmp_ptr = tmp_ptr->prev;
  }

  prev_node->prev = tmp_ptr->prev;

  free(tmp_ptr);

  --p_list->size;

  return;
}

bool is_empty(linked_list *p_list) {
  if (p_list->front == NULL)
    return true;
  return false;
}

int size(linked_list *p_list) { return p_list->size; }

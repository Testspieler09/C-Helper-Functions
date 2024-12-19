/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the
 * license.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "void_comparisons.h"
#include <stdbool.h>

typedef struct Node {
  void *value;
  struct Node *prev;
} Node;

typedef struct linked_list {
  Node *front;
  int size;      // For speed we safe the size
  DataType type; // For comparing the values of the void pointers
} linked_list;

// MACROS
#define create_linked_list(LIST_NAME, TYPE)                                    \
  linked_list LIST_NAME;                                                       \
  init_list(&LIST_NAME, TYPE);

/*
 * Use for linked_list
 * void *item;
 * for_each_item_##(item, &my_list) {
 *   printf("%d\n", *(int *)item);
 *}
 */
#define for_each_item(item, list)                                              \
  for (int _i = 0; _i < (list)->size && ((item) = get(_i, (list))) != NULL;    \
       ++_i)

/*
 * Init an empty list for the user to add items to
 * @param p_list A pointer to the linked list
 * @param type The datatype of the linked list in form of the enum
 */
void init_list(linked_list *p_list, DataType type);

/*
 * Check if a value is contained in the linked_list
 * @param value The value to check for
 * @param p_list The linked list the function is supposed to check in
 * @return The index of the element if contained else -1
 */
int contains(void *value, linked_list *p_list);

/*
 * Get the void pointer to a specific index
 * @param idx The index of the value you want to get
 * @param p_list The linked list the function is supposed to search in
 * @return A void pointer to the value
 */
void *get(int idx, linked_list *p_list);

/*
 * Insert an element into the linked list
 * @param value The value that should be inserted
 * @param p_list The linked list the element is supposed to be inserted to
 */
void insert(void *value, linked_list *p_list);

/*
 * Check if the linked list is empty
 * @param p_list The linked list that is supposed to be checked
 * @return 1 if it is empty otherwise 0
 */
bool is_empty(linked_list *p_list);

/*
 * Remove an item from the linked list
 * @param idx The index of the value you want to remove
 */
void remove_item(int idx, linked_list *p_list);

/*
 * Get the size of the list in O(1)
 * @param p_list The linked list you want to get the size of
 * @retrun The size of the list as an int
 */
int size(linked_list *p_list);

#endif // !LINKED_LIST_H

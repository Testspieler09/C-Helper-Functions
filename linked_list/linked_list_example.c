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

int main() {
  // Create the list with `name` as the first parameter and `type` as the second
  // one
  create_linked_list(example_list, STRING);

  // Insert the values
  char *values[] = {"Hello", "World", "!"};
  for (int i = 0; i < 3; ++i) {
    insert(values[i], &example_list);
  }

  // All other methods
  printf("List contains `Hello`: %d\n", contains("Hello", &example_list));
  printf("Second element of the list is: %s\n", (char *)get(1, &example_list));
  printf("The list is empty: %d\n", is_empty(&example_list));
  remove_item(1, &example_list);
  printf("The size of the list is: %d\n", size(&example_list));

  printf("\n\n");

  // Print the values
  void *word;
  for_each_item(word, &example_list) { printf("%s\n", (char *)word); }

  return 0;
}

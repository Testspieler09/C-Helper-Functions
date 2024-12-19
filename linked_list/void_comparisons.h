/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the
 * license.
 */

#ifndef LINKED_LIST_UTILS_H
#define LINKED_LIST_UTILS_H

typedef enum {
  CHAR,
  U_CHAR,
  SHORT,
  U_SHORT,
  INT,
  U_INT,
  LONG,
  U_LONG,
  LONG_LONG,
  U_LONG_LONG,
  FLOAT,
  DOUBLE,
  LONG_DOUBLE,
  STRING,
  UNKNOWN
} DataType;

typedef int (*CompareFunc)(void *a, void *b);

typedef struct {
  DataType type;
  CompareFunc compare;
} CompareMap;

int char_compare(void *a, void *b);
int u_char_compare(void *a, void *b);
int short_compare(void *a, void *b);
int u_short_compare(void *a, void *b);
int int_compare(void *a, void *b);
int u_int_compare(void *a, void *b);
int long_compare(void *a, void *b);
int u_long_compare(void *a, void *b);
int long_long_compare(void *a, void *b);
int u_long_long_compare(void *a, void *b);
int float_compare(void *a, void *b);
int double_compare(void *a, void *b);
int long_double_compare(void *a, void *b);
int string_compare(void *a, void *b);
int default_compare(void *a, void *b);
CompareFunc get_compare_func(DataType type);

extern CompareMap COMPARE_MAP[15];

#endif // !LINKED_LIST_UTILS_H

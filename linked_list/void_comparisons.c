/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the
 * license.
 */

#include "void_comparisons.h"
#include <string.h>

// Define the compare_functions
CompareMap COMPARE_MAP[15] = {{CHAR, char_compare},
                              {U_CHAR, u_char_compare},
                              {SHORT, short_compare},
                              {U_SHORT, u_short_compare},
                              {INT, int_compare},
                              {U_INT, u_int_compare},
                              {LONG, long_compare},
                              {U_LONG, u_long_compare},
                              {LONG_LONG, long_long_compare},
                              {U_LONG_LONG, u_long_long_compare},
                              {FLOAT, float_compare},
                              {DOUBLE, double_compare},
                              {LONG_DOUBLE, long_double_compare},
                              {STRING, string_compare},
                              {UNKNOWN, default_compare}};

int char_compare(void *a, void *b) {
  if (*(char *)a == *(char *)b) {
    return 0;
  } else if (*(char *)a < *(char *)b) {
    return -1;
  } else {
    return 1;
  }
}

int u_char_compare(void *a, void *b) {
  if (*(unsigned char *)a == *(unsigned char *)b) {
    return 0;
  } else if (*(unsigned char *)a < *(unsigned char *)b) {
    return -1;
  } else {
    return 1;
  }
}

int short_compare(void *a, void *b) {
  if (*(short *)a == *(short *)b) {
    return 0;
  } else if (*(short *)a < *(short *)b) {
    return -1;
  } else {
    return 1;
  }
}

int u_short_compare(void *a, void *b) {
  if (*(unsigned short *)a == *(unsigned short *)b) {
    return 0;
  } else if (*(unsigned short *)a < *(unsigned short *)b) {
    return -1;
  } else {
    return 1;
  }
}

int int_compare(void *a, void *b) {
  if (*(int *)a == *(int *)b) {
    return 0;
  } else if (*(int *)a < *(int *)b) {
    return -1;
  } else {
    return 1;
  }
}

int u_int_compare(void *a, void *b) {
  if (*(unsigned int *)a == *(unsigned int *)b) {
    return 0;
  } else if (*(unsigned int *)a < *(unsigned int *)b) {
    return -1;
  } else {
    return 1;
  }
}

int long_compare(void *a, void *b) {
  if (*(long *)a == *(long *)b) {
    return 0;
  } else if (*(long *)a < *(long *)b) {
    return -1;
  } else {
    return 1;
  }
}

int u_long_compare(void *a, void *b) {
  if (*(unsigned long *)a == *(unsigned long *)b) {
    return 0;
  } else if (*(unsigned long *)a < *(unsigned long *)b) {
    return -1;
  } else {
    return 1;
  }
}

int long_long_compare(void *a, void *b) {
  if (*(long long *)a == *(long long *)b) {
    return 0;
  } else if (*(long long *)a < *(long long *)b) {
    return -1;
  } else {
    return 1;
  }
}

int u_long_long_compare(void *a, void *b) {
  if (*(unsigned long long *)a == *(unsigned long long *)b) {
    return 0;
  } else if (*(unsigned long long *)a < *(unsigned long long *)b) {
    return -1;
  } else {
    return 1;
  }
}

int float_compare(void *a, void *b) {
  if (*(float *)a == *(float *)b) {
    return 0;
  } else if (*(float *)a < *(float *)b) {
    return -1;
  } else {
    return 1;
  }
}

int double_compare(void *a, void *b) {
  if (*(double *)a == *(double *)b) {
    return 0;
  } else if (*(double *)a < *(double *)b) {
    return -1;
  } else {
    return 1;
  }
}

int long_double_compare(void *a, void *b) {
  if (*(long double *)a == *(long double *)b) {
    return 0;
  } else if (*(long double *)a < *(long double *)b) {
    return -1;
  } else {
    return 1;
  }
}

int string_compare(void *a, void *b) { return strcmp((char *)a, (char *)b); }

int default_compare(void *a, void *b) { return !(a == b); }

CompareFunc get_compare_func(DataType type) {
  for (int i = 0; i < (int)(sizeof(COMPARE_MAP) / sizeof(CompareMap)); ++i) {
    if (COMPARE_MAP[i].type == type) {
      return COMPARE_MAP[i].compare;
    }
  }
  return default_compare;
}

#pragma once
#include <stdlib.h>
#include <string.h>
typedef struct String{
  char* str;
  size_t size;
  size_t index;
}String;

void resize(String *string);
void init_string_default(String *string, size_t str_size);
String* make_str_ptr_default(size_t str_size);
void append_char(String *string, char c);
void append_str(String *front, String *back);
void free_str_ptr(String *string);
void right_shift(String *string, size_t end_of_buffer);

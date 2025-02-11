#pragma once
#include "String.h"
#define DEFAULT_STRING_SIZE 50
#define DEFAULT_GAP_SIZE 10

typedef struct Buffer{
  String string;
  size_t left;
  size_t right;
  size_t buff_size;
}Buffer;

void reset_buffer(Buffer *buff);
void set_buffer(Buffer *buff, size_t index);
void write_buffer(Buffer *buff, char c);

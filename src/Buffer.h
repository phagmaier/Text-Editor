#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define DEFAULT_BUFF_SIZE 50

typedef struct Buffer{
  char *str;
  size_t buff_size;
  size_t gap_size;
  size_t left;
  size_t right;
}Buffer;

void init_GB(Buffer *buff, size_t size);

void exapnd_buff(Buffer *buff);

void move_cursor_left(Buffer *buff, size_t new_l);

void move_cursor_right(Buffer *buff, size_t new_l);

void print_buff(Buffer *buff);

void print_buff_and_gap(Buffer *buff);

void print_buffer_info(Buffer *buffer);

Buffer* create_example_buff(const char* string);

void write_char(Buffer *buff, char c);

void delete_char(Buffer *buff);

size_t get_min(size_t a, size_t b);

size_t get_max(size_t a, size_t b);

void free_buffer(Buffer *buff);


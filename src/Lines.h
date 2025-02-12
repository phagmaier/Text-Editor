#pragma once
#include "Buffer.h"

typedef struct Lines{
  Buffer *lines;
  size_t total;
  size_t used;
}Lines;

void init_default_lines(Lines *lines, size_t num_lines);

void expand_lines(Lines *lines);

void free_lines(Lines *lines);

void delete_line(Lines *lines, size_t index);



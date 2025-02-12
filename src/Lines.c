#include "Lines.h"

void init_default_lines(Lines *lines, size_t num_lines){
  lines->lines = (Buffer*)calloc(num_lines,sizeof(Buffer));
  for (size_t i=0;i<num_lines;++i){
    init_GB(&lines->lines[i],DEFAULT_BUFF_SIZE);
  }
  lines->total = num_lines;
  lines->used = 0;
}

void free_lines(Lines *lines){
  for (size_t i=0;i<lines->total;++i){
    free_buffer(&lines->lines[i]);
  }
  lines->total = 0;
  lines->used = 0;
}

void expand_lines(Lines *lines){
  lines->lines = (Buffer*)realloc(lines->lines,(lines->total*2) * sizeof(Buffer));
  memset(&lines->lines[lines->total], 0, lines->total* sizeof(Buffer));
  lines->total *= 2;
}



void delete_line(Lines *lines, size_t index) {
  if (index >= lines->used) {
    return;
  } 
  free_buffer(&lines->lines[index]);

  if (index < lines->used - 1) {
    memmove(&lines->lines[index], &lines->lines[index + 1], 
            (lines->used - index - 1) * sizeof(Buffer));
  }
  --lines->used;
  memset(&lines->lines[lines->used], 0, sizeof(Buffer));
}


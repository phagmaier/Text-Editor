#include "String.h"

void init_string_default(String *string, size_t str_size){
  string->str = (char*)calloc(str_size,1);
  string->size = str_size;
  string->index=0;
}

String* make_str_ptr_default(size_t str_size){
  String *str = (String*)malloc(sizeof(String));
  init_string_default(str,str_size);
  return str;
}


void resize(String *string){
  string->str = realloc(string->str, (string->size+1) *2);
  string->size*=2;
}

void append_char(String *string, char c){
  if (string->index==string->size){
    resize(string);
  }
  string->str[string->index++] = c;
  string->str[string->index]=0;
}

void append_str(String *front, String *back){
  size_t total = front->index + back->index  +1;
  if (total < front->size){
    front->str = (char *)realloc(front->str, total);
  }
  memcpy(front->str+(front->index), back->str, back->index+1);
}

void free_str_ptr(String *string){
  if (string){
    free (string->str);
    free(string);
  }
}


void right_shift(String *string, size_t end_of_buffer) {
  if (string->index +1 >=string->size){
    resize(string);
  }

  for(size_t i = string->index; i>end_of_buffer;--i){
    string->str[i+1] = string->str[i];
    //printf("%c",string->str[i]);
  }
  //printf("\n");

}



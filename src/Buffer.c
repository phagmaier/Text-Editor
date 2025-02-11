#include "Buffer.h"

//string actually does not need to be null terminated
//will still have null characters to indicate the 
//end of the string and when to stop outputting characters
//but don't actually need to have additional space for one
void init_GB(Buffer *buff, size_t size){
  buff->str = (char*)calloc(size,1);
  buff->buff_size=DEFAULT_BUFF_SIZE;
  buff->left = 0;
  buff->right = size-1;
}

void expand_buff(Buffer *buff){
  size_t new_size = (buff->buff_size)*2;
  char* new_str = (char*)calloc(new_size,1);
  memcpy(new_str,buff->str,buff->buff_size);
  free(buff->str);
  buff->str=new_str;
  buff->buff_size = new_size;
  buff->gap_size = new_size - buff->left;
  buff->right = new_size-1;
}



void move_cursor_left(Buffer *buff, size_t new_l) {
  if (buff->gap_size == buff->buff_size || buff->left == 0 || new_l >= buff->left) {
    return;
  }

  size_t shift_size = buff->left - new_l;

  memmove(buff->str + buff->right - shift_size + 1, 
          buff->str + new_l, 
          shift_size);

  buff->left = new_l;
  buff->right = buff->gap_size + buff->left - 1;
}

/*
void move_cursor_left(Buffer *buff, size_t new_l) {
    if (buff->gap_size == buff->buff_size || buff->left == 0 || new_l >= buff->left) {
        return;
    }

    size_t shift_size = buff->left - new_l;

    // Move characters to the right to shift the gap left
    memmove(buff->str + buff->right - shift_size + 1, 
            buff->str + new_l, 
            shift_size);

    // Update left and right boundaries
    buff->left = new_l;
    buff->right = buff->gap_size + buff->left - 1;
}
*/

//this is wrong for a lot of reasons
//Also need to make sure we aren't moving too far right
//limit is the BUFF_SIZE - GAP_SIZE that's how much free space we have
//don't want to move more right that that no point
void move_cursor_right(Buffer *buff, size_t new_l){
  size_t shift_size = new_l - buff->left;
  if (buff->gap_size == buff->buff_size || buff->right == buff->buff_size-1 || shift_size==0) {
    return;
  }
  memmove(buff->str + buff->gap_size + shift_size, buff->str + buff->gap_size, buff->left - new_l);
  buff->left = new_l;
}

void print_buff(Buffer *buff){
  char *c = buff->str;
  for (size_t i=0;i<buff->buff_size;++i){
    if(i<buff->left || i>buff->right){
      /*
      if (buff->str[i] == 0){
        putchar('\n');
        return;
      }
      */
      putchar(buff->str[i]);
    }
    
  }
  putchar('\n');
}

void print_buff_and_gap(Buffer *buff){
  char *c = buff->str;
  for (size_t i=0;i<buff->buff_size;++i){
    if(i<buff->left || i>buff->right){
      putchar(buff->str[i]);
    }
    else{
      putchar('_');
    }
  }
  putchar('\n');

}

void print_buffer_info(Buffer *buffer){
  printf("TOTAL SIZE: %zu LEFT: %zu RIGHT: %zu GAP SIZE: %zu\n",buffer->buff_size, buffer->left,buffer->right,buffer->gap_size);
}


Buffer* create_example_buff(const char* string){
  size_t length = strlen(string);
  Buffer *buff = (Buffer*)malloc(sizeof(Buffer));
  buff->buff_size = length+10; //ten extra characters
  buff->str = (char*)calloc(buff->buff_size,1);
  strncpy(buff->str,string,length);
  buff->left=length;
  buff->right=buff->buff_size-1;
  buff->gap_size=10;
  return buff;
}



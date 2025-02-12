#include "Buffer.h"

size_t get_min(size_t a, size_t b){
  if (a > b){
    return b;
  }
  return a;
}
size_t get_max(size_t a, size_t b){
  if (a > b){
    return a;
  }
  return b;

}

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


//need to make sure you don't move too far right
//buff_size - gap size is the limit
void move_cursor_right(Buffer *buff, size_t new_l){
  new_l = get_min(new_l,(buff->buff_size - buff->gap_size));
  size_t shift_size = new_l - buff->left;
  if (buff->gap_size == buff->buff_size || buff->right == buff->buff_size-1 || shift_size==0) {
    return;
  }
  memmove(buff->str + buff->left,
            buff->str+ buff->right+ 1,
            shift_size);
  buff->left = new_l;
  buff->right = new_l + buff->gap_size-1;
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

void delete_char(Buffer *buff){
  if (buff->left){
    --buff->left;
    ++buff->gap_size;
  }
}

void write_char(Buffer *buff, char c){
  if(!buff->gap_size || buff->left==buff->buff_size-1){
    expand_buff(buff);
  } 
  buff->str[buff->left] = c;
  --buff->gap_size;
  ++buff->left;
}

void free_buffer(Buffer *buff){
  if (buff->str){
    free(buff->str);
  } 

  buff->str = NULL;
  buff->buff_size=0;
  buff->gap_size=0;
  buff->left=0;
  buff->right=0;
}

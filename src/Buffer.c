#include "Buffer.h"

void reset_buffer(Buffer *buff){
  memset(buff+buff->left, 0, buff->buff_size);
}
void set_buffer(Buffer *buff, size_t index){
  if (index <=0){
    buff->left = 0;
  }
  if (index >= buff->string.size){
    buff->left = buff->string.size-1;
    buff->right = buff->string.size-1;
    return;
  }
  buff->right = index + buff->buff_size;
  if (buff->right >= buff->string.size){
    buff->right = buff->string.size-1; 
  }
}

void write_buffer(Buffer *buff, char c){
  right_shift(&buff->string, buff->right+1);
  buff->string.str[buff->right+1] = buff->string.str[buff->left];
  buff->string.str[buff->left]=c;
}

//int because if 0 we go to the above line
int back_space_buffer(Buffer *buff){
  if (buff->left){
    --buff->left;
    //case where buffer start so far right buff right
    //not at full capacity
    if (buff->right - buff->left == buff->buff_size){
      --buff->right;
    }

    return 0;
  }
  return 1;
}

#include "Buffer.h"
#include <stdio.h>

int main(){
  Buffer *buffer = create_example_buff("HELLO WORLD");
  printf("----------------------------------------\n");
  printf("STRING BEFORE SHIFTING:\n");
  printf("----------------------------------------\n");
  printf("BUFFER INFO\n");
  print_buffer_info(buffer);
  printf("----------------------------------------\n");
  printf("PRINTING JUST THE ACTUAL BUFFER\n");
  print_buff(buffer);
  printf("PRINTING BUFF AND GAP (GAP DISPLAYED AS '_')\n");
  print_buff_and_gap(buffer);


  move_cursor_left(buffer,2);
  printf("----------------------------------------\n");
  printf("AFTER SHIFTING TO INDEX 2:\n");
  printf("----------------------------------------\n");
  printf("BUFFER INFO\n");
  print_buffer_info(buffer);
  printf("----------------------------------------\n");
  printf("PRINTING JUST THE ACTUAL BUFFER\n");
  print_buff(buffer);
  printf("PRINTING BUFF AND GAP (GAP DISPLAYED AS '_')\n");
  print_buff_and_gap(buffer);
  printf("----------------------------------------\n");


  return 0;
}

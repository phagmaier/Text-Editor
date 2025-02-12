#include "Buffer.h"
#include <stdio.h>
#include <ncurses.h>
#include "Lines.h"
#include <unistd.h>

#define DEFAULT_NUM_LINES 100

void show_buff_info(Buffer *buffer){
  printf("----------------------------------------\n");
  printf("BUFFER INFO\n");
  print_buffer_info(buffer);
  printf("----------------------------------------\n");
  printf("PRINTING JUST THE ACTUAL BUFFER\n");
  print_buff(buffer);
  printf("PRINTING BUFF AND GAP (GAP DISPLAYED AS '_')\n");
  print_buff_and_gap(buffer);
  printf("----------------------------------------\n");
}



void test_strings(){
  Buffer *buffer = create_example_buff("HELLO WORLD");
  move_cursor_left(buffer,2);
  show_buff_info(buffer);
  printf("\n\n");
  move_cursor_right(buffer,7);
  show_buff_info(buffer);
  move_cursor_left(buffer,2);
  show_buff_info(buffer);
  move_cursor_right(buffer,7);
  show_buff_info(buffer);
}

void print_lines(Lines *lines){
  for(size_t i=0;i<lines->total;++i){
    printw("%s\n",lines->lines[i].str);
    //usleep(1000000); 
    usleep(10000); 
    refresh();
  } 
}

int main(){
  //test_strings();
  Lines lines;  
  init_default_lines(&lines, DEFAULT_NUM_LINES);
   
  initscr();
  
  keypad(stdscr, TRUE);
  cbreak();
  
  curs_set(2);
  
  move(0, 0);
  
  
  // Move cursor explicitly after printing
  int y=0; 
  int x=0;
  //getyx(stdscr, y, x);  // Get current cursor position
  //move(y, x);           // Move to that position
  // IMPORTANT: Refresh the screen to see changes
  refresh();
  print_lines(&lines);
  getch();
  
  // Clean up
  endwin();
  return 0;

}

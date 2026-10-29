#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

void fb_write_char(char c);
void fb_write_string(char *str);
void fb_clear(void);
void fb_move(unsigned short x, unsigned short y);
void fb_set_colour(char colour);
void fb_write_int(int num);

#endif
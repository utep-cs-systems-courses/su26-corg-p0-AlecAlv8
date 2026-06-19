#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_5x7(char c)
{
  c -= 0x20;
  for (char col = 0; col < 5; col++) {
    for (char row = 0; row < 7; row++) {
      unsigned short rowBits = font_5x7[c][col];
      unsigned short colMask = 1 << (6-row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

/* The 8x12 font stores each glyph as 12 rows; each row is an 8-bit
   bitmap whose most-significant bit is the left-most column. */
void print_char_8x12(char c)
{
  c -= 0x20;
  for (int row = 0; row < 12; row++) {
    unsigned char colBits = font_8x12[c][row];
    for (int col = 0; col < 8; col++) {
      unsigned char colMask = 1 << (7-col); /* bit 7 is the left-most column */
      putchar( (colBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

// Prints an upward-pointing arrow whose left edge is at col leftCol.
// The arrowhead is a triangle of the given size, and a vertical shaft
// of (2*(size/2)+1) cols extends below it, centered under the tip.
void print_arrow(int leftCol, int size)
{
  // Arrowhead: same raster projection as print_triangle
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }

  // Shaft: a vertical bar centered under the tip of the arrowhead
  int center = leftCol + size;
  int half = size / 2;
  int shaftMin = center - half, shaftMax = center + half;
  for (int row = 0; row < size; row++) {
    int col;
    for (col = 0; col < shaftMin; col++) putchar(' ');
    for (       ; col <= shaftMax; col++) putchar('*');
    putchar('\n');
  }
}


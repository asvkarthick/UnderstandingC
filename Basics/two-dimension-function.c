#include <stdio.h>

#define ROWS 4
#define COLS 5

void func(int array[ROWS][COLS])
{
  int i, j;

  for (i=0; i<ROWS; i++)
  {
    for (j=0; j<COLS; j++)
    {
      array[i][j] = i*j;
    }
  }
}

void func_vla(int rows, int cols, int array[rows][cols])
{
  int i, j;

  for (i=0; i<rows; i++)
  {
    for (j=0; j<cols; j++)
    {
      array[i][j] = i*j;
    }
  }
}

int main()
{
  int x[ROWS][COLS];

  func(x);
  func_vla(x, ROWS, COLS);
}

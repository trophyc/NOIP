#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int rows, cols;
char field[MAX_ROWS][MAX_COLS];
char number[MAX_ROWS][MAX_COLS];

void ReadInUseful (char* c);
void PrintField ();
char CheckAround (int r, int c);
void PrintNumber ();

int main ()
{
   scanf ("%d %d\n", &rows, &cols);
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         char c;
         ReadInUseful (&c);
         field[i][j] = c;
      }
   }

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         number[i][j] = CheckAround(i,j);
      }
   }
   PrintNumber();
   return 0;
}

void ReadInUseful (char* c)
{
   *c = 0;
   while (*c != '*' && *c != '?') {
      scanf ("%c", c);
   }
}

char CheckAround (int r, int c)
{
   if (field[r][c] == '*') {
      return '*';
   }

   char ch = '0';
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (r + i < 0 || c + j  < 0 || r+i >= rows || c+j >= cols || (i == 0 && j == 0)) {
            continue;
         }
         if (field[r+i][c+j] == '*') {
            ch++;
         }
      }
   }
   return ch;
}

void PrintField ()
{
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf ("%c", field[i][j]);
      }
      printf ("\n");
   }
}

void PrintNumber ()
{
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf ("%c", number[i][j]);
      }
      printf ("\n");
   }
}
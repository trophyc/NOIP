#include <stdio.h>

#define MAX_ROWS 16

void EnumerateNext (int total, int select, int* result);
void PrintRows (int* result, int rows);

int main ()
{
   int totalRows, totalCols, rows, cols;

   scanf ("%d %d %d %d", &totalRows, &totalCols, &rows, &cols);
   int selectedRows[MAX_ROWS];
   selectedRows[0] = -1;
   do {
      EnumerateNext (totalRows, rows, selectedRows);
      PrintRows(selectedRows, rows);
   } while (selectedRows[0] != -1);
   return 0;
}

void EnumerateNext (int total, int select, int* result)
{
   if (result[0] == -1) {
      for (int i = 0; i < select; i++) {
         result[i] = i;
      }
      return;
   }

   if (result[0] == total - select) {
      result[0] = -1;
      return;
   }

   int i = 0;
   while (result[select - i - 1] == total -i -1) {
      i++;
   }

   result[select -i -1] ++;
   int a = result[select -i -1];
   i--;
   for (; i >= 0; i--) {
      result[select -i -1] = ++a;
   }
   return;
}

void PrintRows (int* result, int rows)
{
   for (int i = 0; i < rows; i++) {
      printf ("%d ", result[i]);
   }
   printf ("\n");
}
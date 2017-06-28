#include <stdio.h>
#include <limits.h>

#define MAX_ROWS 16
#define MAX_COLS 16

void EnumerateNext (int total, int select, int* result);
int GetMinWith (int* selectedRows, int rows, int totalCols, int cols);
int GetMinHCost (int ith, int col, int* selectedRows, int rows);
void PrintRows (int* result, int rows);
int matrix[MAX_ROWS][MAX_COLS];

int main ()
{
   int totalRows, totalCols, rows, cols;
   int min = INT_MAX;
   scanf ("%d %d %d %d", &totalRows, &totalCols, &rows, &cols);
   for (int i = 0; i < totalRows; i++) {
      for (int j = 0; j < totalCols; j++) {
         scanf ("%d", &matrix[i][j]);
      }
   }

   int selectedRows[MAX_ROWS];
   selectedRows[0] = -1;
   do {
      EnumerateNext (totalRows, rows, selectedRows);
      if (selectedRows[0] != -1) {
         int tmp = GetMinWith (selectedRows, rows, totalCols, cols);
         min = (min < tmp ? min : tmp);
      }
   } while (selectedRows[0] != -1);
   printf ("%d\n", min);
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

/* dp[i][j] stores the min value when col j is selected as the ith selected row
*/

#define ABS(a) ((a) >= 0 ? (a) : -(a))

int dp[MAX_ROWS+1][MAX_COLS]; 
int v_cost[MAX_COLS]; // the vertical values

int GetMinWith (int* selectedRows, int rows, int totalCols, int cols)
{
   for (int j = 0; j < totalCols; j++) {
      v_cost[j] = 0;
      for (int i = 0; i < rows-1; i++) {
         int row = selectedRows[i];
         int nextRow = selectedRows[i+1];
         v_cost[j] += ABS(matrix[row][j] - matrix[nextRow][j]); 
      }
   }

   for (int j = 0; j < totalCols; j++) {
      dp[1][j] = v_cost[j];
   }

   for (int i = 2; i <= cols; i++) {
      for (int j = i - 1; j < totalCols; j++) {
         int hCost = GetMinHCost (i, j, selectedRows, rows);
         dp[i][j] = v_cost[j] + hCost;
      }
   }

   int min = INT_MAX;
   for (int j = cols - 1; j < totalCols; j++) {
      min = (min < dp[cols][j] ? min : dp[cols][j]);
   }
   return min;
}

int GetMinHCost (int ith, int col, int* selectedRows, int rows)
{
   int min = INT_MAX;
   for (int j = ith - 2; j < col; j++) {
      int h = dp[ith - 1][j];      
      for (int i = 0; i < rows; i++) {
         int row = selectedRows[i];
         h += ABS (matrix[row][j] - matrix[row][col]);
      }
      min = (min < h ? min : h);
   }
   return min;
}

void PrintRows (int* result, int rows)
{
   for (int i = 0; i < rows; i++) {
      printf ("%d ", result[i]);
   }
   printf ("\n");
}
#include <stdio.h>
#include <memory.h>

// Not all the types need to be placed!

// int flowers (i, j) returns the number of patterns,
//  that the jth type of flowers starts from position i.
//  0 <= i < m; 0 <= j < n 
int flowers (int position, int types);
#define MAX_POSITION 100
#define MAX_TYPES 100
int n, m;
int limits[MAX_TYPES+1];
int results[MAX_POSITION+1][MAX_TYPES+1];

int main ()
{
   memset (results, -1, sizeof (results));
   scanf ("%d %d", &n, &m);
   for (int i = 0; i < n; i++) {
      scanf ("%d", &limits[i]);
   }

   printf ("%d\n", flowers(0,0));
   return 0;
}

int flowers (int i, int j)
{
   if (results[i][j] != -1) {
      return results[i][j];
   }
   if (j == n-1) {
      if (i >= m - limits[j]) {
         results[i][j] = 1;
         return 1;
      }
      results[i][j] = 0;
      return 0;
   }

   int number = 0;
   for (int k = i; k <= m && k - i <= limits[j]; k++ ) {
      number += flowers (k, j+1);
      number %= 1000007;
   }
   results[i][j] = number;
   return number;
}
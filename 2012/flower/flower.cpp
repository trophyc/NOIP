#include <stdio.h>
#include <memory.h>

#define MAX_FLOWERS 100
#define MAX_TYPES 100

int limits[MAX_TYPES+1];

// dp[i][j]: ending by position j (0 <= j <= m-1),
//  deploys 0-i (0 <= i <= n) types. (so i+1, starting from j+1)
int dp[MAX_TYPES+1][MAX_FLOWERS+1];

int main ()
{
   int n, m;
   scanf ("%d %d", &n, &m); // n types of flowers. m positions.
   for (int i = 1; i <= n; i++) {
      scanf ("%d", &limits[i]);
   }
   memset (dp, 0, sizeof (dp));

   for (int i = 0; i <= limits[1]; i++) {
      dp[1][i] = 1;
   }
   for (int i = 2; i <= n; i++) {
      int sum = 0;
      int toRemove = 0 - limits[i] -1;
      for (int j = 0; j <= m; j++) {
         if (toRemove >= 0 ) {
            sum -= dp[i-1][toRemove];
            sum = (sum >= 0 ? sum : sum + 1000007);
         }
         toRemove ++;
         sum += dp[i-1][j];
         sum %= 1000007;
         dp[i][j] = sum;
      }
   }
   
   printf ("%d\n", dp[n][m]);
   return 0;
}
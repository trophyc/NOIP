#include <stdio.h>
#include <memory.h>

#define MAX_FLOWERS 100
#define MAX_TYPES 100

int limits[MAX_TYPES];

// dp[i][j]: ending by position j (0 <= j <= m-1),
//  deploys 0-i (0 <= i <= n) types. (so i+1, starting from j+1)
int dp[MAX_TYPES][MAX_FLOWERS];

int main ()
{
   int n, m;
   scanf ("%d %d", &n, &m); // n types of flowers. m positions.
   for (int i = 0; i < n; i++) {
      scanf ("%d", &limits[i]);
   }
   memset (dp, 0, sizeof (dp));

   for (int i = 0; i < limits[0]; i++) {
      dp[0][i] = 1;
   }
   for (int i = 1; i < n; i++) {
      int sum = -1;
      for (int j = i; j < m; j++) {
         if (sum == -1) {
            sum = 0;
            int start = (j - limits[i] > 0 ? j - limits[i] : 0);         
            for (int k = start; k < j; k++) {
               sum += dp[i-1][k];
               sum %= 1000007;
            }
         } else {
            int tmp = j - limits[i] -1 ;
            if (tmp >= 0) {
               sum -= dp[i-1][tmp];
            }
            sum += dp[i-1][j-1];
            sum %= 1000007;
         }
         dp[i][j] = sum;
      }
   }
   
   printf ("%d\n", dp[n-1][m-1]);
   return 0;
}
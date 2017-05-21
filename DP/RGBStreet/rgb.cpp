#include <stdio.h>

#define MAX 10000
int dp[MAX][3];

#define min(a,b) ((a)<(b) ? (a) : (b))

int main ()
{
   int n;
   scanf ("%d", &n);
   
   for (int i = 0; i < 3; i++) {
      scanf ("%d", &dp[0][i]);
   }

   for (int i = 1; i < n; i++) {
      int r, g, b;
      scanf ("%d %d %d", &r, &g, &b);
      dp[i][0] = r + min (dp[i-1][1], dp[i-1][2]);
      dp[i][1] = g + min (dp[i-1][0], dp[i-1][2]);
      dp[i][2] = b + min (dp[i-1][0], dp[i-1][1]);
   }

   int minmum = dp[n-1][0];
   minmum = min (minmum, dp[n-1][1]);
   minmum = min (minmum, dp[n-1][2]);
   printf ("%d\n", minmum);
   return 0;
}
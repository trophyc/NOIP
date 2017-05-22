
// 在键盘上可以随便按一个键开始，然后每次按与上次相邻的数字。一共按n次键，一共可以组成多少个数字串？
//    1  2  3
//    4  5  6
//    7  8  9
//    0

#include <stdio.h>

#define KEYS 10
#define MAX 100

// dp[i][j]: 以i键开始按j+1次的总数。
long long dp[KEYS][MAX];

int main ()
{
   int n;
   scanf ("%d", &n);

   for (int i = 0; i < KEYS; i++) {
      dp[i][0] = 1;
   }

   for (int j = 1; j < n; j++) {
      dp[0][j] = dp[7][j-1] + dp[8][j-1];
      dp[1][j] = dp[2][j-1] + dp[5][j-1] + dp[4][j-1];
      dp[2][j] = dp[1][j-1] + dp[3][j-1] + dp[4][j-1] + dp[5][j-1] + dp[6][j-1];
      dp[3][j] = dp[2][j-1] + dp[5][j-1] + dp[6][j-1];
      dp[4][j] = dp[1][j-1] + dp[2][j-1] + dp[5][j-1] + dp[8][j-1] + dp[7][j-1];
      dp[5][j] = dp[1][j-1] + dp[2][j-1] + dp[3][j-1] + dp[4][j-1] + dp[6][j-1] + dp[7][j-1] + dp[8][j-1] + dp[9][j-1];
      dp[6][j] = dp[2][j-1] + dp[3][j-1] + dp[5][j-1] + dp[8][j-1] + dp[9][j-1];
      dp[7][j] = dp[0][j-1] + dp[4][j-1] + dp[5][j-1] + dp[8][j-1];
      dp[8][j] = dp[0][j-1] + dp[4][j-1] + dp[5][j-1] + dp[6][j-1] + dp[7][j-1] + dp[9][j-1];
      dp[9][j] = dp[5][j-1] + dp[6][j-1] + dp[8][j-1];
   }

   long long sum = 0;
   for (int i = 0; i< KEYS; i++) {
      sum += dp[i][n-1];
   }

   printf ("%d", sum);
   return 0;
}
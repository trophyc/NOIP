// 你需要给一些房子着R，G，B三色之一，相邻的房子必须着不同的颜色。
//  已知每个房子着每种颜色的花费，用尽量少的花费给每个房子着上色。

//  输入，第一行为房子数n。2 -- n+1行，每行3个整数，分别是，第i座
//  房子的 RGB费用。

#include <stdio.h>

//dp[i][j], 为从第1到第i所房子涂色的最小费用。其中第i所涂成j色。

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
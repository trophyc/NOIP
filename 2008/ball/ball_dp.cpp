#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 30
int dp[MAX][MAX]; //dp[j][i] 当前球在j号手上，还要再传i+1手，最终到0号的传球法。

int main ()
{
   int n, passes;
   cin >> n >> passes;

   memset (dp, 0, sizeof (dp));
   dp[1][0] = 1;
   dp[n-1][0] = 1;

   for (int i = 1; i < passes; i ++) {
      for (int j = 0; j < n; j++) {
         dp[j][i] = dp[(j-1+n)%n][i-1] + dp[(j+1)%n][i-1];
      }
   }

   cout << dp[0][passes-1] << endl;
   return 0;
}
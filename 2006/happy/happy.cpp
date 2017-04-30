#include <iostream>
#include <memory.h>
using namespace std;

//dp[i][m] 代表在前i个物品中花m的前选择，能取得的最大乘积和。
// dp[i][m] = dp[i-1][m] 和 dp[i-1][m-v[i]] + v[i] * w[i] 中的最大值。
// 可以降为一维。
#define MAX(a,b) ((a)>(b) ? (a) : (b))

int main ()
{
   int budget, n;
   cin >> budget >> n;
   int* dp = new int [ budget + 1 ];
   memset (dp, 0, sizeof (int)* (budget+1));

   for (int i = 0; i < n; i++) {
      int money, weight;
      cin >> money >> weight;
      for (int m = budget; m >=0; m--) {
         if (m > money) {
            dp[m] = MAX(dp[m], dp[m-money] + money* weight);
         }
      }
   }

   cout << dp[budget] << endl;
   delete [] dp;
   return 0;
}

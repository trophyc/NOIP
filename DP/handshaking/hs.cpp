//n<=50个人坐在圆桌上握手，要求每个人恰好和一个人握手，但是手不许交叉。例如四个人有两种握法。统计握法总数。

#include <iostream>
using namespace std;

#define MAX 50

long long dp[MAX/2];
void Calc (int i);

// dp(n) 为n人时的握法总数。
// n必须为偶数。选定一人位1号，则与他相邻的是2号和n号。
//   - 1与2握手，则剩下n-2人，即dp(n-2)。
//   - 1与3不能握，因为2无法与人握手。
//   - 1与4握，则分两组，（2,3） （5,6 ... n), 即dp(2) * dp (n-4);
//   - ....


int main ()
{
   int n;
   cin >> n;

   if ( n % 2 ) {
      cout << 0 << endl;
      return 0;
   }

   n /= 2;
   dp[0] = dp[1] = 1;

   for (int i = 2; i <= n; i++) {
      Calc (i);
   }
   cout << dp[n] << endl;
   return 0;
}

void Calc (int i)
{
   long long sum = 0;
   for (int j = 0; j <= i-1; j++) {
      sum += dp[j] * dp[i-1-j];
   }
   dp[i] = sum;
   cout << "---dp[" << i << "] = " << sum << endl; 
}
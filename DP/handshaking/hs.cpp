#include <iostream>
using namespace std;

#define MAX 50

long long dp[MAX/2];
void Calc (int i);

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
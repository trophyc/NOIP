#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 30

int dp[MAX+1][MAX+1];

int PassBall (int n, int i, int passes);

int main ()
{
   int n, passes;

   memset (dp, -1, sizeof (dp));
   cin >> n >> passes;

   cout <<  PassBall (n, 0, passes) << endl;

   return 0;
}

int PassBall (int n, int i, int passes)
{
   if (dp[i][passes] != -1) {
      return dp[i][passes];
   }
   
   if (passes == 1) {
      if ((i == 1 || i == n-1)) {
         dp[i][1] = 1;
         return 1;
      } 
      dp[i][1] = 0;
      return 0;
   }

   int l, r;
   l = (i + 1) % n;
   r = (i-1 + n) % n;
   dp[i][passes] = PassBall (n, l, passes -1) + PassBall (n, r, passes -1);
   return dp[i][passes];
}
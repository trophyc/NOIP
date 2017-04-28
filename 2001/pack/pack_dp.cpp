#include <stdio.h>
#include <string.h>

/*
动态规划，设：dp[i,j] 表示选前i个物品刚好能装满 j 空间 (bool),则有：
dp[i,j] = dp[i-1, j] or dp[i-1, j-v[i]]  j>v[i]
dp[i,0] = 0 ;
不过，这题有点特殊：
就是：
dp[i,j]只与: i-1有关
所以可以降到一维...
*/
int main(void)
{
   int V; // volumn of the box;
   int n; // number of items
   scanf ("%d", &V);
   scanf ("%d", &n);

   int* items = new int [n]; // storing the volum of each item
   for (int i = 0; i < n; i++) {
      scanf ("%d", &items[i]);
   }

   bool* dp = new bool [V+1]; // from 0 to V
   memset (dp, 0, sizeof(bool)* (V+1));
   dp [0] = true; // 0 item can fill volumn 0
   for (int i = 0; i < n; i++) {
      for (int j = V; j >= items[i]; j--) {
            dp[j] |= dp[ j - items[i]];
      }
   }
   
   for (int j = V; j >=1; j--) {
      if (dp[j]) {
         printf ("%d\n", V-j);
         break;
      }
   }
   delete [] dp;
   delete [] items;
   return 0;
}

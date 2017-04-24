#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

using namespace std;

int DynamicPlanning (char* buf, int len, int* dp, int start, int numbers);

int main ()
{
   int len, numbers;
   
   cin >> len >> numbers;
   numbers ++;
   char* buf;
   
   buf = (char*)malloc (len+1);
   cin.getline(buf, len+1);
   cin.getline(buf, len+1);
   
   int* dp = (int*)malloc (len*numbers* sizeof(int));
   memset(dp, -1, len*numbers*sizeof(int));
   
   cout << DynamicPlanning (buf, len, dp, 0, numbers) << endl;
   
   free (buf);
   free (dp);
   return 0;
}

int DynamicPlanning (char* buf, int len, int* dp, int start, int numbers)
{
   int idx = len * numbers + start;
   if (dp[idx] >0 ) {
      return dp[idx];
   }
   
   int i;
   int cur_number = 0;
   if (numbers == 1) {
      for (i = start; i < len; i++) {
         cur_number *= 10;
         cur_number += buf[i] - '0';
      }
      dp[idx] = cur_number;
      return cur_number;
   }

   int max = 0;
   for (i = start+1; i < len -numbers +1 ; i++) {
      cur_number *= 10;
      cur_number += buf[i-1] - '0';
      int tmp = cur_number * DynamicPlanning (buf, len, dp, i, numbers -1);
      max = (max > tmp ? max : tmp);
   }
   dp[idx] = max;
   return max;
}


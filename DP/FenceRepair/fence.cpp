#include <stdio.h>
#include <memory.h>
#include <math.h>
/*
你有一些Fence，但是其中一些破了。你希望修复它们。每次可以修复一个区间[i, i+1, ..., j]，代价是sqrt(j-i+1)。
用最小的代价修复所有的破Fence。注意：你可以修复一个本来就没破的Fence。
*/
#define MAX 1000

float cost[MAX];
int brokenNbr;
int broken[MAX];

#define min(a,b) ((a) < (b) ? (a) : (b))

int main ()
{
   scanf ("%d", &brokenNbr);
   for (int i = 0; i < brokenNbr; i++) {
      scanf ("%d", &broken[i]);
   }

   if (brokenNbr == 0) {
      printf ("%f\n", 0.0);
      return 0;
   }

   memset (cost, 0, sizeof (cost));
   cost[broken[0]] = 1;

   for (int i = 1; i < brokenNbr; i++) {
      int cur = broken[i];
      float minimum = sqrt (cur +1);
      for (int j = 1; j <= i; j++) {
         int prev1 = broken[j-1];
         int prev = broken[j];
         float tmp = cost[prev1] + sqrt (cur - prev + 1);
         minimum = min (minimum, tmp);
      }
      cost[i] = minimum;
   }

   printf ("%f\n", cost[brokenNbr-1]);
   return 0;
}
#include <stdio.h>

/*
本题在测试9和10中会溢出。
因为分数除第一人外是单调递增的，所以当 分数 > 10^10 是，如果 maxSoFar > 0, 分数只会增加，这时只要计算余数。
如果分数一直 < 10 ^10, 要判断，最后一人的分数是不是比第一人大。
*/

int main ()
{
   long long n, mod;
   scanf ("%lld %lld", &n, &mod);

   long long maxSoFar = 0;
   long long maxHere = 0;
   long long maxTotal = 0;
   long long score = 0;
   long long a;

   scanf ("%lld", &a);
   long long score0 = a;
   maxSoFar = score = maxHere = a;
   maxTotal = maxSoFar + score;
   bool bigEnough = false;
   for (int i = 1; i < n; i++) {
      scanf ("%lld", &a);
      maxHere += a;
      maxHere = (maxHere > a ? maxHere : a);
      maxSoFar = (maxSoFar > maxHere ? maxSoFar : maxHere);
      score = maxTotal;
      if (maxTotal > 10000000000L) {
         bigEnough = true;
      }
      if (!bigEnough) {
         maxTotal = (maxTotal > score + maxSoFar ? maxTotal : score + maxSoFar);
      } else {
         if (maxSoFar > 0) {
            maxTotal += maxSoFar;
            maxTotal %= mod;
         }
      }
   }

   long long result;
   if (!bigEnough) {
      result = (score0 > score ? score0 : score);
   } else {
      result = score;
   }

   printf ("%lld, %lld\n", result, result%mod);
   return 0;
}
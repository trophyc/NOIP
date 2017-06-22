#include <stdio.h>

/*

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
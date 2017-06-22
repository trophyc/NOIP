#include <stdio.h>

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
      for (int i = 1; i < n; i++) {
      scanf ("%lld", &a);
      maxHere += a;
      maxHere = (maxHere > a ? maxHere : a);
      maxSoFar = (maxSoFar > maxHere ? maxSoFar : maxHere);
      score = maxTotal;
      maxTotal = (maxTotal > score + maxSoFar ? maxTotal : score + maxSoFar);
   }
   long long result = (score0 > score ? score0 : score);
   printf ("% lld, %lld\n", result, result%mod);
   return 0;
}
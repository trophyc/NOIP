#include <stdio.h>
#include <math.h>

// int 位数不够， long long有18位， 15^11小于18位。
int main()
{
   int base, n;
   scanf ("%d", &base);
   scanf ("%d", &n);

   long long sum = 0;
   long long power = 1;

   //N <= 1000, so less than 10 digits.
   int bitmask = 1;
   for (int i = 0; i < 11; i++) {
      if (n & bitmask) {
         sum += power;
      }
      power *= base;
      bitmask = bitmask << 1;
   }

   printf ("%ld\n", sum);
   return 0;
}
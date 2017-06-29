#include <stdio.h>
#include <math.h>

int main ()
{
   int days;
   scanf ("%d", &days);

   int n = (int) ((sqrt(8*days + 1)-1) /2);
   int r = days - n * (n+1)/2;

   int coin = n* (n+1) * (2*n+1)/6 + r * (n+1);
   printf ("%d\n", coin);
   return 0;
}
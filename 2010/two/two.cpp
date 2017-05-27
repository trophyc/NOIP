#include <stdio.h>

int GetDigitsOf (int nbr, int digit);

int main ()
{
   int l, r;
   scanf ("%d % d", &l, &r);
   printf ("%d\n", GetDigitsOf(r, 2) - GetDigitsOf(l-1, 2));
   return 0;
}

int GetDigitsOf (int nbr, int digit)
{
   int result = 0;
   int p = 10;
   int tmp = nbr;

   do {
      int q = tmp / 10;
      int r = tmp % 10;
printf ("## tmp = %d, q = %d, r = %d result = %d", tmp, q, r, result);
      if (r > digit) {
         result +=  (q+1) * p / 10;
      } else if (r == digit) {
         if (p == 10) {
            result += (q+1);
         } else {
            result +=  q* p / 10 + nbr % (p/10) +1;
         }
      } else {
         result += q * p /10;
      }
printf ("---result = %d\n", result);      
      p *= 10;
      tmp /= 10;
   } while (p /10 <= nbr);
   return result;
}
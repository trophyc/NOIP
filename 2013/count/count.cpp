#include <stdio.h>

int FindDigitIn (int n, int x);

int main ()
{
   int n, x;
   int sum = 0;

   scanf ("%d %d", &n, &x);

   for (int i = 1; i <= n ; i++) {
      sum += FindDigitIn (i, x);
   }
   printf ("%d\n", sum);
   return 0;
}

int FindDigitIn (int n, int x)
{
   int sum = 0;
   while (n >= 1) {
      int r = n % 10;
      if (r == x) {
         sum ++;
      }
      n /= 10;
   }
   return sum;
}
#include <stdio.h>

#define MAX_POWER 100
#define ABS(a) ((a) > 0 ? (a) : -(a))

int main ()
{
   int factors[MAX_POWER+1];

   int n;
   scanf ("%d", &n);
   for (int i = 0; i <= n; i++) {
      scanf ("%d", &factors[i]);
   }

   for (int i = 0; i <=n; i++) {
      if (factors[i] == 0) {
         continue;
      }
      if (i != 0 && factors[i] > 0) {
         printf ("+");
      }
      if (factors[i] < 0) {
         printf ("-");
      }
      if (ABS(factors[i]) != 1 || i == n) {
         printf ("%d", ABS(factors[i]));         
      }
      if (i != n) {
         printf ("x^%d", n-i);
      }
   }
   return 0;
}
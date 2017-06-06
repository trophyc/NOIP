#include <stdio.h>
#include <math.h>

int main ()
{
   freopen ("prime.in", "r", stdin);
   freopen ("prime.out", "w", stdout);

   long long n;
   scanf ("%d", &n);
   float limit = sqrt (n);

   for (int i = 2; i < limit + 1; i++) {
      if (n % i == 0) {
         printf ("%d\n", n/i);
         break;
      }
   }
   fclose (stdin);
   fclose (stdout);
   return 0;
}

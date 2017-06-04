#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
   int n;

   scanf ("%d", &n);
   srand(time(0));

   printf ("%d\n", n);
   for (int i = 0; i < n; i++) {
      if (rand() % 2 == 0) {
         printf ("+");
      } else {
         printf ("*");
      }
   }
   printf ("\n");
   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
   srand(time(0));

   int n = 80;
   int m = 100;
   printf ("%d %d\n", n, m);
   for (int i = 0; i < n; i++) {
      printf ("%d ", rand() % 99 + 1);
   }
   return 0;
}
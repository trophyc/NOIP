#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
   int n, m, a;
   srand(time(0));

   scanf ("%d %d %d", &n, &m, &a);

   printf ("%d %d %d\n", n, m, a);
   for (int i = 0; i < n; i++) {
      printf ("%d ", rand() % a + 1);
   }
   return 0;
}
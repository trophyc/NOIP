#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Random(int l, int h);

int main ()
{
   srand (time(0));
   printf ("%d %d %d %d\n", Random(-500, 500), Random (-500,500), Random (-500, 500), Random (-500, 500));
   printf ("100000\n");

   for (int i = 0; i < 100000; i++) {
      printf ("%d %d\n", Random(-1000, 1000), Random (-1000, 1000));
   }
   return 0;
}

int Random(int l, int h)
{
   int r = rand() % (h-l+1);
   return (r+l);
}
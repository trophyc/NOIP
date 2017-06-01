#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random (int l, int u);
struct order {
   int nbr;
   int random;
};

order x[200000];
int cmp (const void* A, const void* B);

int main ()
{
   int n = 100000;
   int r = 50;
   int q = 50000;

   srand (time (0));

   printf ("%d %d %d\n", n, r, q);
   int j = 0; 
   for (int i = 0; i < 2*n; i++) {
      printf ("%d ", random(1, 50));
      j++;
      if (j >= 100) {
         j = 0;
         printf ("\n");
      }
   }

   for (int i = 0; i < 2*n; i++) {
      x[i].nbr = i;
      x[i].random = rand();
   }
   qsort (x, 2*n, sizeof(order), cmp);
   
   for (int i = 0; i < 2*n; i++) {
      int j = 0;
      printf ("%d ", x[i].nbr);
      j++;
      if (j >= 100) {
         j = 0;
         printf ("\n");
      }
   }
   return 0;
}

int random (int l, int u)
{
   return rand() % (u-l+1) + l;
}

int cmp (const void* A, const void* B)
{
   const order* a = (const order*)A;
   const order* b = (const order*)B;

   if (a->random > b->random) {
      return 1;
   }
   if (a->random < b->random) {
      return -1;
   }
   float f = rand()/RAND_MAX;
   if (f > 0.5) {
      return 1;
   }
   return -1;
}
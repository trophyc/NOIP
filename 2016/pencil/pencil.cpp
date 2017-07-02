#include <stdio.h>
#include <limits.h>

struct package 
{
   int nbr;
   int price;
};

package p[3];

int main ()
{
   int t;
   scanf ("%d", &t);
   for (int i = 0; i < 3; i++) {
      scanf ("%d", &p[i].nbr);
      scanf ("%d", &p[i].price);
   }

   int min = INT_MAX;
   for (int i = 0; i < 3; i++) {
      int packs;
      if (t % p[i].nbr == 0) {
         packs = t / p[i].nbr;
      } else {
         packs = t / p[i].nbr + 1; 
      }
      int sum = packs * p[i].price;
      min = (min < sum ? min : sum);
   }

   printf ("%d\n", min);
   return 0;
}
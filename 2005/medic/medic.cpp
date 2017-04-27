#include <stdio.h>

struct Herb {
   int t;
   int value;
};

int dfs (Herb* herbs, int n, int start, int t);

int main ()
{
   int t, nbr;

   scanf ("%d", &t);
   scanf ("%d", &nbr);

   Herb* herbs = new Herb [nbr];
   for (int i = 0; i < nbr; i++) {
      scanf ("%d", &(herbs[i].t));
      scanf ("%d", &(herbs[i].value));
   }

   printf ("%d\n", dfs(herbs, nbr, 0, t));
   return 0;
}

#define MAX(a,b) ((a)>(b) ? (a) : (b))

int dfs (Herb* herbs, int n, int start, int t)
{
   int a = 0;
   int b = 0;

   if (start == n-1) {
      if (t < herbs[n-1].t) {
         return 0;
      } else {
         return herbs[n-1].value;
      }
   }

   if (t >= herbs[start].t) {
      a = herbs[start].value + dfs (herbs, n, start+1, t - herbs[start].t);
   }
   b =  dfs (herbs, n, start+1, t);
   return MAX(a,b);
}
#include <stdio.h>
#include <memory.h>

struct Herb {
   int t;
   int value;
};

#define MAX_ITEMS 100
#define MAX_TIME 1000
int value[MAX_ITEMS][MAX_TIME+1];

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
   memset (value, -1, sizeof (value));

   printf ("%d\n", dfs(herbs, nbr, 0, t));
   delete [] herbs;
   return 0;
}

#define MAX(a,b) ((a)>(b) ? (a) : (b))

int dfs (Herb* herbs, int n, int start, int t)
{
   int a = 0;
   int b = 0;

   if (value[start][t] != -1) {
      return value[start][t];
   }
   if (start == n-1) {
      if (t < herbs[n-1].t) {
         value[start][t] = 0;
         return 0;
      } else {
         value[start][t] = herbs[n-1].value;
         return herbs[n-1].value;
      }
   }

   if (t >= herbs[start].t) {
      a = herbs[start].value + dfs (herbs, n, start+1, t - herbs[start].t);
   }
   b =  dfs (herbs, n, start+1, t);
   value[start][t] = MAX(a,b);
   return MAX(a,b);
}
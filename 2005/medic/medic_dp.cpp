#include <stdio.h>
#include <memory.h>

#define MAX_TIME 1000

/*
动态规划，设：value[i,t] 表示花时间t选前i个仙草的最大价值,则有：
value[i,t] = value[i-1, t] or value[i-1, t-t[i]] + v[i]  t>t[i]
value[i,0] = 0 ;
不过，这题有点特殊：
就是：
value[i,j]只与: i-1有关
所以可以降到一维...
*/

int value [MAX_TIME+1];

struct Herb {
   int t;
   int value;
};

#define MAX(a,b) ((a)>(b) ? (a) : (b))

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
   memset (value, 0, sizeof(value));
   
   for (int i = 0; i < nbr; i ++) {
      for (int j = t; j >= herbs[i].t; j --) { 
         value[j] = MAX (value[j], herbs[i].value + value[j - herbs[i].t]);
      }
   }

   printf ("%d\n", value[t]);
   delete [] herbs;
   return 0;
}
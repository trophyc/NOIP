#include <stdio.h>
#include <memory.h>

#define MAX_NATIONS 100
#define MAX_CULTURES 100
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int nationNbr, cultureNbr, roadNbr, start, end;

struct Nation 
{
   int culture;
   int roads [MAX_NATIONS];
};

Nation nations[MAX_NATIONS];
bool cultureExpel[MAX_CULTURES][MAX_CULTURES];
void InitData();

int main ()
{
   InitData();
   return 0;
}

void InitData()
{
   memset (nations, 0, sizeof (nations));   
   scanf ("%d %d %d %d %d", &nationNbr, &cultureNbr, &roadNbr, &start, &end);
   for (int i = 0; i < nationNbr; i++) {
      int culture;
      scanf ("%d", &culture);
      nations[i].culture = culture - 1;
   }
   for (int i = 0; i < cultureNbr; i++) {
      for (int j = 0; j < cultureNbr; j++) {
         int a;
         scanf ("%d", &a);
         if ( a == 1) {
            cultureExpel[i][j] = true;
         } else {
            cultureExpel[i][j] = false;            
         }
      }
   }
   for (int i = 0; i < roadNbr; i++) {
      int a, b, len;
      scanf ("%d %d %d", &a, &b, &len);
      a--;
      b--;
      nations[a].roads[b] = nations[b].roads[a] = MIN (len, nations[a].roads[b] );
   }
}
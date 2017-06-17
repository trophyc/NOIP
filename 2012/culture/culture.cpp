#include <stdio.h>
#include <memory.h>

#define MAX_NATIONS 100
#define MAX_CULTURES 100
#define MAX_DISTANCE 99000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int nationNbr, cultureNbr, roadNbr, start, end;

struct Nation 
{
   int culture;
   int roads [MAX_NATIONS];
};

Nation nations[MAX_NATIONS];
bool cultureExpel[MAX_CULTURES][MAX_CULTURES];
bool usedCultures[MAX_CULTURES];

void InitData();
void PrintData();
bool CultureConflict(int n);
int ShortestPath (int s, int d);

int main ()
{
   InitData();
   PrintData();
   printf ("%d\n", ShortestPath(start, end));
   return 0;
}

void InitData()
{
   memset (nations, 0, sizeof (nations));   
   scanf ("%d %d %d %d %d", &nationNbr, &cultureNbr, &roadNbr, &start, &end);
   start --; 
   end --;
   for (int i = 0; i < nationNbr; i++) {
      int culture;
      scanf ("%d", &culture);
      nations[i].culture = culture - 1;
   }
   for (int i = 0; i < cultureNbr; i++) {
      for (int j = 0; j < cultureNbr; j++) {
         int a;
         scanf ("%d", &a);
         if (i == j) {
            cultureExpel[i][j] = true;            
         }
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
      if (nations[a].roads[b] == 0) {
         nations[a].roads[b] = nations[b].roads[a] = len;
      } else {
         nations[a].roads[b] = nations[b].roads[a] = MIN (len, nations[a].roads[b] );
      }
   }
   memset (usedCultures, 0, sizeof (usedCultures));
}

void PrintData()
{
   printf ("%d %d %d %d %d\n ----- Map --------\n", nationNbr, cultureNbr, roadNbr, start, end);
   for (int i = 0; i < nationNbr; i ++) {
      printf ("Nation %d: culture: %d : \n", i, nations[i].culture);
      for (int j = 0; j < nationNbr; j++) {
         if (nations[i].roads[j] > 0) {
            printf ("\t\t to %d, len: %d\n", j, nations[i].roads[j]);
         }
      }
   }
   printf ("----- Culture expel ------\n");
   for (int i = 0; i < cultureNbr; i ++) {
      for (int j = 0; j < cultureNbr; j++) {
         printf ("%d ", cultureExpel[i][j]);
      }
      printf ("\n");
   }
}

bool CultureConflict(int n) 
{
   for (int i = 0; i < MAX_CULTURES; i++) {
      if (cultureExpel[n][i] && usedCultures[i]) {
         return true;
      }
   }
   return false;
}

int ShortestPath (int s, int d)
{
   int shortest = MAX_DISTANCE + 1;

   if (CultureConflict(s)) {
      return -1;
   }
   // Mask this culture
   usedCultures[nations[s].culture] = true;

   for (int i = 0; i < nationNbr; i++) {
      int theRest;
      if (nations[s].roads[i] == 0) {
         continue;
      }
      theRest = nations[s].roads[i];
      if (i != d) {
         int tmp = ShortestPath(i, d);
         if (tmp == -1) {
            theRest = -1;
         } else {
            theRest += tmp;
         }
      }

      if (theRest != -1) {
         shortest = MIN (shortest, theRest);
      }
   }

   shortest = (shortest >= MAX_DISTANCE ? -1 : shortest);
   usedCultures[nations[s].culture] = false;
   return shortest;
}
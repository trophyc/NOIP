#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_NATIONS 100
#define MAX_CULTURES 100
#define INFINITE (unsigned int)(-1)

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int nationNbr, cultureNbr, roadNbr, start, end;

struct Nation 
{
   int culture;
   int roads [MAX_NATIONS];
   unsigned int distance; // d[i] in dijkstra
   bool selected;     // In S set
   int from;            // storing the path.
};

Nation nations[MAX_NATIONS];
bool cultureExpel[MAX_CULTURES][MAX_CULTURES];


void InitData ();
void PrintData ();
void Dijkstra (int start);
void UpdateDistance (int cur);
int SelectNext();
bool CultureConflict (bool* map, int i);

int main ()
{
   InitData();
   Dijkstra (start);
   printf ("%d\n", nations[end].distance);
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
      nations[i].distance = INFINITE;
      nations[i].selected = false;
   }

   for (int i = 0; i < cultureNbr; i++) {
      for (int j = 0; j < cultureNbr; j++) {
         int a;
         scanf ("%d", &a);
         if (i == j) {
            cultureExpel[i][j] = true;
         } else if ( a == 1) {
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

void Dijkstra (int start)
{
   nations[start].distance = 0;   
   nations[start].selected = true;
   nations[start].from = -1;

   int current = start;
   for (int i = 1; i < nationNbr; i++) {
      UpdateDistance (current);
      current = SelectNext();
      nations[current].selected = true;
   }
}

void UpdateDistance (int cur)
{
   bool cultureMap[MAX_NATIONS];
   memset (cultureMap, 0, sizeof(cultureMap));
   int p = cur;
   while (p != -1) {
      cultureMap[nations[p].culture] = true;
      p = nations[p].from;
   }

   for (int i = 0; i < nationNbr; i++) {
      int road = nations[cur].roads[i];
      if (road && !nations[i].selected && !CultureConflict(cultureMap, i)) {
         int distance = nations[cur].distance + road;
         if (distance <= nations[i].distance) {
            nations[i].distance = distance;
            nations[i].from = cur;
         }
      }
   }
}

int SelectNext()
{
   int next = 0;
   int tmp = INFINITE;

   for (int i = 0; i < nationNbr; i++) {
      if (nations[i].selected) {
         continue;
      }
      if (nations[i].distance < tmp) {
         tmp = nations[i].distance;
         next = i;
      }
   }
   return next;
}

bool CultureConflict (bool* map, int i)
{
   for (int j = 0; j < cultureNbr; j++) {
      if (cultureExpel[nations[i].culture][j] && map[j]) {
         return true;
      }
   }
   return false;
}
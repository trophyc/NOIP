#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

#define MAX_STOPS 1000
#define MAX_TRAINS 1000

int stops, trains;

typedef queue<int> IntQ;
struct Vertice {
   int inComings;
   int outGoings[MAX_STOPS+1];
};

Vertice v[MAX_STOPS+1];
int levels;

void InitData();
void PrintGraph ();
void TopologicalSort ();
void AddingFirstLevelToQ (IntQ* q);

int main ()
{
   InitData ();
   TopologicalSort ();
   printf ("%d\n", levels);
   return 0;
}

void InitData()
{
   levels = 0;
   scanf ("%d %d", &stops, &trains);
   memset (v, 0, sizeof(v));

   for (int i = 0; i < trains; i++) {
      int numbers;
      int trainStop[MAX_STOPS];
      memset (trainStop, 0, sizeof (trainStop));
      scanf ("%d", &numbers);
      for (int j = 0; j < numbers; j++) {
         int tmp;
         scanf ("%d", &tmp);
         trainStop[j] = tmp;
      }
      
      int ptr = 0;
      for (int j = trainStop[0]; j <= trainStop[numbers-1]; j++) {
         if (j == trainStop[ptr]) {
            ptr++;
            continue;
         }
         for (int k = 0; k < numbers; k++) {
            if (v[j].outGoings[trainStop[k]] != 1) {
               v[trainStop[k]].inComings ++;
               v[j].outGoings[trainStop[k]] = 1;
            }
         }
      }  
   }
}

void TopologicalSort ()
{
   // with bfs algorithm.
   IntQ q;
   AddingFirstLevelToQ (&q);
  
   while (!q.empty()) {
      int a = q.front();
      q.pop();
      if (a == -1) {
         // current level done, adding a new seprator for nexxt level
         if (!q.empty()) {
            q.push (-1);
         }
         levels ++; 
         continue;
      }
    
      for (int i = 1; i <= stops; i++) {
         int next = v[a].outGoings[i];
         if (next) {
            v[i].inComings --;
            if (v[i].inComings == 0) {
               q.push(i);
             }
         }
      }
   }
}

void AddingFirstLevelToQ (IntQ* q)
{
   for (int i = 1; i <= stops; i++) {
      if (v[i].inComings == 0) {
         q->push(i);
      }
   }
   q->push(-1); // adding a separator.
}

void PrintGraph ()
{
   for (int i = 1; i <= stops; i++) {
      printf ("%d: incoming: %d, outGoings: ", i, v[i].inComings);
      for (int j = 0; j < stops; j++) {
         if (v[i].outGoings[j]) {
            printf ("%d ", j);
         }
      }
      printf ("\n");
   }
}
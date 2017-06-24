#include <iotream>
#include <queue>
#include <memory.h>

using namespace std;

#define MAX_STOPS 1000
#define MAX_TRAINS 1000

int stops, trains;

struct Vertice {
   int inComings;
   int outGoings[MAX_STOPS];
};

Vertice v[MAX_STOPS];

void InitData();
void PrintGraph ();

int main ()
{
   InitData ();
   return 0;
}

void InitData()
{
   cin >> stops >> trains;
   memset (v, 0, sizeof(v));

   for (int i = 1; i < trains; i++) {
      int numbers;
      int trainStop[MAX_STOPS];
      memset (trainStop, 0, sizeof (trainStop));
      cin >> numbers;
      for (int i = 0; i < numbers; i++) {
         int tmp;
         cin >> tmp;
         tmp--;
         trainStop[i] = tmp;
      }
      
      int ptr = 0;
      for (int i = trainStop[0]; i <= trainStop[numbers-1]; i++) {
         if (i == trainStop[ptr]) {
            ptr++;
            continue;
         }
         for (int j = 0; j < numbers; j++) {
            v[trainStop[j]].inComings ++;
            v[i].outGoings[trainStop[j]] = 1;
         }
      }  
   }
}

void PrintGraph ()
{
   
}
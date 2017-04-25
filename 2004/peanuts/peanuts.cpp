#include <iostream>
#include <stdlib.h>
using namespace std;

struct corn {
   int amount;
   int x;
   int y;
};

#define MAX 20

corn field[MAX*MAX]; 
int CmpCorn (const void* c1, const void* c2);

#define abs(a) ((a) > 0 ? (a): (0-(a)))

int TimeForNextAndGetBack(int curX, int curY, int i);
int TimeForNext (int curX, int curY, int i);

int main ()
{
   int n, m, k;
   cin >> n >> m >> k;


   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> field[i * m + j].amount;
         field[i * m + j].x = j;
         field[i * m + j].y = i;
      }
   }

   qsort (field, MAX*MAX, sizeof(corn), CmpCorn);

   int curX = field[0].x;
   int curY = -1;
   int i = 0;
   int fetched = 0;
   while (k >= TimeForNextAndGetBack(curX, curY, i) && field[i].amount > 0) {
      fetched += field[i].amount;
      k -= TimeForNext (curX, curY, i);
      curX = field[i].x;
      curY = field[i].y;
      i++;
   }

   cout << fetched << endl;
   return 0;
}

int CmpCorn (const void* c1, const void* c2)
{
   return ( static_cast <const corn*>(c2)->amount - static_cast <const corn*>(c1)->amount);
}

int TimeForNextAndGetBack(int curX, int curY, int i)
{
   int time = abs (field[i].x - curX) + abs (field[i].y - curY) + 1 + field[i].y + 1;
   return time;
}

int TimeForNext (int curX, int curY, int i)
{
   return (abs (field[i].x - curX) + abs (field[i].y - curY) + 1);
}
#include <iostream>
#include <stdlib.h>
#include <memory.h>

using namespace std;

#define MAX_ITEMS 30

int dfs (int remains, const int* a, int i, int total, int** gap); // returns the minimum gap.

int main ()
{
   int V;
   int n;
   int a[MAX_ITEMS];

   cin >> V;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   int** gap = new int* [n];
   for (int i = 0; i < n; i++) {
      gap[i] = new int [V+1];
      memset (gap[i], -1, sizeof (int)* (V+1));
   }

   cout << dfs (V, a, 0, n, gap);

   for (int i = 0; i < n; i++) {
      delete [] gap[i];
   }
   delete [] gap;

   return 0;
}

#define min(a,b) ((a) < (b)  ? (a) : (b))

int dfs (int r, const int* a, int i, int n, int** gap)
{
   int x = r;
   int y;

   if (a[i] == r) {
      cout << 0 << endl;
      exit(0);
   }

   if (gap[i][r] != -1) {
      return gap[i][r];
   }

   if (i == n-1) {
      if (a[i] > r) {
         gap[i][r] = r;
         return r;
      }
      gap[i][r] = r- a[i];
      return (r - a[i]);
   }

   if (a[i] < r) {
      x = dfs (r - a[i], a, i+1, n, gap);  
   }
   y = dfs (r, a, i+1, n, gap);
   gap[i][r] = min (x,y);
   return gap[i][r];
}
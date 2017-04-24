#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX_ITEMS 30

int dfs (int remains, const int* a, int i, int total); // returns the minimum gap.

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

   cout << dfs (V, a, 0, n);
   return 0;
}

#define min(a,b) (a < b  ? a : b)

int dfs (int r, const int* a, int i, int n)
{
   int x = r;
   int y;
   
   if (a[i] == r) {
      cout << 0 << endl;
      exit(0);
   }

   if (i == n-1) {
      if (a[i] > r) {
         return r;
      }
      return (r - a[i]);
   }

   if (a[i] < r) {
      x = dfs (r - a[i], a, i+1, n);  
   }
   y = dfs (r, a, i+1, n);
   return min (x,y);
}
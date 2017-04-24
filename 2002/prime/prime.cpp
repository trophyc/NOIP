#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime (int p);
#define MAX_N 20

int count = 0;

void dfs (int curSum, int remains, int index, int* x, int total);

int main ()
{
   int n, k;
   cin >> n >> k;
   int x[MAX_N];
   for (int i = 0; i < n; i++) {
      cin >> x[i];
   }

   dfs (0, k, 0, x, n);
   cout << count << endl;
   return 0;
}

bool IsPrime (int p)
{
   if (p < 2) {
      return false;
   }

   for (int i = 2; i <= sqrt(p)+1; i++) {
      if (p/i*i == p) {
         return false;
      }
   }
   return true;
}

void dfs (int curSum, int remains, int index, int* x, int total)
{
   if (remains == 1) {
      for (int i = index; i < total; i++){
         int p = curSum + x[i];
         if (IsPrime(p)) {
            count++;
         }
      }
      return;
   }
   for (int i = index; i <= total - remains; i++) {
      dfs (curSum + x[i], remains -1, i+1, x, total);
   } 
}
#include <iostream>
#include <memory.h>

using namespace std;

int dfs (int n, int* results);

int main ()
{
   int n;
   cin >> n;  

   int* results = new int[n];
   memset (results, 0, sizeof (int) * n);

   cout << dfs(n, results) << endl;
   delete [] results;
   return 0;
}

int dfs (int n, int* results)
{
   if (results[n-1] > 0) {
      return results[n-1];
   }

   int count = 0;
   for (int i = 1; i <= n/2; i++) {
      count += dfs (i, results);
   }
   results[n-1] = ++count;

   return count;
}

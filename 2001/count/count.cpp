#include <iostream>

using namespace std;

int count = 0;

void dfs (int n);

int main ()
{
   int n;
   cin >> n;   
   dfs (n);   
   cout << count << endl;
}

void dfs (int n)
{
   count ++;
   if (n == 1) {
      return;
   }

   for (int i = 1; i <= n/2; i++) {
      dfs (i);
   }
   return;
}

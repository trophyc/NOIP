#include <iostream>
using namespace std;

int main ()
{
   int k;
   cin >> k;
   
   double sum = 0;
   int i = 0;
   while (sum <= k) {
      i++;
      sum += (double)1 / (double)(i);
   }
   cout << i << endl;
   return 0;
}
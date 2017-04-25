#include <iostream>
using namespace std;

int main ()
{
   int max = 0;
   int day = 0;

   for (int i = 0; i < 7; i++) {
      int a, b;
      cin >> a >> b;
      if (max < a+b) {
         day = i+1;
         max = a+b;
      }
   }
   cout << day << endl;
   return 0;
}
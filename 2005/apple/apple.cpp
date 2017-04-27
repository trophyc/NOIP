#include <iostream>
using namespace std;

#define APPLES 10
#define CHAIR 30
int main ()
{
   int apples [APPLES];
   int tao;

   for (int i = 0; i < APPLES; i++) {
      cin >> apples[i];
   }
   cin >> tao;
   tao += CHAIR;

   int count = 0;
   for (int i = 0; i < APPLES; i++) {
      if (tao >=apples[i]) {
         count++;
      }
   }
   cout << count << endl;
   return 0;
}
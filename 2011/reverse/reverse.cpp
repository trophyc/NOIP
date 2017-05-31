#include <iostream>
using namespace std;

int main ()
{
   long long n;

   cin >> n;

   if (n== 0) {
      cout << '0' << endl;
      return 0;
   }

   if (n < 0) {
     cout << '-';
   }
   n = (n > 0 ? n : (0-n));

   bool firstNonZero = false;
   for (int i = 0; i < 10; i++) {
      int r = n % 10;
      if (r != 0) {
         firstNonZero = true;
      }
      if (firstNonZero) {
         cout << (char)(r + '0');
      }
      n = n/10;
      if (n == 0) {
         break;
      }
   }

   cout << endl;
   return 0;
}
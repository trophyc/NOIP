#include <iostream>
using namespace std;

int main ()
{
   int a, b, l;
   cin >> a >> b >> l;

   cout << l << endl;
   if (a == 0) {
      cout << 0 << " " << 1 << endl;
      return 0;
   }
   if (b == 0) {
      cout << 1 << " " << 0 << endl;
      return 0;
   }
   if (a == b) {
      cout << 1 << " " << 1 << endl;
      return 0;
   }

   double ratio = (double)a / (double)b;
   double epsilon = 10000000;
   int a1 = 1, b1 = 1;
   int bestA = 1, bestB = 1;

   if (a > b) {
      for (a1 = l; a1 > 0; a1--) {
         for (b1 = a1 - 1; b1 > 0; b1--) {
            double tmp = (double) a1 / (double) b1 - ratio;
            if (tmp < 0) {
               continue;
            }
            if (tmp <= epsilon) {
               epsilon = tmp;
               bestA = a1;
               bestB = b1;
            } else {
               break;
            }
         }
      }
   } else {
      for (b1 = l; b1 > 0; b1--) {
         for (a1 = b1 - 1; a1 > 0; a1--) {
            double tmp = (double) a1 / (double) b1 - ratio;
            if (tmp < 0) {
               break;
            }
            if (tmp <= epsilon) {
               epsilon = tmp;
               bestA = a1;
               bestB = b1;
            }
         }
      }
   }
   cout << bestA << " " << bestB << endl;
   return 0;
}
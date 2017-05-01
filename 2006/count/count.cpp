#include <iostream>
using namespace std;

#define MAX_DIGITS 26
#define MAX_TIMES 5

int main ()
{
   int start, end, digits;
   cin >> start >> end >> digits;
   char jam[MAX_DIGITS];
   cin >> jam;

   for (int i = 0; i < digits; i++) {
      jam[i] -= ('a' + start - 1);
   }

   for (int i = 0; i < MAX_TIMES; i++) {
      int j = 0;
      int c;
      for (j = 0; j < digits; j++) {
         if (jam[digits - 1- j] == end - start -j) {
            // the last possible letter for this digit;
            continue;
         }
         // the next letter for this digit;
         c = ++ jam[digits -1 -j];
         break;
      }
      j--;
      for (; j >= 0; j --) {
         jam[digits -1 -j] = ++c;
      }

      for (int k = 0; k < digits; k++) {
         cout << (char)(jam[k] + 'a' + start -1);
      }
      cout << endl;
   }

   return 0;
}

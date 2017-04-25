#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 500

int result[MAX];

void By2();
void Minus1();
int Digits ();
void PrintOut();

int main ()
{
   int n;
   cin >> n;
   memset (result, 0, sizeof(result));
   result[0] = 1;

   for (int i = 0; i < n; i++) {
      By2();
   }

   //the last digit cannot be 0, so just minus 1.
   result[0] -= 1;
   
   cout << Digits() << endl;
   PrintOut();
   return 0;
}

void By2()
{
   int c = 0;
   for (int i = 0; i < MAX; i++) {
      result[i] *= 2;
      result[i] += c;
      if (result[i] >= 10) {
         result[i] -= 10;
         c = 1;
      } else {
         c = 0;
      }
   }
}

int Digits()
{
   int d = MAX;
   for (int i = MAX-1; i >= 0; i--) {
      if (result[i] == 0) {
         d--;
      } else {
         break;
      }
   }
   if (d == 0) {
      d = 1;
   }
   return d;
}

void PrintOut()
{
   for (int i = 9; i >= 0; i--) {
      for (int j = 49; j >= 0; j--) {
         cout << result[i*50+j];
      }
      cout << endl;
   }
}


#include <iostream>
#include <string>
#include <memory.h>
#include <string.h>

using namespace std;

void PrintResult (const int* p, int n);
void Multiply (int* result, int* mul, int n);

int main ()
{
   string nbr;
   int digits;
   cin >> nbr;
   cin >> digits;

   int* result = new int [digits];

   memset (result, 0, sizeof(int)* digits);
   const char* p = nbr.c_str();
   int len = strlen (p);

   for (int i = 0; i < len && i < digits; i++) {
      result[i] = *(p + len - 1 -i) - '0';
   }

   int* mul = new int [digits];
   memcpy (mul, result, sizeof(int)*digits);

   long long limit = 10;
   long long i = 0;
   int cur_digit = 1;
   bool found = false;
   do {
      Multiply (result, mul, digits);
      i++;
      if (memcmp (mul, result, sizeof (int) * cur_digit) == 0) {
         // we have found the period of the first "cur_digit"s.
         // for the next digit, the period wouldn't be bigger than 10 * this period.
         if (cur_digit == digits) {
               found = true;
               break;
         }
         limit = i * 10;
         cur_digit ++;
      }
   } while (i <= limit && cur_digit <= digits);

   cout << "Digits = " << digits << endl;
   PrintResult (result, digits);
   if (found) {
         cout << i << endl;
   } else {
         cout << -1 << endl;
   }

   delete [] result;
   delete [] mul;
   return 0;
}

void Multiply (int* result, int* mul, int n)
{
   int* tmp = new int [n];
   memset (tmp, 0, sizeof (int)*n);

   for (int i = 0; i < n; i++) {
      if ( mul[i] == 0) {
         continue;
      }
      int carry = 0;
      for (int j = 0; j < n - i; j++) {
         if (carry == 0 &&  result[j] == 0) {
            continue;
         }
         tmp[i+j] += ( carry + mul[i] * result[j]); 
         carry = tmp[i+j] /10;
         tmp[i+j] %= 10;
      }
   }
   memcpy (result, tmp, sizeof (int) * n);
   delete [] tmp;
}

void PrintResult (const int* p, int n)
{
   for (int i = 0; i <n; i++) {
      cout << p[n-1-i];
   }
   cout << endl;
}
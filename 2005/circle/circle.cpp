#include <iostream>
#include <string>
#include <memory.h>
#include <string.h>

using namespace std;

void PrintResult (const int* p, int n);
void Multiply (int* result, int* mul, int n);
void Increase (int* i, int digits);
int Compare (int* a, int* b, int digits);
/*
1. 高精度计算。
2. 必有周期，因为n位数只有10^n个排列。
3. 但是有可能前几个不再周期里，如35, 35*35 = 1225; 25*25 = 625, ...
    除第一个以外，都是25
4. 如果，前2位的周期因为3,则第3位周期不大于30. 否则是3中描述的情况
*/
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

   int* limit = new int [digits+2];
   int* i = new int [digits+2];
   memset (limit, 0, sizeof (int) * (digits + 2));
   limit[1] = 1; // limit = 10;
   memset (i, 0, sizeof (int) * (digits + 2));

   int cur_digit = 1;
   bool found = false;
   do {
      Multiply (result, mul, digits);
      //i++;
      Increase (i, digits+2);
      if (memcmp (mul, result, sizeof (int) * cur_digit) == 0) {
         // we have found the period of the first "cur_digit"s.
         // for the next digit, the period wouldn't be bigger than 10 * this period.
         if (cur_digit == digits) {
               found = true;
               break;
         }
         // limit = i *10
         limit[0] = 0;
         for (int k = 0; k < digits +1; k++) {
            limit[k+1] = i[k];   
         }
         cur_digit ++;
      }
   } while (Compare (i, limit, digits+2) <= 0 && cur_digit <= digits);

   cout << "Digits = " << digits << endl;
   PrintResult (result, digits);
   if (found) {
         PrintResult (i, digits + 2);
   } else {
         cout << -1 << endl;
   }

   delete [] result;
   delete [] mul;
   delete [] limit;
   delete [] i;
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
   bool leading0 = true;
   for (int i = n-1; i >= 0; i--) {
      if (leading0 && p[i] == 0 ) {
         continue;
      }
      cout << p[i];
      leading0 = false;
   }
   cout << endl;
}

void Increase (int* i, int digits)
{
   int carry = 1;
   int k = 0;
   while (carry && k < digits) {
      i[k] ++;
      carry = i[k] /10;
      i[k] %= 10;
      k++;
   } 
   return;     
}

int Compare (int* a, int* b, int digits)
{
   for (int i = digits-1; i >= 0; i--){
      if (a[i] < b[i]) {
         return -1;
      }
      if (a[i] > b[i]) {
         return 1;
      }
   }
   return 0;
}
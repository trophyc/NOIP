#include <iostream>
using namespace std;
#include <memory.h>
#include <limits.h>

// 2*3*5*7*11*17*19*23*29*31*37*41 = 9,814,524,629,910 > INT_MAX
// 不可能有多于 12 个质因数
#define MAX_PRIME 12
struct PrimeFactor {
   int p;
   int power;
};

void GetAllPrimeFactors (int n, PrimeFactor* result, int len);
void AddPower (PrimeFactor* result, int len, int i);
int GetSeconds (PrimeFactor* tube, PrimeFactor* cell, int len);

void PrintPower (PrimeFactor* result, int len);

int main ()
{
   int n, m1, m2;
   cin >> n >> m1 >> m2;

   PrimeFactor tube[MAX_PRIME];
   memset (tube, -1, sizeof (tube));
   GetAllPrimeFactors (m1, tube, MAX_PRIME);
   for (int i = 0; i < MAX_PRIME; i++) {
      if (tube[i].p == -1) {
         break;
      }
      tube[i].power *= m2;
   }

   int min = INT_MAX;   
   for (int i = 0; i < n; i++) {
      int si;
      cin >> si;
      PrimeFactor cell[MAX_PRIME];
      memset (cell, -1, sizeof(cell));
      GetAllPrimeFactors (si, cell, MAX_PRIME);
      int t = GetSeconds(tube, cell, MAX_PRIME);
      t = (t < 0 ? INT_MAX : t);
      min = (min <= t ? min : t);
   }

   min = (min == INT_MAX ? -1 : min);
   cout <<(int) min << endl;
   return 0;
}

void GetAllPrimeFactors (int n, PrimeFactor* result, int len)
{
   if (n == 1) {
      return;
   }

   int i = 2;
   do {
      if (n % i == 0) {
         AddPower (result, len, i);
         break;
      }
      i++;
   } while (i <= n);
   GetAllPrimeFactors(n/i, result, len);
   return;
}

void AddPower (PrimeFactor* result, int len, int i)
{
   for (int k = 0; k < len; k++) {
      if (result[k].p == i ) {
         result[k].power ++;
         break;
      }
      if (result[k].p == -1) {
         result[k].p = i;
         result[k].power = 1;
         break;
      }
   }
}

int GetSeconds (PrimeFactor* tube, PrimeFactor* cell, int len)
{
   int max = 1;
   int j = 0;

   for (int i = 0; i < len ; i++) {
      if (tube[i].p == -1) {
         break;
      }
      while (cell[j].p < tube[i].p && cell[j].p != -1) {
         j++;
      }
      if (cell[j].p != tube[i].p) {
         return   (-1);
      }
      int a = tube[i].power % cell[i].power;
      int b = tube[i].power / cell[i].power;
      int times = ( a == 0 ? b : b+1);
      max = (max >= times ? max : times);
   }
   return max;
}


void PrintPower (PrimeFactor* result, int len)
{
   cout << "--------------" << endl;
   for (int i = 0; i < len; i++) {
      if (result[i].p == -1) {
         break;
      }
      cout << "(" << result[i].p << " ^ " << result[i].power << ")" << endl;
   }
   cout << "--------------" << endl;
}
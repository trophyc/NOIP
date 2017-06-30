#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_CELLS 100000
#define MAX_COLORS 100000

typedef vector<int> IntVec;

int cells, colors;
int number[MAX_CELLS];

IntVec oddPos[MAX_COLORS];
IntVec evenPos[MAX_COLORS];

#define MOD 10007

int GetSum (IntVec v);
int GetSum_fast (IntVec v);

int main ()
{
   scanf ("%d %d", &cells, &colors);

   for (int i = 0; i < cells; i++) {
      scanf ("%d", &number[i]);
   }
   for (int i = 0; i < cells; i++) {
      int color;
      scanf ("%d", &color);
      color --;
      if (i % 2 == 0) {
         evenPos[color].push_back(i);
      } else {
         oddPos[color].push_back(i);
      }
   }

   int sum = 0;
   for (int i = 0; i < colors; i++) {
      sum += GetSum_fast (evenPos[i]) + GetSum_fast (oddPos[i]);
      sum %= MOD;
   }
   printf ("%d\n", sum);
   return 0;
}

int GetSum (IntVec v)
{
   int sum = 0;
   int n = v.size();
   
   for (int i = 0; i < n-1; i++) {
      for (int j = i +1; j < n; j++) {
         sum += (v[i] + v[j] + 2) % MOD * ((number[v[i]] + number[v[j]]) % MOD);
         sum %= MOD;
      }
   }
   return sum;
}

int GetSum_fast (IntVec v)
{
   int sum = 0;
   int n = v.size();

   int a = 0;
   for (int i = 0; i < n; i++) {
      a += number[v[i]];
      a %= MOD;
   }

   for (int i = 0 ; i < n; i++) {
      sum +=  (a + (n-2) * number[v[i]]) % MOD * (v[i] + 1);
      sum %= MOD;
   }
   return sum;
}
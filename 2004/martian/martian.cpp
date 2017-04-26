#include <stdio.h>

int Increase (int* p, int count); // returns 1, if successfule, returns 0, if fails.
void ExchangeDigits (int* p, int count, int cur);
void PrintOut(int* p, int count);
//算法描述：
// 从个位向前扫描，直到发现第一个小于前一位的数字，如13542中的3. 13xxx形式的数中，当前这个
// 数最大。下一个必须把3换成xxx中比3大的最小数，即4，所以，将3，4互换得，14532，这是14xxx
// 中最大的。将xxx由降序换升序，即完成加1.
int main ()
{
   int n;
   int k;

   scanf ("%d", &n);
   scanf ("%d", &k);
   int* p = new int [n];
   for (int i = 0; i < n; i++ ) {
      scanf ("%d", p+i);
   }

   for (int i = 0; i < k; i++) {
      Increase (p, n);
   }

   PrintOut (p, n);
   
   delete [] p;
   return 0;
}

int Increase (int* p, int count) 
{
   for (int i = count - 2; i >= 0; i--) {
      if (p[i] < p[i+1]) {
         ExchangeDigits (p, count, i);
         return 1;
      }
   }
   return 0;
}

void ExchangeDigits (int* p, int count, int cur)
{
   for (int i = count - 1; i >= cur + 1; i -- ) {
      if ( p[i] > p[cur]) {
         int tmp = p[i];
         p[i] = p[cur];
         p[cur] = tmp;
         break;
      }
   }
   for (int i = cur+1; i <= (count + cur)/2 ; i++) {
      int tmp = p[i];
      p[i] = p [count + cur - i];
      p [count + cur - i] = tmp;
   }
}

void PrintOut(int* p, int count)
{
   for (int i = 0; i < count; i++ ) {
      printf ("%d ", *(p+i));
   }
   printf ("\n");
}
#include <stdio.h>
#include <memory.h>

#define MAX_NBR 500
int value[MAX_NBR][MAX_NBR];

void InitValue (int n);
void PrintValue (int n);
int Find2ndMax (int* array, int len);
/*
满足题意的任何数据，小涵都有必胜策略。
将每一行的第二大数据挑出来，选择其中最大的即可， 记为a。
因为每行的最大数据必被计算机破坏，小涵只能得到第二大。
从第3轮开始，每一行，每一列中大于a的最多只有一个。如(4,6) (6,4), 
则不可能再有(3,6) (6,3), 否则的话第6行中有两个大于a, 这样选a的时候
应该选第6行的。
小涵选6或4，这样电脑就选不到大于a的了。
*/
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main ()
{
   int n;
   scanf ("%d", &n);
   InitValue (n);
   int max = -1;
   for (int i = 0; i < n; i++) {
      max = MAX (max, Find2ndMax(&value[i][0], n));
   }
   printf ("1\n%d\n", max);
   return 0;
}

void InitValue (int n)
{
   memset (value, -1, sizeof (value));
   for (int i = 0; i < n; i++) {
      for (int j = i+1 ; j < n; j++) {
         int v;
         scanf ("%d", &v);
         value[j][i] = value[i][j] = v;
      }
   }
}

void PrintValue (int n)
{
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf ("%4d ", value[i][j]);
      }
      printf ("\n");
   }
}

int Find2ndMax (int* array, int len)
{
   int max = -1;
   int secondMax = -1;

   for (int i = 0; i < len; i++) {
      if (array[i] > secondMax && array[i] < max) {
         secondMax = array[i];
      } else if (array[i] > max) {
         secondMax = max;
         max = array[i];
      }
   }
   return secondMax;
}
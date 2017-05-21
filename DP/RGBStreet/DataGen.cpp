#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 第一行是一个整数，表示有几座房子
// 从第二行开始，每一行3个整数，表示这座房子
// 分别刷成RGB的费用。

int random (int l, int u);

int main ()
{
   int n;
   scanf ("%d", &n);

   printf ("%d\n", n);
   
   srand ((int)time(0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
         printf ("%d ", random (2, 9) );
      }
      printf ("\n");
   }
   return 0;
}

int random (int l, int u)
{
   return (l + rand() % (u-l));
}
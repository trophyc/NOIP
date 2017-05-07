#include <stdio.h>

int main ()
{
   char d[10];
   scanf ("%c-%c%c%c-%c%c%c%c%c-%c", d, d+1, d+2, d+3, d+4, d+5,
          d+6, d+7, d+8, d+9);
   
   int r = 0;
   for (int i = 0; i < 9; i++) {

      r += (d[i] - '0') * (i+1);
      r %= 11;
   }

   if (r == d[9] - '0'){
      printf ("Right\n");
      return 0;
   }

   d[9] = r + '0';
   printf ("%c-%c%c%c-%c%c%c%c%c-%c\n", d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8], d[9]);
   return 0;
}
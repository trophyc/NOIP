#include <stdio.h>

#define MOD 10000

int main ()
{
   int sum = 0;
   int tmp1, product;
   int count;
   char op;

   product = 1;
   do {
      count = scanf ("%d", &tmp1);
      if (count != 1) {
         break;
      }
      product *= tmp1;
      product %= MOD;
      count = scanf ("%c", &op);
      if (count != 1) {
         sum += product;
         sum %= MOD;
         break;
      }
      if (op == '+') {
         sum += product;
         sum %= MOD;
         product = 1;
      } else if (op == '*') {
         continue;
      } else {
         sum += product;
         sum %= MOD;
         break;
      }
   } while (1);

   printf ("%d\n", sum);
   return 0;
}
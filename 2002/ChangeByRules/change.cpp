#include <stdio.h>

#define MAX_LEN 31
#define MAX_RULES 15

int rules[10]; // one for each digits
char number[MAX_LEN+1];

int main ()
{
   int n;

   scanf ("%s", number);
   scanf ("%d", &n);

   for (int i = 0; i < 10; i++){
      rules[i] = 1;
   }
   for (int i = 0; i < n; i++){
      int org, change;
      scanf ("%d", &org);
      scanf ("%d", &change);
      rules[org] ++;
   }

   unsigned int result = 1;
   char* p = number;
   while (*p != '\0') {
      result *= rules[*p-'0'];
      p++;
   }
   printf ("%u\n", result);
   return 0;
}

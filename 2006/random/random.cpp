#include <stdio.h>
#include <stdlib.h>

int cmp (const void* a, const void* b);

int main ()
{
   int total;
   int* numbers;

   scanf ("%d", &total);
   numbers = new int [total];
   for (int i = 0; i < total; i++) {
      scanf ("%d", numbers + i);
   }

   qsort (numbers, total, sizeof (int), cmp);

   int count = total;
   for (int i = total -1; i > 0; i--) {
      if (numbers[i] == numbers[i-1]) {
         numbers[i] = -1;
         count --;
      }
   }

   printf ("%d\n", count);
   for (int i = 0; i < total; i ++) {
      if (numbers[i] == -1) {
         continue;
      }
      printf ("%d ", numbers[i]);
   }
   printf ("\n");
   delete [] numbers;
   return 0;
}

int cmp (const void* a, const void *b)
{
   int A = *((int*) a);
   int B = *((int*) b);

   if (A == B) {
      return 0;
   }
   if (A < B) {
      return -1;
   }
   return 1;
}
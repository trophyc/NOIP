#include <stdio.h>

int main ()
{
   int max, segments;
   scanf ("%d", &max);
   scanf ("%d", &segments);

   bool* trees = new bool [max+1];
   for (int i = 0; i <= max; i++) {
      trees[i] = true;
   }

   int count = max + 1;
   for (int i = 0; i < segments; i++) {
      int low, high;
      scanf ("%d", &low);
      scanf ("%d", &high);
      for (int j = low; j <= high; j++) {
         if (trees[j]) {
            trees[j] = false;
            count --;
         }
      }
   }

   printf ("%d\n", count);
   delete [] trees;
   return 0;
}
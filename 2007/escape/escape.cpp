#include <stdio.h>

int FlashDistance (int curDist, int* magic);

int main ()
{
   int magic, distance, time;

   scanf ("%d", &magic);
   scanf ("%d", &distance);
   scanf ("%d", &time);

   int flash = 0;
   int run = 0;
   for (int i = 1; i <= time; i ++) {
      flash = FlashDistance (flash, &magic);
      run += 17;
      if (flash > run) {
         run = flash;
      }
     
      if (run >= distance) {
         printf ("Yes\n%d\n", i);
         return 0;
      }
   }

   printf ("No\n%d\n", run);
   return 0;
}

int FlashDistance (int curDist, int* magic)
{
   if (*magic >= 10) {
      *magic -= 10;
      curDist += 60;
      return curDist;
   }
   *magic += 4;
   return curDist;
}
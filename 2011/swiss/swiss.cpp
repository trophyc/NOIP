#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

struct player {
   int score;
   int power;
   int nbr;
};

int compare (const void* A, const void* B);

player all[2*MAX_N];

int main ()
{
   int n, r, q;
   scanf ("%d %d %d", &n, &r, &q);

   for (int i = 0; i < 2*n; i++) {
      scanf ("%d", &all[i].score);
      all[i].nbr = i+1;
   }
   for (int i = 0; i < 2*n; i++) {
      scanf ("%d", &all[i].power);
   }

   for (int i = 0; i < r; i++) {
      qsort (all, n*2, sizeof(player), compare);
      for (int j = 0; j < n; j++) {
         if (all[2*j].power > all[2*j+1].power) {
            all[2*j].score ++;
         } else {
            all[2*j+1].score ++;
         }
      }
   }

   qsort (all, n*2, sizeof(player), compare);
   printf ("%d\n", all[q-1].nbr);
   return 0;
}

int compare (const void* A, const void* B)
{
   const player* a = (const player*)A;
   const player* b = (const player*)B;

   if (a->score > b->score) {
      return -1;
   }
   if (a->score < b->score) {
      return 1;
   }
   if (a->nbr < b->nbr) {
      return -1;
   }
   return 1;
}
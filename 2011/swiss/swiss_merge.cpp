#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#define MAX_N 100000

struct player {
   int score;
   int power;
   int nbr;
};

int compare (const void* A, const void* B);
void Fight (int n);
void Merge (int n);

player all[2*MAX_N];
player winner[MAX_N];
player loser[MAX_N];

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

   qsort (all, n*2, sizeof(player), compare);

   for (int i = 0; i < r; i++) {
      Fight(n);
      Merge(n);
   }

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

void Fight (int n)
{
   for (int j = 0; j < n; j++) {
      if (all[2*j].power > all[2*j+1].power) {
         ++(all[2*j].score);
         winner[j] = all[2*j];
         loser[j] = all[2*j+1]; 
      } else {
         ++ (all[2*j+1].score);
         winner[j] = all[2*j+1];
         loser[j] = all[2*j];
      }
   }
}

void Merge (int n)
{
   int pwinner = 0;
   int ploser = 0;
   int pmerge = 0;

   while (pmerge < 2*n) {
      int cmp = compare ((void*)(&winner[pwinner]), (void*)(&loser[ploser]));
      assert (cmp == 1 || cmp == -1);
      if (cmp == 1 ) {
         //winner < loser
         all[pmerge++] = loser[ploser++];
      } else if (cmp == -1) {
         //winner > loser
         all[pmerge++] = winner[pwinner++];
      }
      if (pwinner == n) {
         memcpy(&all[pmerge], &loser[ploser], sizeof (player) * (n-ploser));
         break;
      }
      if (ploser == n) {
         memcpy(&all[pmerge], &winner[pwinner], sizeof (player) * (n-pwinner));         
         break;
      }
   }
   
}
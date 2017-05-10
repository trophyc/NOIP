#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Candidate {
   int no;
   int score;
};

int cmp (const void* A, const void* B);

int main ()
{
   int total, selected;
   scanf ("%d", &total);
   scanf ("%d", &selected);

   Candidate* all = new Candidate [total];
   for (int i = 0; i < total; i++) {
      scanf ("%d", &all[i].no);
      scanf ("%d", &all[i].score);
   }

   int shortListed = selected * 1.5;
   if (shortListed > total) {
      shortListed = total;
   }

   qsort (all, total, sizeof (Candidate), cmp);
   int scoreLine = all[shortListed-1].score;

   int count = shortListed;
   while (shortListed < total && all[shortListed].score >= scoreLine) {
      count++;
      shortListed++;
   } 

   printf ("%d %d\n", scoreLine, count);
   for (int i = 0; i < count; i++) {
      printf ("%d %d\n", all[i].no, all[i].score);
   }
   delete [] all;
   return 0;
}

int cmp (const void* A, const void* B)
{
   const Candidate* a = (const Candidate*) A;
   const Candidate* b = (const Candidate*) B;

   if (a->score > b->score) {
      return -1;
   }
   if (a->score < b->score) {
      return 1;
   }
   // same core
   if (a->no > b->no) {
      return 1;
   }
   if (a->no < b->no) {
      return -1;
   }
   return 0;
}
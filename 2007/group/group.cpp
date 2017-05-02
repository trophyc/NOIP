#include <stdio.h>
#include <stdlib.h>

struct gift
{
   int value;
   int prev;
   int next;
};

int CompareGift(const void* A, const void* B);
void SetLinks (gift* allGifts, int n);
void PrintLinks (gift* allGifts, int n);
void DeleteLink (gift* allGifts, int index);
int MakeGroup (gift* allGifts, int n, int limit);

#define HEAD 0
#define TAIL 1

int main ()
{
   int limit, n;
   scanf ("%d", &limit);
   scanf ("%d", &n);

   gift* allGifts = new gift [n+2];
   // gift[0] is the head and gift[1] is the tail.
   for (int i = 2; i < n+2; i ++){
      scanf ("%d", &(allGifts[i].value));
   }
   qsort (allGifts+2, n, sizeof(gift), CompareGift);
   SetLinks (allGifts, n);

   int count = 0;
   while (MakeGroup(allGifts, n, limit) > 0) {
      count ++;
 //     PrintLinks(allGifts, n);
   }

   printf ("%d\n", count);

   return 0;
}

int CompareGift(const void* A, const void* B)
{
   const gift* a = (const gift*) A;
   const gift* b = (const gift*) B;

   if (a->value > b->value) {
      return -1;
   } else if (a->value < b->value) {
      return 1;
   } 
   return 0;
}

void SetLinks (gift* allGifts, int n)
{
   for (int i = 2; i < n+2; i++) {
      allGifts[i].prev = i-1;
      allGifts[i].next = i+1;
   }
   allGifts[HEAD].next = 2;
   allGifts[HEAD].prev = -1;
   allGifts[2].prev = 0;
   allGifts[TAIL].prev = n+1;
   allGifts[TAIL].next = -1;
   allGifts[n+1].next = 1;
   return;
}

void PrintLinks (gift* allGifts, int n)
{
   for (int i = 0; i < n+2; i++) {
      printf ("i = %d, value = %d, prev = %d, next = %d\n", 
               i, allGifts[i].value, allGifts[i].prev, allGifts[i].next );
   }
}

void DeleteLink (gift* allGifts, int index)
{
   int prev = allGifts[index].prev;
   int next = allGifts[index].next;
   
   allGifts[index].prev = -1;
   allGifts[index].next = -1;
   if (prev >= 0) {
      allGifts[next].prev = prev;
   }
   if (next >= 0) {
      allGifts[prev].next = next;
   }
}

int MakeGroup (gift* allGifts, int n, int limit)
{
   int big = allGifts[HEAD].next;
   int small = TAIL;

   if (big == TAIL) {
      return 0;
   }

   DeleteLink(allGifts, big);
   int gap = limit - allGifts[big].value;

   int last = small;
   do {
      last = small;
      small = allGifts[small].prev;
   } while ( small > TAIL && allGifts[small].value <= gap);

   if (last > TAIL) {
      DeleteLink (allGifts, last);
   }
   return 1;
}
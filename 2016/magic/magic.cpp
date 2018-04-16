#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_ITEMS 40000
struct item {
   int magic;
   int idx;
   int result[4];
};

int itemNbr;
item items[MAX_ITEMS];
int maxMagic;

int cmp_magic (const void* A, const void* B);
int cmp_idx (const void* A, const void* B);
void PrintItems ();
int BinarySearch (int m, int l, int r, bool exact = true);
void match ();
int FindNextValue (int curIdx);
void MarkDown (int pa, int pb, int pc, int pd);
void MarkOnePointer (int p, int idx, int n);
int NumberOfSameValue (int idx);

int main ()
{
   memset (items, 0, sizeof(items));
   scanf ("%d %d", &maxMagic, & itemNbr);

   for (int i = 0; i < itemNbr; i++) {
      scanf ("%d", &items[i].magic);
      items[i].idx = i+1;
   }

   qsort (items, itemNbr, sizeof(item), cmp_magic);
   maxMagic = items[itemNbr-1].magic;

/*   int q;
   scanf ("%d", &q);
   printf ("%d is at %d.\n", q, BinarySearch (q, 0, itemNbr-1));*/
   match();
   qsort (items, itemNbr, sizeof(item), cmp_idx);
   PrintItems();   
   return 0;
}

int cmp_magic (const void* A, const void* B)
{
   const item* a = (const item*)A;
   const item* b = (const item*)B;

   if (a->magic > b->magic) {
      return 1;
   }
   if (a->magic < b->magic) {
      return -1;
   }
   if (a->idx < b->idx) {
      return -1;
   }
   return 1;
}

int cmp_idx (const void* A, const void* B)
{
   const item* a = (const item*)A;
   const item* b = (const item*)B;

   if (a->idx > b->idx) {
      return 1;
   }
   if (a->idx < b->idx) {
      return -1;
   }
   return 0;
}

void PrintItems ()
{
/*   for (int i = 0; i < itemNbr; i++) {
      printf ("Magic = %d, idx = %d\n", items[i].magic, items[i].idx);
   }
*/
   for (int i = 0; i < itemNbr; i++) {
      printf ("%d %d %d %d\n", items[i].result[0], items[i].result[1], items[i].result[2], items[i].result[3]);
   }
}

int BinarySearch (int m, int l, int r, bool exact)
{
   if (m < items[l].magic) {
      return (exact ? -1 : l);
   }
   if (m > items[r].magic) {
      return (exact ? -1 : r+1);
   }
   int mid = (l + r) /2;
   if (items[mid].magic == m) {
      return mid;
   }

   if (items[mid].magic < m) {
      if (mid + 1 >= r) {
         if (items[r].magic == m) {
            return r;
         } else {
            return (exact ? -1 : r);
         }
      }
      return BinarySearch (m, mid + 1, r, exact);
   } else {
      if (l >= mid - 1) {
         if (items[l].magic == m) {
            return l;
         } else {
            return (exact ? -1 : mid);
         }
      }
      return BinarySearch (m, l, mid -1, exact);
   }
}

void match ()
{
   int ptrA, ptrB, ptrC, ptrD;
   int a, b, c, d;
   ptrA = 0;
   while (ptrA >= 0 && ptrA < itemNbr - 3) {
      a = items[ptrA].magic;
      ptrB = FindNextValue (ptrA);
//printf ("2 - ptrA = %d, ptrB = %d\n", ptrA, ptrB);  
      while (ptrB != -1) {
         b = items[ptrB].magic;
         int BA = b - a;
         if (a + 4 * BA + BA /2 + 1 > maxMagic) {
            break;
         }
         if (BA % 2) {
            ptrB = FindNextValue (ptrB);
            continue;
         }
         c = b + 3 * BA + 1;
         if (c + BA / 2 > maxMagic) {
            break;
         }

         ptrC = BinarySearch (c, ptrB, itemNbr-1, false);
//printf ("3 - ptrA = %d, ptrB = %d, ptrC = %d\n", ptrA, ptrB, ptrC);           
         do {
            c = items[ptrC].magic;
            d = c + BA /2;
            if (d > maxMagic) {
               break;
            }
            ptrD = BinarySearch (d, ptrC, itemNbr-1);
            if (ptrD == -1) {
               continue;
            }
//printf ("4 - ptrA = %d, ptrB = %d, ptrC = %d, ptrD = %d\n", ptrA, ptrB, ptrC, ptrD);  
            MarkDown (ptrA, ptrB, ptrC, ptrD);
         } while ((ptrC  = FindNextValue(ptrC)) != -1);
         ptrB = FindNextValue(ptrB);
      }
      ptrA = FindNextValue (ptrA);
   }
}

int FindNextValue (int curIdx)
{
   int curValue = items[curIdx].magic;
   for (int i = curIdx + 1; i < itemNbr; i ++) {
      if (curValue != items[i].magic) {
         return i;
      }
   }
   return -1;
}

void MarkDown (int pa, int pb, int pc, int pd)
{
   int a = NumberOfSameValue (pa);
   int b = NumberOfSameValue (pb);
   int c = NumberOfSameValue (pc);
   int d = NumberOfSameValue (pd);
//printf ("a, b, c, d = %d, %d, %d, %d\n", a, b, c, d);   
   MarkOnePointer (pa, 0, b*c*d);
   MarkOnePointer (pb, 1, a*c*d);
   MarkOnePointer (pc, 2, a*b*d);
   MarkOnePointer (pd, 3, a*b*c);
}

void MarkOnePointer (int p, int idx, int n)
{
   int magic = items[p].magic;
   items[p].result[idx] += n;
   int i = p+1;
   while ( i < itemNbr && items[i].magic == magic) {
      items[i].result[idx] += n;
      i++;
   }
   i = p-1;
   while (i >= 0 && items[i].magic == magic) {
      items[i].result[idx] += n;
      i--;
   }   
}

int NumberOfSameValue (int p)
{
   int magic = items[p].magic;
   int ret = 1;
   int i = p+1;
   while (items[i].magic == magic) {
      ret++;
      i++;
   }
   i = p-1;
   while (items[i].magic == magic) {
      ret++;
      i--;
   }   
   return ret;   
}
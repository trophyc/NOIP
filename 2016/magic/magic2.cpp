#include <stdio.h>
#include <memory.h>

#define MAX_MAGIC 15000
#define MAX_ITEMS 40000

int items;
int maxMagic;

// magic[i] stores the number of items with magic value == i
int magic[MAX_MAGIC+1];
// item[i] stores the magic value of the (i+1)th item
int item[MAX_ITEMS];

int result[MAX_ITEMS][4];

void match ();
void PrintResult ();

int main ()
{
   memset (magic, 0, sizeof (magic));
   memset (result, 0, sizeof (result));

   scanf ("%d %d", &maxMagic, & items);
   for (int i = 0; i < items; i++) {
      int m;
      scanf ("%d", &m);
      magic[m] ++;
      item[i] = m;
   }

   match ();
   PrintResult();
   return 0;
}

void match ()
{
   for (int a = 0; a < items - 3; a++) {
      if (magic[a] == 0) {
         continue;
      }
      for (int b = a+2 ; b <= (2 * maxMagic + 7* a - 2)/9; b++) {
         if (magic[b] == 0) {
            continue;
         }
         int BA = b-a;         
         int c = b + BA * 3 + 1;
         for (; c <= maxMagic - BA/2; c++) {
            if (magic[c] == 0) {
               continue;
            }
            int d = c + BA / 2;
            if (d == 0) {
               continue;
            } 
            result[a][0] += magic[b] * magic[c] * magic[d];
            result[b][1] += magic[a] * magic[c] * magic[d];
            result[c][2] += magic[a] * magic[b] * magic[d];
            result[d][3] += magic[a] * magic[b] * magic[c];
         } 
      }
   }
}

void PrintResult ()
{
   for (int i = 0; i < items; i++) {
      int m = item[i];
      printf ("%d %d %d %d\n", result[m][0], result[m][1], result[m][2], result[m][3]);
   }
}
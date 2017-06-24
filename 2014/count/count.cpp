#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 100

int set[MAX_NUMBER];
int n;
int result;

int compare (const void* A, const void* B);
bool Addable (int i);
void PrintSet ();

int main ()
{
   scanf ("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf ("%d", &(set[i]));
   }

   qsort (set, n, sizeof(int), compare);

   result = 0;
   for (int i = 0; i < n-2; i++) {
      if (Addable (i)) {
         result++;
      }
   }

   printf ("%d\n", result);
   return 0;
}

int compare (const void* A, const void* B)
{
   const int* a = (const int*)A;
   const int* b = (const int*)B;

   if (*a > *b) {
      return -1;
   }
   if (*a == *b) {
      return 0;
   }
   return 1;
}

bool Addable (int idx)
{
   int thisNumber = set[idx];
   int i = idx + 1;
   int j = n-1;

   int gap = thisNumber - set [i];
   while (set[i] > thisNumber/2 && i < j) {
      if (gap > set[j]) {
         j--;
      } else if (gap == set[j]) {
         return true;
      } else {
         i++;
         gap = thisNumber - set[i];
      }
   }
   return false;
}

void PrintSet ()
{
   for (int i = 0; i < n; i++) {
      printf ("%d ", set[i]);
   }
   printf ("\n");
}
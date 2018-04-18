#include <stdio.h>
#include <string.h>

#define MAX_LEN 40
#define MAX_NUM 6

unsigned long long result[MAX_LEN][MAX_NUM];
int n, k;
char input[MAX_LEN+1];

void ReadIn();
void PrintOut ();
unsigned long long dfs(int end, int muls);

int main ()
{
   memset (result, -1, sizeof (result));
   ReadIn();
   printf ("%lu\n", dfs (n, k));
   return 0;
}

void ReadIn ()
{
   scanf ("%d", &n);
   scanf ("%d", &k);
   scanf ("%s", input);
}

void PrintOut ()
{
   printf ("n = %d, k = %d", n, k);
   printf ("%s\n", input);
}

unsigned long long dfs(int end, int muls)
{
   if (end == 0) {
      return 1;
   }
   if (result[end][muls] != -1) {
      return result[end][muls];
   }

   unsigned long long max = 0;
   for (int start = muls; start < end; start++)
   {
      unsigned long long cur = 0;
      for (int i = start; i < end; i++) {
         cur *= 10;
         cur += input[i] - '0';
      }
      unsigned long long tmp = cur * dfs(start, muls-1);
      max = (max > tmp ? max : tmp);
   }

   result[end][muls] = max;
   return max;
}
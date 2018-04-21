#include <stdio.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_LEN 1024

char words[MAX_WORDS][MAX_LEN];
char startStr[8];
int count;

int used[MAX_WORDS];
int appendingLength[MAX_WORDS][MAX_WORDS];

void ReadIn();
void PrintOut();
int dfs (int i, int curMax);
int GetMaxLength ();
void CalcAppendingLength ();
int CalcTwoStrings(int i, int j);

int main ()
{
   ReadIn();
   CalcAppendingLength();
   int ans = GetMaxLength ();
   printf ("%d\n", ans);
}

void ReadIn ()
{
   scanf ("%d", &count);
   for (int i = 0; i < count; i++) {
      scanf ("%s", words[i]);
   }
   scanf ("%s", startStr);
}

void PrintOut()
{
   printf ("---\n%d\n", count);
   for (int i = 0; i < count; i++) {
      printf ("%s\n", words[i]);
   }
   printf ("%s\n---\n", startStr);

   for (int i = 0; i < count; i++) {
      for (int j = 0; j < count; j++) {
         printf ("%d\t", appendingLength[i][j]);
      }
      printf ("\n");
   }
}

int dfs (int idx, int curMax)
{
   int max = curMax;
   for (int k = 0; k < count ; k++) {
      if (used[k] >= 2 || !appendingLength[idx][k]) {
         continue;
      }
      used[k] ++;
      int tmp = dfs (k, curMax + appendingLength[idx][k]);
      max = (max > tmp ? max : tmp);
      used[k] --;
   }
   return max;
}

int GetMaxLength ()
{
   int maxLength = 0;
   for (int i = 0; i < count; i++) {
      if (words[i][0] != startStr[0]) {
         break;
      }
      memset (used, 0, sizeof (used));
      used[i] = 1;
      int tmp = dfs (i, strlen(words[i]));
      maxLength = (maxLength > tmp ? maxLength : tmp);
   }
   return maxLength;
}

void CalcAppendingLength ()
{
   for (int i = 0; i < count; i++) {
      for (int j = 0; j < count; j++) {
         appendingLength[i][j] = CalcTwoStrings (i, j);
      }
   }
}

int CalcTwoStrings(int i, int j)
{
   char* str1 = words[i];
   char* str2 = words[j];
   int len1 = strlen (str1);
   int len2 = strlen (str2);

   int min_len = (len1 < len2 ? len1: len2);
   int ans = 0;
   for (int k = 1; k <= min_len && ans == 0; k++) {
      if (strncmp (str1+len1-k, str2, k) != 0) {
         continue;
      }
      ans = len2 - k;
   }
   return ans;
}
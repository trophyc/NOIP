#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const char* words[7] = {"hello", "beautiful", "world", "don't", "rain", "start", "shine"};
int len[7] = {5, 9, 5, 5, 4, 5, 5};

int main ()
{
   int total_len = 0;

   srand (time(0));
   printf ("BeAuTiFuL\n");

   while (total_len < 1000000 - 10) {
      int idx = rand() % 7;
      printf ("%s ", words[idx]);
      total_len += len[idx] +1;
   }

   return 0;
}
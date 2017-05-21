#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
   if (argc != 2) {
      printf ("Usage: %s <filename>\n", argv[0]);
      return 0;
   }

   int n, m, p;
   scanf ("%d %d %d", &n, &m, &p);
   
   FILE* file = fopen(argv[1], "wt+");
   if (!file) {
      printf ("Cannot open file %s.\n", argv[1]);
      return 0;
   }
   fprintf (file, "%d %d %d\n", n, m, p);

   srand ((int)time(0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         fprintf (file, "%d ", rand()%10);
      }
      fprintf (file, "\n");
   }
   for (int i = 0; i < n; i++) {
      fprintf (file, "%d ", rand()%3);
   }
   fclose (file);
}
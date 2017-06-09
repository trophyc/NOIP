#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10000
#define ROOMS 100
#define MAX_SIGN 1000000

int main ()
{
   srand (time(0));
   
   printf ("%d %d\n", FLOORS, ROOMS);
   for (int i = 0; i < FLOORS; i++) {
      for (int j = 0; j < ROOMS; j++) {
         printf ("%d %d\n", rand()%2, rand() % MAX_SIGN + 1);
      }
   } 

   printf ("%d", rand() % ROOMS);
   return 0;
}


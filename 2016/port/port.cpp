#include <stdio.h>
#include <memory.h>

FILE* hFirst;
FILE* hSecond;

#define ONEDAY 86400
#define MAX_NATIONS 100000
unsigned int nations;
unsigned int visitors[MAX_NATIONS+1];
unsigned int ships;
unsigned int timeOf2nd;

void AddThisShip ();
void RemoveAllOldShips (unsigned int t);

int main (int argc, char** argv)
{
   if (argc != 2) {
      return -1;
   }

   nations = 0;
   memset (visitors, 0, sizeof(visitors));
   hFirst = fopen (argv[1], "r");
   hSecond = fopen (argv[1], "r");
  
   fscanf (hFirst, "%u", &ships);
   fscanf (hSecond, "%u", &ships);
   fscanf (hSecond, "%u", &timeOf2nd);

   for (unsigned int i = 0; i < ships; i++) {
      unsigned int shipTime;
      fscanf (hFirst, "%u", &shipTime);
      AddThisShip ();
      if (shipTime >= ONEDAY) {
         RemoveAllOldShips (shipTime - ONEDAY);
      }
      printf ("%d\n", nations);
   }

   fclose (hFirst);
   fclose (hSecond);
   return 0;
}

void AddThisShip ()
{
   unsigned int n;
   fscanf (hFirst, "%u", &n);

   for (unsigned int i = 0; i < n; i++) {
      unsigned int c;
      fscanf (hFirst, "%u", &c);
      visitors[c] ++;
      if (visitors[c] == 1) {
         nations ++;
      }
   }
}

void RemoveAllOldShips (unsigned int t)
{
   while (timeOf2nd <= t) {
      unsigned int n;
      fscanf (hSecond, "%u", &n);
      for (unsigned int i = 0; i < n; i++) {
         unsigned c;
         fscanf (hSecond, "%u", &c);
         visitors[c] --;
         if (visitors[c] == 0) {
            nations --;
         }
      }
     fscanf (hSecond, "%u", &timeOf2nd);
   }
}
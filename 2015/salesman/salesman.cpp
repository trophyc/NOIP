#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int disctance[MAX];
struct client {
   int nbr;
   int fatigue;
   int dist;
};
client all[MAX];
client b[MAX];

int clients;

int cmp_fatigue (const void* A, const void* B);
int cmp_f_and_d (const void* A, const void* B);

int MaxPoints (int x, int maxSoFar, int farID, int* ptrB);
void PrintClients (client* a, int n);

int main ()
{
   scanf ("%d", &clients);
   for (int i = 0; i < clients; i++) {
      int d;
      scanf ("%d", &d);
      all[i].dist = 2*d;
      all[i].nbr = i;
   }
   for (int i = 0; i < clients; i++) {
      scanf ("%d", &all[i].fatigue);      
      b[i] = all[i];
   }
   qsort (all, clients, sizeof(client), cmp_fatigue);
   qsort (b, clients, sizeof(client), cmp_f_and_d);

//PrintClients (all, clients);
//PrintClients (b, clients);

   int maxSoFar = 0;
   int farID = 0;
   int ptrB = 0;
   for (int x = 0; x < clients; x++) {
      maxSoFar += all[x].fatigue;
      farID = (all[farID].dist >= all[x].dist ? farID : x);
      printf ("%d\n", MaxPoints(x, maxSoFar, farID, &ptrB));
   }
   return 0;
}

int cmp_fatigue (const void* A, const void* B)
{
   const client* a = (const client*)A;
   const client* b = (const client*)B;

   if (a->fatigue > b->fatigue) {
      return -1;
   } else if (a->fatigue == b->fatigue) {
      if (a->dist > b->dist) {
         return -1;
      } else if (a->dist < b->dist) {
         return 1;
      }
      return 0;
   }
   return 1;
}

int cmp_f_and_d (const void* A, const void* B)
{
   const client* a = (const client*)A;
   const client* b = (const client*)B;

   int tmpA = a->fatigue + a->dist;
   int tmpB = b->fatigue + b->dist;
   if (tmpA > tmpB) {
      return -1;
   } else if (tmpA == tmpB) {
      return 0;
   }
   return 1;
}

int MaxPoints (int x, int maxSoFar, int farID, int* ptrB)
{
   int result = maxSoFar + all[farID].dist;
   while (*ptrB < clients && b[*ptrB].dist < all[farID].dist) {
      ptrB++;
   }

   if (b[*ptrB].nbr == all[farID].nbr) {
      return result;
   }
   int farResult = all[farID].dist +all[x].fatigue;
   int bResult = b[*ptrB].dist + b[*ptrB].fatigue;
   if (bResult > farResult) {
      result -= farResult;
      result += bResult;
   }
//printf ("ptrB = %d, far = %d, b = %d, result = %d\n", *ptrB, farResult, bResult, result);
   return result;
}

void PrintClients (client* a, int n)
{
   printf ("--------\n");
   for (int i = 0; i < n; i++) {
      printf ("f = %d, d = %d, idx = %d\n", a[i].fatigue, a[i].dist, a[i].nbr);
   }
}
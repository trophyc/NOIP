#include <stdio.h>
#include <stdlib.h>

/********************************************************
解题思路：
显然既要取得尽可能多的推销疲劳点，也要取得尽可能多的路程疲劳点。
1. 推销疲劳点要尽可能多，则尽量从最疲劳的向下选。将疲劳点由高到低排序
2. 路程疲劳点，只需要有一个 (2 * 路程 + 推销) 疲劳点最大即可。

两个数组，一个按推销疲劳点由高到低排(all), 另一个按(2 * 路程 + 推销)排 (b).
1. 在all中选前x个。记录最小的推销点和最远距离
2. 在b中，如果有一个 > (记录最小的推销点和最远距离) 的点，那么，
    将最小推销点移除，而加入b中找到的点，即可
    如果最远点与b中的为同一点，则不做任何操作。

********************************************************/
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
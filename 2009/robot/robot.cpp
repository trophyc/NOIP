#include <stdio.h>
#include <limits.h>

#define MAX 1000
int n, m, p;
int coin[MAX][MAX];
int cost[MAX];
int f[MAX][MAX];
int g[MAX][MAX];
int fmax[MAX];

#define max(a,b) ((a)>(b) ? (a) : (b))

void ReadIn();
void Init();
void PrintCoin();
void Calc ();
void CalcG (int time, int road);

int main ()
{
   ReadIn();
   Init();
   Calc();
   printf ("%d\n", fmax[m-1]);
   return 0;
}

void ReadIn()
{
   scanf ("%d %d %d", &n, &m, &p);
 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int tmp;
         scanf ("%d", &tmp);
         if (i - 1 >= 0 && j -1 >= 0) {
            coin[i][j] = tmp + coin[i-1][j-1];
         } else {
            coin[i][j] = tmp;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      scanf ("%d", &cost[i]);
   }
}

void Init()
{
   for (int i = 0; i < m; i ++) {
      fmax[i] = INT_MIN;
   }
   for (int i = 0; i < n; i++) {
      fmax[0] = max (fmax[0], (coin[i][0] - cost[i]));
   }
}

void Calc() 
{
   // i is the ith time slot, j is the jth road.
   for (int i = 1; i < m; i++) {
      int Fmaxi = INT_MIN;
      for (int j = 0; j < n; j++) {
         CalcG (i, j);
         f[j][i] = coin[j][i] + g[j][i];
         Fmaxi = max (Fmaxi, f[j][i]);
      }
      fmax[i] = Fmaxi;
   }
}

void CalcG (int time, int road)
{
   int maxG  = INT_MIN;
   int j = road - p;
   int time1 = (time-p >= 0 ? time - p : 0);
   for (int i = time1 ; i < time; i++) {
      j = i + (road - time);
      int j1 = (j < 0 ? j + n : j);
      maxG = max (maxG, fmax[i] - coin[j1][i] - cost[j1]);
   }
   g[road][time] = maxG;
}


void PrintCoin()
{
   for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j++) {
         printf ("%d ", coin[i][j]);
      }
      printf ("\n");
   }
}

void PrintFmax() 
{
   for (int i = 0; i < n; i++) {
      printf ("%d\n", fmax[i]);
   }
}
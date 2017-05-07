#include <iostream>
#include <memory.h>
#include <stdlib.h>
using namespace std;

struct Point {
   int row, col;
};

struct Pair {
   Point a,b;
};

#define MAX_PAIRS 2000
#define MAX_ROWS 1000
#define MAX_COLS 1000

struct Splitter {
   int no;
   int weight;
};

Splitter splitterH[MAX_ROWS];
Splitter splitterV[MAX_COLS];

#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define MIN(a,b) ((a)>=(b) ? (b) : (a))

int CompareWeight (const void* A, const void* B);
int CompareNo (const void* A, const void* B);
void PrintResult (Splitter* s, int n);

int main ()
{
   int rows, cols, horzs, verts, pairs;
   cin >> rows >> cols >> horzs >> verts >> pairs;

   for (int i = 0; i < rows; i++) {
      splitterH[i].no = i;
      splitterH[i].weight = 0;
   }
   for (int i = 0; i < cols; i++) {
      splitterV[i].no = i;
      splitterV[i].weight = 0;
   }

   for (int i = 0; i < pairs; i++) {
      Pair p;
      cin >> p.a.row >> p.a.col >> p.b.row >> p.b.col;
      if (ABS(p.a.row - p.b.row) == 1) {
         splitterH[min(p.a.row, p.b.row)].weight += 1;
      } else if (ABS (p.a.col - p.b.col) == 1) {
         splitterV[min(p.a.col, p.b.col)].weight += 1;
      }
   }

   qsort (splitterH, rows, sizeof (Splitter), CompareWeight);
   qsort (splitterV, cols, sizeof (Splitter), CompareWeight);

   qsort (splitterH, horzs, sizeof (Splitter), CompareNo);
   qsort (splitterV, horzs, sizeof (Splitter), CompareNo);   

   PrintResult (splitterH, horzs);
   PrintResult (splitterV, verts);
   return 0;
}

int CompareWeight (const void* A, const void* B)
{
   const Splitter* a = (const Splitter*) A;
   const Splitter* b = (const Splitter*) B;

   if (a->weight > b->weight) {
      return -1;
   }
   if (a->weight < b->weight) {
      return 1;
   }
   if (a->no > b->no) {
      return 1;
   }
   return -1;
}

int CompareNo (const void* A, const void* B)
{
   const Splitter* a = (const Splitter*) A;
   const Splitter* b = (const Splitter*) B;

   if (a->no > b->no) {
      return 1;
   }
   if (a->no < b->no) {
      return -1;
   }
   return 0;
}

void PrintResult (Splitter* s, int n)
{
   for (int i = 0; i < n; i ++) {
      cout << s[i].no;
      if (i != n -1) {
         cout << " ";
      }
   }
   cout << endl;
   return;
}
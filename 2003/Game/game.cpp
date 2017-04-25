#include <stdio.h>
#include <memory.h>
#include <assert.h>
using namespace std;

#define MAX_COUNT 50
#define MAX_SEGMENTS 9

int maxMatrix[MAX_COUNT][MAX_SEGMENTS + 1];
int minMatrix[MAX_COUNT][MAX_SEGMENTS + 1];

int ReadFromFile(FILE* file, int* count, int* segments, int v[]);
void PrintReadIns(int count, int segments, int v[]);

void FindMaxAndMin(int v[], int count, int start, int segments, int* max, int* min);
void GetMod(int v[], int count);
void CopyBuffer(int v[], int count);

int main(int argc, char* argv[])
{
   if (argc != 2) {
      fprintf(stderr, "Usage: %s INPUTFILE", argv[0]);
      return -1;
   }

   FILE* file;
   file = fopen (argv[1], "rt");
   if (file == NULL) {
      fprintf(stderr, "Cannot open %s", argv[1]);
      return -1;
   }

   int v[MAX_COUNT*2];
   int count, segments;
   int err = ReadFromFile (file, &count, &segments, v);
   if (err != 0) {
      fprintf(stderr, "Input file format error.\n");
   }

   GetMod(v, count);
   PrintReadIns(count, segments, v);
   CopyBuffer(v, count);

   int max = 0;
   int min = 1000000000;
   for (int i = 0; i < count; i++) {
      int* p;
      p = v + i;
      //initialize the matrice to all -1.
      memset(maxMatrix, 0xff, sizeof(maxMatrix));
      memset(minMatrix, 0xff, sizeof(minMatrix));

      int max_this, min_this;
      FindMaxAndMin(p, count, 0, segments, &max_this, &min_this);
      max = (max < max_this ? max_this : max);
      min = (min > min_this ? min_this : min);
   }
   printf("max = %d, min = %d\n", max, min);
   return 0;
}

int ReadFromFile(FILE* file, int* count, int* segments, int v[])
{
   fscanf (file, "%d %d\n", count, segments);
   if (*count <= 0 || *count < *segments || *count > MAX_COUNT) {
      return -1;
   }
   if (*segments > MAX_SEGMENTS || *segments <= 1) {
      return -1;
   }

   for (int i = 0; i < *count; i++) {
      int d;
      if (fscanf (file, "%d\n", &d) == EOF) {
         return -1;
      }
      v[i] = d;
   }
   return 0;
}

void PrintReadIns(int count, int segments, int v[])
{
   printf ("Total %d numbers should be divided into %d segments.\n", count, segments);
   for (int i = 0; i < count; i++) {
      printf ("%d ", v[i]);
   }
   printf ("\n");
}

void FindMaxAndMin(int v[], int count, int start, int segments, int* max, int* min)
{
   /* if this has been calculated, just reture*/
   if (maxMatrix[start][segments] >= 0) {
      assert(minMatrix[start][segments] >= 0);
      *max = maxMatrix[start][segments];
      *min = minMatrix[start][segments];
      return;
   }
   
   if (segments == 1) {
      /*just sum up*/
      int sum = 0;
      for (int i = start; i < count; i++) {
         sum += v[i];
      }
      sum %= 10;
      maxMatrix[start][1] = sum;
      minMatrix[start][1] = sum;
      *max = sum;
      *min = sum;
      return;
   }

   int end_of_this_segment;
   int sum_of_this_segment = 0;
   int seg_max = 0;
   int seg_min = 1000000000;
   for (end_of_this_segment = start; end_of_this_segment < (count - segments + 1); end_of_this_segment++) {
      sum_of_this_segment += v[end_of_this_segment];
      sum_of_this_segment %= 10;
      int maxRest, minRest;
      FindMaxAndMin(v, count, end_of_this_segment + 1, segments - 1, &maxRest, &minRest);
      int product;
      product = sum_of_this_segment * maxRest;
      if (product > seg_max) {
         seg_max = product;
      }
      product = sum_of_this_segment * minRest;
      if (product < seg_min) {
         seg_min = product;
      }
   }
   *max = seg_max;
   *min = seg_min;
   maxMatrix[start][segments] = seg_max;
   minMatrix[start][segments] = seg_min;
   return;
}

void GetMod(int v[], int count)
{
   for (int i = 0; i < count; i++) {
      v[i] %= 10;
      v[i] = (v[i] < 0 ? v[i] + 10 : v[i]);
   }
}

void CopyBuffer(int v[], int count)
{
   for (int i = 0; i < count; i++) {
      v[i + count] = v[i];
   }
}
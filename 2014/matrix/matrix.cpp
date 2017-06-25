#include <stdio.h>

int n, i, j;
#define abs(a) ((a) >=0 ? (a) : -(a))
#define max(a,b) ((a) > (b) ? (a) : (b))

int GetCircles (int n, int i, int j);

int main ()
{
   scanf ("%d %d %d", &n, &i, &j);
   i--; 
   j--;

   bool odd = (bool) (n%2);
   bool even = !odd;
   int circle = GetCircles (n, i, j);
   int firstOfCircle = n*n;
   if (!even) {
      firstOfCircle -= (2 * circle - 1) * (2 * circle - 1) - 1;
   } else {
      firstOfCircle -= (2 * circle) * (2 * circle) - 1;
   }
   int top, bottom, left, right;
   int allCircles = (even ? n/2 : n/2 + 1);
   int gap = allCircles - circle;
   top = left = gap;
   bottom = right = n - 1 - gap;

   int result = firstOfCircle;
   if (i == top) {
      // the top line,
      result += (j - left);
   } else if (i == bottom) {
      // the bottom line
      result += (right - left) * 2 + (right - j);
   } else if (j == left) {
      // the left line
      result += (right - left) * 3 + (bottom -i);
   } else {
      // the right line;
      result += (right - left) + (i - top);
   }

   printf ("%d\n", result);
   return 0;
}

int GetCircles (int n, int i, int j)
{
   float mid = ((float)n - 1) /2;
   float circle = abs (mid - (float) i);
   circle = max (circle, abs (mid - (float)j));
   return (int)(circle + 1.4); 
}
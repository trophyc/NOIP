#include <iostream>
using namespace std;

int gcd (int a, int b);

int main ()
{
   int x, y;

   cin >> x >> y;

   int t = y/x;

   if (x <= 0 || y <= 0 || y < x || t*x < y) {
      cout << 0 << endl;
      return 0;
   }

   int count = 0;
   for (int i = 1; i <= t; i++) {
      if (t/i*i == t && gcd(i, t/i) == 1 ) {
         cout << i << ",\t" << t/i << endl;
         count ++;
      }
   }
   cout << count << endl;
   return 0;
}

int gcd (int a, int b)
{
   int c = (a > b ? a : b);
   int d = (a > b ? b : a);

   if (c/d * d == c) {
      return d;
   }
   int r = c - c/d * d;
   return gcd (d, r);
}
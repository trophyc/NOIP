#include <iostream>
#include <string>
using namespace std;

void PrintResult (const char* p, int set);

#define MAX  1000
char buf[MAX];

int main ()
{
   char c = '0';
   int i = 0;
   while (c != 'E' && i <MAX) {
      cin >> c;
      buf[i++] = c;
   }

   PrintResult (buf, 11);
   cout << endl;
   PrintResult (buf, 21);
   return 0;
}

void PrintResult (const char* p, int set)
{
   int a = 0;
   int b = 0;
   int i = 0;
   while (p[i] != 'E') {
      if (p[i] == 'W') {
         a++;
      } else if (p[i] == 'L') {
         b++;
      }
      if ((a >= set && a-b >=2) || (b >= set && b-a >= 2)) {
         cout << a << ":" << b << endl;
         a = b = 0;
      }
      i++;
   }
   if (a != 0 || b != 0) {
      cout << a << ":" << b << endl;
   }
}
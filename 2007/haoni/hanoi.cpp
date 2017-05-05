#include <iostream>
using namespace std;

// A(n) = 2* A(n-1) + 2
// A(1) = 2;

int main ()
{
   int n;
   cin >> n;
   int a = 2;
   for (int i = 2; i <=n; i++) {
      a = 2*a + 2;
   }
   cout << a << endl;
   return 0;
}
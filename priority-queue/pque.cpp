#include <cstdio>
#include <queue>
using namespace std;

int main ()
{
   priority_queue<int> pque;
   priority_queue<int, vector<int>, greater<int> > minque;

   pque.push (3);
   pque.push (5);
   pque.push (1);

   printf ("------\n");
   while (!pque.empty()) {
      printf ("%d\n", pque.top());
      pque.pop();
   }
   printf ("------\n");

   minque.push (3);
   minque.push (1);
   minque.push (5);
   while (!minque.empty()) {
      printf ("%d\n",minque.top());
      minque.pop();
   }
   return 0;
}
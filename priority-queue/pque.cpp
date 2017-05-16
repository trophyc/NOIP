#include <cstdio>
#include <queue>
using namespace std;

int main ()
{
   priority_queue<int> pque;

   pque.push (3);
   pque.push (5);
   pque.push (1);

   while (!pque.empty()) {
      printf ("%d\n", pque.top());
      pque.pop();
   }
   return 0;
}
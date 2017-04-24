#include <iostream>

using namespace std;

bool ControlledByHorse (int ptx, int pty, int hrx, int hry);
int dfs (int x, int y, int hrx, int hry, int Bx, int By);

int main ()
{
   int Ax = 0;
   int Ay = 0;
   int Bx, By;
   int hrx, hry;

   cin >> Bx >> By;
   cin >> hrx >> hry;

   int count  = dfs (Ax, Ay, hrx, hry, Bx, By);
   cout << count << endl;
   return 0;
}

#define abs(a) ((a) >= 0 ? (a) : 0-(a))

bool ControlledByHorse (int ptx, int pty, int hrx, int hry)
{
   if (ptx == hrx && pty == hry) {
      return true;
   }
   if (abs(ptx - hrx) == 1 && abs(pty - hry) ==2) {
      return true;
   }
   if (abs (ptx - hrx) == 2 && abs (pty - hry) == 1) {
      return true;
   }
   return false;
}

int dfs (int x, int y, int hrx, int hry, int Bx, int By)
{
   if (x > Bx || y > By || ControlledByHorse (x, y, hrx, hry)) {
      return 0;
   }
   if (x == Bx && y == By) {
      return 1;
   }
   return (dfs (x+1, y, hrx, hry, Bx, By) + dfs (x, y+1, hrx, hry, Bx, By));
}

#include <stdio.h>

class CPoint
{
public:
   CPoint(int x, int y) : m_x(x), m_y(y) {}
   virtual ~CPoint() {};

   int RadiusSquared (CPoint& pt);

   int GetX() {return m_x;}
   int GetY() {return m_y;}

protected:
   int m_x, m_y;
};

int CPoint::RadiusSquared (CPoint& pt)
{
   int x0 = pt.GetX();
   int y0 = pt.GetY();
   return (x0 - m_x) * (x0 - m_x) + (y0 - m_y) * (y0 - m_y);
}

#define MAX(a,b) ((a)>(b) ? (a) : (b))

class CDefense : public CPoint
{
public:   
   CDefense(int x, int y) : CPoint (x, y) {m_MaxSoFar = 0;}
   virtual ~CDefense() {};

   int GetMaxSoFar() {return m_MaxSoFar;}
   void DefendIt (int rsquared) {m_MaxSoFar = MAX (rsquared, m_MaxSoFar);}

protected:
   int m_MaxSoFar;
};

int main ()
{
   int x1, y1, x2, y2;
   scanf ("%d %d %d %d", &x1, &y1, &x2,&y2);
   CDefense A (x1,y1);
   CDefense B (x2,y2);

   int n;
   scanf ("%d", &n);

   for (int i = 0; i < n; i++) {
      int x, y;
      scanf ("%d %d", &x, &y);
      CPoint missile(x, y);
      int maxA = A.GetMaxSoFar();
      int maxB = B.GetMaxSoFar();
      int rA = A.RadiusSquared (missile);
      int rB = B.RadiusSquared (missile);
      if (rA <= maxA || rB <= maxB) {
         continue;
      }
      if (rA < rB) {
         A.DefendIt (rA);
      } else {
         B.DefendIt(rB);
      }
   }

   printf ("%d", A.GetMaxSoFar() + B.GetMaxSoFar());
   return 0;
}



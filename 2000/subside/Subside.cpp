#include <iostream>
#include <vector>
using namespace std;
#include <stdlib.h>

struct Plot
{
   int price;
   int sales;
};

typedef vector<Plot> PlotVector;
#define INC_STEP 2
#define epsilon 0.001
#define abs(x) (x > 0 ? x : -x)

void Readin (int& target, PlotVector& v, int& dec);
void EnlargeVector (PlotVector& v, int i);
void PrintInfo (int target, PlotVector& v, int dec);
int GetSalesByPrice (PlotVector v, int dec, int price);
double CalcLimit (int target_profit, int target_sales, int profit, int sales);
void PrintSubside (double down, double up);

int main ()
{
   PlotVector v(3);
   int target;
   int dec;
    
   Readin (target, v, dec);
   int price = v[0].price;
   int cost = price;   
   int sales = GetSalesByPrice (v, dec, price);
   int target_sales = GetSalesByPrice (v, dec, target);

   double up_limit = 10000;
   double down_limit = -10000; 

   while (sales >= 0 ) {
      if (price != target) {
         double limit; 
         if (sales != target_sales) {
            limit = CalcLimit(target - cost, target_sales, price - cost, sales);
         } else if (price < target) {
            price ++;
            sales = GetSalesByPrice (v, dec, price);
            continue;
         } else {
            cout << "NO SOLUTION" << endl;
            exit(0);
         }

         if (price < target && sales != target_sales) {
            up_limit = (up_limit > limit ? limit : up_limit);
         } else {
            down_limit = (down_limit > limit ? down_limit : limit);
         }
      }
      price ++;
      sales = GetSalesByPrice (v, dec, price);
   }

   PrintSubside (down_limit, up_limit);
   return 0;
}

void Readin (int& target, PlotVector& v, int& dec)
{
   cin >> target;
    
   int price, sales;
   int i = 0;
   do {
      cin >> price >> sales;
      v[i].price = price;
      v[i].sales = sales;
      i++;
      EnlargeVector (v, i);
   } while (price != -1);
   cin >> dec;
}

void EnlargeVector (PlotVector& v, int i)
{
   int size = v.size();
   if (size <= i) {
      v.resize (size + (i-size)/INC_STEP*INC_STEP + INC_STEP);
   }
   return;
}

void PrintInfo (int target, PlotVector& v, int dec)
{
   cout << "=================" << endl;
   cout << target << endl;
    
   int i = 0;
   int price, sales;    
   do {
      price = v[i].price;
      sales = v[i].sales;
      cout << price << "         " << sales << endl;
      i++;
   } while (price != -1);
   cout << dec << endl;
   cout << "=================" << endl;
}

int GetSalesByPrice (PlotVector v, int dec, int price)
{
   if (price < v[0].price) {
      return -1;
   }

   int i = -1; 
   do {
      i++;
   } while (v[i].price != -1 && price > v[i].price);

   if (price == v[i].price) {
      return v[i].sales;
   } else if (price < v[i].price) {
      return (v[i-1].sales - (v[i-1].sales - v[i].sales)/(v[i].price - v[i-1].price) * (price - v[i-1].price));
   }

   int last_price = v[i-1].price;
   int last_sales = v[i-1].sales;
   int sales = last_sales - dec * (price - last_price);
   return sales;
}

double CalcLimit (int profit_target, int target_sales, int profit, int sales)
{
   return ((double)profit_target * (double)target_sales - (double)profit * (double)sales) / ((double)sales - (double)target_sales);
}

void PrintSubside (double down, double up)
{
   if (down > up) {
      cout << "NO SOLUTION" << endl;
      return;
   }
   if (down < 0 && up > 0 ) {
      cout << 0 << endl;
      return;
   }

   int intdown = (int)down;
   int intup = (int)up;

   if (intdown < down) {
      intdown ++;
   }
   if (intup > up) {
      intup --;
   }

   if (intdown >= 0) {
      cout << intdown << endl;
   }
   if (intup <= 0) {
      cout << intup << endl;
   }
   return;
}
#include <stdio.h>

#define MAX 1024

struct Plot {
   int price;
   int sales;
};

Plot input[MAX];
int target_price;
int target_sales;
int dec; // decrease step
int cost;

void ReadIn();
double FindUpperLimit();
double FindLowerLimit();
double CalcLimit (int price, int sales, int target_price, int target_sales);
int GetSalesFromPrice (int price);
void PrintResult(double low, double up);

int main ()
{
   ReadIn();
   double up = FindUpperLimit();
   double low = FindLowerLimit();
   PrintResult (low, up);
   return 0;
}

void ReadIn()
{
   scanf ("%d", &target_price);
   int price = 0;
   int sales;
   int idx = 0;

   do {
      scanf ("%d", &price);
      scanf ("%d", &sales);
      input[idx].price = price;
      input[idx].sales = sales;
      idx++;
   } while (input[idx-1].price != -1);
   scanf ("%d", &dec);
   cost = input[0].price;
   target_sales = GetSalesFromPrice (target_price);
}

double FindUpperLimit()
{
   double upper = 1E10;
   for (int i = cost; i < target_price; i++) {
      int isales = GetSalesFromPrice (i);
      double tmp = CalcLimit(i, isales, target_price, target_sales);
      upper = (upper > tmp ? tmp : upper);
   }
   return upper;
}

double FindLowerLimit()
{
   double lower = -1E10;
   int i = target_price + 1;
   int isales;

   while ((isales = GetSalesFromPrice (i)) > 0) {
      double tmp = CalcLimit(i, isales, target_price, target_sales);
      lower = (lower < tmp ? tmp : lower);
      i++;
   }
   return lower;
}

double CalcLimit (int price, int sales, int target_price, int target_sales)
{
   return ( (double)((price-cost)*sales) - (double)((target_price-cost)*target_sales)) / ((double)(target_sales-sales));
}

int GetSalesFromPrice (int price)
{
   int idx = 0;
   while (input[idx].price != -1 && input[idx].price < price) {
      idx++;
   }
   if (input[idx].price == price) {
      return input[idx].sales;
   }

   int last_price = input[idx-1].price;
   int last_sales = input[idx-1].sales;
   if (input[idx].price != -1) {
      return (input[idx].sales + (input[idx].price - price) * (last_sales - input[idx].sales) / (input[idx].price - last_price));
   }

   return (last_sales - dec * (price - last_price)); 
}

void PrintResult(double low, double up)
{
   if (low >= up) {
      printf ("NO SOLUTION\n");
   }

   if (low < 0 && up > 0) {
      printf ("0\n");
   }

   int intlow = (int)low;
   int intup = (int)up;

   if (intlow < low) {
      intlow ++;
   }
   if (intup > up) {
      intup --;
   }

   if (intlow >= 0) {
      printf ("%d", intlow);
   }
   if (intup <= 0) {
      printf ("%d", intup);
   }
   return;   
}
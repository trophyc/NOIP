#include <stdio.h>

struct date 
{
   int year;
   int month;
   int day;
};

int days[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

date d1, d2;
void Int2Date(int a, date* d);
void GetLoopbackFromYear (int y, date*d);
int DateCmp (const date* a, const date* b);
bool IsDate (const date* d);
bool IsLeapYear (int y);

int main ()
{
   int a;
   scanf ("%d", &a);
   Int2Date(a, &d1);
   scanf ("%d", &a);
   Int2Date(a, &d2);

   int total = 0;
   int y1 = d1.year;
   int y2 = d2.year;

   for (int i = y1; i <= y2; i++) {
      date loopback;
      GetLoopbackFromYear (i, &loopback);
      if (IsDate (&loopback) && DateCmp (&loopback, &d2) <= 0 && DateCmp (&loopback, &d1) >= 0) {
         total ++;
      }
   }

   printf ("%d", total);
   return 0;
}

void Int2Date(int a, date* d)
{
   d->day = a % 100;
   a /= 100;
   d->month = a % 100;
   a /= 100;
   d->year = a;
}

void GetLoopbackFromYear (int y, date*d)
{
   d->year = y;
   d->month = y % 10;
   y /= 10;
   d->month = d->month * 10 + y % 10;
   y /= 10;
   d->day = y % 10;
   y /= 10;
   d->day = d->day * 10 + y % 10;
}

int DateCmp (const date* a, const date* b)
{
   if (a->year > b->year) {
      return 1;
   } else if (a->year < b->year) {
      return -1;
   }

   if (a->month > b->month) {
      return 1;
   } else if (a->month < b->month) {
      return -1;
   }

   if (a->day > b->day) {
      return 1;
   } else if (a->day < b->day) {
      return -1;
   }
   return 0;
}

bool IsDate (const date* d)
{
   if (d->month < 1 || d->month > 12) {
      return false;
   }

   if (d->day < 0 || d->day > days[d->month]) {
      return false;
   }
   if (d->month == 2 && (d->day == 29 && !IsLeapYear (d->year))) {
      return false;
   }
   return true;
}

bool IsLeapYear (int y)
{
   if (y % 400 == 0) {
      return true;
   }
   if (y % 100 == 0) {
      return false;
   }
   if (y % 4 == 0) {
      return true;
   }
   return false;
}
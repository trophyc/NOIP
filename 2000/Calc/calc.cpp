#include <stdio.h>

#define MAX_LINE 1024
#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')
#define IS_LETTER(x) (((x)>='a'&& (x) <='z') || ((x) >='A' && (x) <= 'Z'))

struct Expr {
   int factor;
   int number;
};

int GetNumber (char* str, int& idx);
void GetExpr (char* str, int& idx, Expr& e);
float Calculate (Expr l, Expr r);

int main ()
{
   char input[MAX_LINE];
   scanf ("%s", input);

   Expr left = {0, 0};
   Expr right = {0, 0};

   int idx = 0;
   GetExpr (input, idx, left);
   idx++;
   GetExpr (input, idx, right);
   printf ("%.3f", Calculate(left, right));
   return 0;
}

int GetNumber (char* str, int& idx)
{
   int tmp = 0;
   int sign = 1;
   bool digitFound = false;

   if (str[idx] == '-') {
      sign = -1;
      idx ++;
   } else if (str[idx] == '+') {
      sign = 1;
      idx ++;
   }

   while (IS_DIGIT(str[idx])) {
      digitFound = true;
      tmp *= 10;
      tmp += str[idx] - '0';
      idx++;
   }

   if (digitFound) {
      return (sign * tmp);
   }
   return sign;
}

void GetExpr (char* str, int& idx, Expr& e)
{
   e.factor = 0;
   e.number = 0;
   while (str[idx] != '=' && str[idx] != '\0') {
      int number = GetNumber (str, idx);
      if (IS_LETTER(str[idx])) {
         e.factor += number;
         idx++;
      } else {
         e.number += number;
      }
   }
}

float Calculate (Expr l, Expr r)
{
   float number = r.number - l.number;
   float factor = l.factor - r.factor;
   return (number/factor);
}
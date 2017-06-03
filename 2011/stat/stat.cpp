#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 11

void ToUpperCase (char* str);

int main ()
{
   char toBeFound[WORD_LEN];
   char word[WORD_LEN];
   char c;

   scanf ("%s", &toBeFound);
   scanf ("%c", &c);    // eat up 0x0a and 0x0d
   int ret = scanf ("%c", &c);    // however, from stdin, only 0x0a, while from file could be 0x0a and 0x0d

   ToUpperCase (toBeFound);

   int sum = 0;
   int i = 0;
   if (c == 0x0a || c == 0x0d) {
      ret = scanf ("%c", &c);
   }

   bool matched = true;
   int len = strlen (toBeFound);
   while (ret > 0 && c != 0x0a && c != 0x0d) {
      if (c != ' ' && c != '\t') {
         word[i] = toupper (c);
         if (matched && i < len) {
            matched =( word[i] == toBeFound[i]);
         } else {
            matched = false;
         }
         i++;
      } else {
         word[i] = '\0';
         matched = matched && (i == len);
         sum = (matched ? sum+1 : sum);
         i = 0;
         matched = true;
      }
      ret = scanf ("%c", &c);      
   } 

   printf ("%d\n", sum);
   return 0;
}

void ToUpperCase (char* str)
{
   int i = 0;
   while (str[i] != '\0') {
      str[i] = toupper (str[i]);
      i++;
   }
   return;
}
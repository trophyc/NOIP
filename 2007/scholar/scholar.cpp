#include <iostream>
#include <stdlib.h>
using namespace std;

struct record
{
   int no;
   int chinese;
   int maths;
   int english;
   int total;
};

int Compare (const void* a, const void* b);

int main()
{
   int students;
   cin >> students;
   
   record* scores = new record [students]; 
   for (int i = 0; i < students; i++) {
      scores[i].no = i + 1;
      cin >> scores[i].chinese;
      cin >> scores[i].maths;
      cin >> scores[i].english;
      scores[i].total = scores[i].chinese + scores[i].maths + scores[i].english;
   }

   qsort (scores, students, sizeof (record), Compare);

   for (int i = 0; i < 5; i++) {
      cout << scores[i].no << " " << scores[i].total << endl;
   }
   delete [] scores;
   return 0;
}

int Compare (const void* a, const void* b)
{
   record* A = (record*) a;
   record* B = (record*) b;

   if (A->total < B->total) {
      return 1;
   }
   if (A->total > B->total) {
      return -1;
   }
   if (A->chinese > B->chinese) {
      return -1;
   }
   if (A->chinese < B->chinese) {
      return 1;
   }
   if (A->no < B->no) {
      return -1;
   }
   return 1;
}
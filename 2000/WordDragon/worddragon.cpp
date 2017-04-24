#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> StrVec;

int AttachableLengthByIdx(StrVec* v, int idx1, int idx2, int** links);
int AttachableLength (const char* str1, const char* str2);
int dfs (StrVec* v, int n, int idx, int cur_len, int* uasge, int** links);

int main ()
{
   int n;
   cin >> n;
   char start_char;
   vector<string>* v = new StrVec(n);
   string str;
   for (int i = 0; i < n ; i++) {
      cin >> str;
      (*v)[i] = str;
   }
   cin >> start_char;

   int** word_links = new int* [n];
   for (int i = 0; i < n; i++) {
      word_links[i] = new int [n];
      memset (word_links[i], -1, sizeof (int) * n);
   }

   int* usage = new int[n]; 
   memset (usage, 0, sizeof (int) * n);
   int max = 0;
   for (int i = 0; i < n; i++) {
      if ((*v)[i][0] == start_char) {
          int ret = dfs (v, n, i, strlen ((*v)[i].c_str()), usage, word_links);
          max = (max > ret ? max : ret);
      }
   }

   cout << max << endl;
   delete (v);
   for (int i = 0; i < n; i++) {
      delete [] word_links[i];
   }
   delete [] word_links;
   delete [] usage;
   return 0;
}

int AttachableLength (const char* str1, const char* str2)
{
// if str2 cannot be connected with str1, return 0
// if can, then returns the number of chars that str2 adds to the string.
// str1 = "at", str2 = "tact", "atact", returns 3.
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int min = (len1 > len2 ? len2 : len1);

   if (len1 <= 1 || len2 <= 1) {
      return 0; 
   }

   if (strcmp(str1, str2) == 0) {
       return 0;
   }

   for (int k = min-1; k >=1; k--) {
      bool same = true;
      for (int i = 0; i < k; i++) {
         if (str1[len1-k+i] != str2 [i]) {
             same = false;
             break;
         }
      }
      if (same) {
          return (len2 - k);
      }
   }
   return 0;
}

int AttachableLengthByIdx(StrVec* v, int idx1, int idx2, int** links)
{
   if (idx1 == idx2) {
       links[idx1][idx2] = 0;
      return 0;
   }
   if (links[idx1][idx2] >= 0) {
      return links[idx1][idx2];
   }
   int result = AttachableLength((*v)[idx1].c_str(), (*v)[idx2].c_str());
   links[idx1][idx2] = result;
   return result;
}

int dfs (StrVec* v, int n, int i, int cur_len, int* usage, int** links)
{
   usage[i] ++;

   int max = cur_len;
   for (int j = 0; j < n; j++) {
      if (usage[j] >= 2) {
          continue;
      }
      int attachable = AttachableLengthByIdx (v, i, j, links);
      if (attachable > 0) {
          int ret = dfs(v, n, j, cur_len + attachable, usage, links);
          max = (max > ret ? max : ret);
      }
   }

   usage[i] --;
   return max;
}

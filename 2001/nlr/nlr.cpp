#include <memory.h>
#include <stdio.h>

#define MAX_LEN 8

struct treenode {
   char c;
   int left;
   int right;
};

treenode tree[MAX_LEN];

int cur = 0;

void BuildTree(const char* mid_str, int mstart, int mend, const char* post_str, int pstart, int pend);
int FindCharInSubStr (const char* str, int start, int end, char c);
void PrintTree ();
void PrintPreOrder (int n);

int main ()
{
   char mid_str[MAX_LEN+1];
   char post_str[MAX_LEN+1];
   scanf ("%s %s", mid_str, post_str);

   memset(tree, -1, sizeof (tree));
//   printf ("%s\n%s\n", mid_str, post_str);
   BuildTree (mid_str, 0, strlen(mid_str) - 1, post_str, 0, strlen (mid_str)-1);
//   PrintTree();
   PrintPreOrder (0);
   printf ("\n");
   return 0;
}

int FindCharInSubStr (const char* str, int start, int end, char c)
{
   if (start > end) {
      return -1;
   }
   for (int i = start; i <= end; i++){
      if (c == str[i]) {
         return i;
      }
   }
   return -1;
}

void BuildTree(const char* mid, int mstart, int mend, const char* post, int pstart, int pend)
{
   // the last one of the post string is the root node.
   int tmp = cur;
   tree[tmp].c = post[pend];
   cur++;
   
   int root_pos = FindCharInSubStr (mid, mstart, mend, post[pend]);
   int left_length = root_pos - mstart;
   int right_length = mend - root_pos;

   if (left_length <= 0) {
      // the left node is empty;
      tree[tmp].left = -1;
   } else {
      tree[tmp].left = cur;
      BuildTree(mid, mstart, root_pos-1, post, pstart, pstart + left_length -1);
   }
 
   if (right_length <= 0) {
      // the right node is empty
      tree[tmp].right = -1;
   } else {
      tree[tmp].right = cur;
      BuildTree(mid, root_pos+1, mend, post, pend - right_length, pend - 1);
   }
}

void PrintTree()
{
   for (int i = 0; i < MAX_LEN; i ++) {
      printf ("%d:\t%c, l = %d, r = %d\n", i, tree[i].c, tree[i].left, tree[i].right);
   }
}

void PrintPreOrder (int n)
{
   printf ("%c", tree[n].c);
   if (tree[n].left >=0) {
      PrintPreOrder(tree[n].left);
   }
   if (tree[n].right >= 0) {
      PrintPreOrder (tree[n].right);
   }
}
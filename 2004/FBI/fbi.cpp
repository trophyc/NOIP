#include <iostream>
using namespace std;

struct node {
   char c;
   int left;
   int right;
};

int power (int a, int b);
int BuildParent (node* tree, int start, int end); // returns the number of the parents
void PrintTree_Post (node* tree, int root);

int main ()
{
   int n;
   cin >> n;

   if (n > 10 || n < 0) {
      return -1;
   }

   int len = power (2, n+1);
   node* tree = new node[len];
   

   for (int i = 0; i < len/2; i++) {
      char a;
      cin >> a;
      if (a == '0') {
         tree[i].c = 'B';
      } else if (a == '1') {
         tree[i].c = 'I';
      }
      tree[i].left = -1;
      tree[i].right = -1;
   }
   

   int start = 0;
   int end = len/2 -1;
   int nbr = BuildParent (tree, start, end);
   while (nbr > 1) {
      start = end + 1;
      end = end + nbr;
      nbr = BuildParent (tree, start, end);
   }

   int root = len -2;
   PrintTree_Post (tree, root);
   cout << endl;

   delete [] tree;
   return 0;
}

int power (int a, int b)
{
   int ret = 1;
   for (int i = 0; i < b; i++) {
      ret *= a;
   }
   return ret;
}

int BuildParent (node* tree, int start, int end)
{
   for (int i = 0; i < (end - start +1)/2 ; i++) {
      int left = start + i * 2;
      int right = left + 1;
      int parent = end + i + 1;
      tree[parent].left = left;
      tree[parent].right = right;
      if (tree[left].c == tree[right].c) {
         tree[parent].c = tree[left].c;
      } else {
         tree[parent].c = 'F';
      }
   }
   return (end-start+1)/2;
}

void PrintTree_Post (node* tree, int root)
{
   int left = tree[root].left;
   int right = tree[root].right;
   char c = tree[root].c;

   if (root == -1) {
      return;
   }
   PrintTree_Post(tree, left);
   PrintTree_Post(tree, right);
   cout << c;
}
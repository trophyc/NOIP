#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NODES 100000

struct Node
{
   char op;
   int  left;
   int  right;  
   int  zeros;
   int  ones;    
};

Node nodes[MAX_NODES];
int pCur = 0;

int TreeFromInput (char ending = 0); // return the index of root node.
void PrintMidOrder (int root);
void PrintPostOrder (int root);
int GetOnes (int idx);
int GetZeros (int idx);

#define THIS(x) (nodes[x])
#define LEFT(x) (nodes[x].left)
#define RIGHT(x) (nodes[x].right)

int GetOnes (int idx)
{
   if (THIS(idx).ones != -1) {
      return THIS(idx).ones;
   }

   int leftOnes, leftZeros, rightOnes, rightZeros;

   leftOnes = (THIS(idx).left != -1 ? GetOnes (LEFT(idx)) : 1);
   leftZeros = (THIS(idx).left != -1 ? GetZeros(LEFT(idx)) : 1);
   rightOnes = (THIS(idx).right != -1 ? GetOnes(RIGHT(idx)) : 1);
   rightZeros = (THIS(idx).right != -1  ? GetZeros(RIGHT(idx)) : 1);

   if (THIS(idx).op == '+') {
      THIS(idx).ones = leftOnes * rightOnes % 1007;
      THIS(idx).ones += leftOnes * rightZeros % 1007;
      THIS(idx).ones += leftZeros * rightOnes % 1007;
      THIS(idx).ones %= 1007;
   } else {
      THIS(idx).ones = leftOnes * rightOnes % 1007;
   }
   return THIS(idx).ones;
}

int GetZeros (int idx)
{
   if (THIS(idx).zeros != -1) {
      return THIS(idx).zeros;
   }

   int leftOnes, leftZeros, rightOnes, rightZeros;

   leftOnes = (THIS(idx).left != -1 ? GetOnes(LEFT(idx)) : 1);
   leftZeros = (THIS(idx).left != -1 ? GetZeros(LEFT(idx)) : 1);
   rightOnes = (THIS(idx).right != -1 ? GetOnes(RIGHT(idx)) : 1);
   rightZeros = (THIS(idx).right != -1  ? GetZeros(RIGHT(idx)) : 1);

   if (THIS(idx).op == '*') {
      THIS(idx).zeros = leftZeros * rightOnes % 1007;
      THIS(idx).zeros += leftZeros * rightZeros % 1007;
      THIS(idx).zeros += leftOnes * rightZeros % 1007;
      THIS(idx).zeros %= 1007;
   } else {
      THIS(idx).zeros = leftZeros * rightZeros % 1007;
   }
   return THIS(idx).zeros;
}

int main ()
{
   int dummy;
   scanf ("%d\n", &dummy);

   memset (nodes, -1, sizeof(nodes));
   pCur = 0;

   int root = TreeFromInput ();
//   PrintMidOrder (root);
///   printf ("\n");
//   PrintPostOrder (root);
//   printf ("\n");
   printf ("%d\n", GetZeros(root));
   return 0;
}

int TreeFromInput (char ending)
{
   int root  = -1;
   int rightMost = -1;
   char c;
   int ret = scanf ("%c", &c);

   bool goOn = (ending == 0 ? (c != 0x0a && c != 0x0d && c != 0) : (c != ending)) && (ret != 0);
   while (goOn ) {
      int tmp;
      if (c == '+') {
         tmp = pCur;
         THIS(tmp).op = '+';
         LEFT(tmp) = root;
         root = tmp;
         rightMost = root;
         pCur++;
      } else  if (c == '*' || c == '(') {
         if (c == '*') {
            tmp = pCur;
            THIS(tmp).op = '*';
            pCur++;
         } else {
            tmp = TreeFromInput (')');
         }
         if (root == -1) {
            root = tmp;
            rightMost = tmp;
         } else {
            RIGHT(rightMost) = tmp;
            rightMost = tmp;
         }
      } else {
         exit (1);
      }
      ret = scanf ("%c", &c);
      goOn = (ending == 0 ? (c != 0x0a && c != 0x0d && c != 0) : (c != ending)) && (ret != 0);
   }
   return root;
}

void PrintMidOrder (int root)
{
   if (LEFT(root) != -1) {
      PrintMidOrder (LEFT(root));
   }
   printf ("%c", THIS(root).op);
   if (RIGHT(root) != -1)  {
      PrintMidOrder (RIGHT(root));
   }
}

void PrintPostOrder (int root)
{
   if (LEFT(root) != -1) {
      PrintPostOrder (LEFT(root));
   }
   if (RIGHT(root))  {
      PrintPostOrder (RIGHT(root));
   }
   printf ("%c", THIS(root).op);
}

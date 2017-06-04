#include <stdio.h>
#include <stdlib.h>

class CNode;

CNode* TreeFromInput (char ending = 0);
void PrintMidOrder (CNode* root);
void PrintPostOrder (CNode* root);

class CNode 
{
public:
   CNode (char oprand);
   virtual ~CNode ();

   int GetOnes();
   int GetZeros();

public:
   char m_op;
   CNode* m_left;
   CNode* m_right;

protected:   
   int m_zeros;
   int m_ones;
};

CNode::CNode (char oprand) : m_op (oprand)
{
   m_left = m_right = NULL;
   m_zeros = m_ones = -1;
}

CNode::~CNode()
{
   if (m_left) {
      delete m_left;
   }
   if (m_right) {
      delete m_right;
   }
}

int CNode::GetOnes ()
{
   if (m_ones != -1) {
      return m_ones;
   }

   int leftOnes, leftZeros, rightOnes, rightZeros;

   leftOnes = (m_left ? m_left->GetOnes() : 1);
   leftZeros = (m_left ? m_left->GetZeros() : 1);
   rightOnes = (m_right ? m_right->GetOnes() : 1);
   rightZeros = (m_right ? m_right->GetZeros() : 1);

   if (m_op == '+') {
      m_ones = leftOnes * rightOnes % 1007;
      m_ones += leftOnes * rightZeros % 1007;
      m_ones += leftZeros * rightOnes % 1007;
      m_ones %= 1007;
   } else {
      m_ones = leftOnes * rightOnes % 1007;
   }
   return m_ones;
}

int CNode::GetZeros ()
{
   if (m_zeros != -1) {
      return m_zeros;
   }

   int leftOnes, leftZeros, rightOnes, rightZeros;

   leftOnes = (m_left ? m_left->GetOnes() : 1);
   leftZeros = (m_left ? m_left->GetZeros() : 1);
   rightOnes = (m_right ? m_right->GetOnes() : 1);
   rightZeros = (m_right ? m_right->GetZeros() : 1);

   if (m_op == '*') {
      m_zeros = leftZeros * rightOnes % 1007;
      m_zeros += leftZeros * rightZeros % 1007;
      m_zeros += leftOnes * rightZeros % 1007;
      m_zeros %= 1007;
   } else {
      m_zeros = leftZeros * rightZeros % 1007;
   }
   return m_zeros;
}

int main ()
{
   int dummy;
   scanf ("%d\n", &dummy);
   CNode* root = TreeFromInput ();
//   PrintMidOrder (root);
///   printf ("\n");
//   PrintPostOrder (root);
//   printf ("\n");
   printf ("%d\n", root->GetZeros());
   delete root;
   return 0;
}

CNode* TreeFromInput (char ending)
{
   CNode* root  = NULL;
   CNode* rightMost = NULL;
   char c;
   int ret = scanf ("%c", &c);

   bool goOn = (ending == 0 ? (c != 0x0a && c != 0x0d && c != 0) : (c != ending)) && (ret != 0);
   while (goOn ) {
      CNode* tmp;
      if (c == '+') {
         tmp = new CNode ('+');
         tmp->m_left = root;
         root = tmp;
         rightMost = root;
      } else  if (c == '*' || c == '(') {
         if (c == '*') {
            tmp = new CNode ('*');
         } else {
            tmp = TreeFromInput (')');
         }
         if (!root) {
            root = tmp;
            rightMost = tmp;
         } else {
            rightMost->m_right = tmp;
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

void PrintMidOrder (CNode* root)
{
   if (root->m_left) {
      PrintMidOrder (root->m_left);
   }
   printf ("%c", root->m_op);
   if (root->m_right)  {
      PrintMidOrder (root->m_right);
   }
}

void PrintPostOrder (CNode* root)
{
   if (root->m_left) {
      PrintPostOrder (root->m_left);
   }
   if (root->m_right)  {
      PrintPostOrder (root->m_right);
   }
   printf ("%c", root->m_op);
}
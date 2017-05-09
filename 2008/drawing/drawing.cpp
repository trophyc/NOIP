#include <stdio.h>
#include <memory.h>
#include <string.h>

const char* block[] = {"+---+", 
                      "/   /|",
                     "+---+ |",
                     "|   | +",
                     "|   |/",
                     "+---+"};

#define MAX_WIDTH 50
#define MAX_DEPTH 50
#define MAX_HEIGHT 100

char canvas[3*MAX_HEIGHT + 2*MAX_DEPTH +1][4*MAX_WIDTH + 1 + 2 * MAX_DEPTH];
void DrawBlock (int x, int y);
void Print (int x, int y, int width, int height);
void DrawLayer (int layer, int depth, int width, int x, int y);
int map [MAX_DEPTH][MAX_WIDTH];
void ReadInMap (int depth, int width);

int max_x = 0;
int min_y = 3*MAX_HEIGHT + 2*MAX_DEPTH;
int layers = 0;

#define MAX(a,b) ((a)>=(b) ? (a) : (b))
#define MIN(a,b) ((a)<=(b) ? (a) : (b))

int main ()
{
   int depth, width;

   scanf ("%d", &depth);
   scanf ("%d", &width); 
   ReadInMap (depth, width);

   memset (canvas, '.', sizeof (canvas));
   int orgx = 0;
   int orgy = 3*MAX_HEIGHT + 2*MAX_DEPTH;

   for (int i = 0; i < layers; i++) {
      DrawLayer (i, depth, width, orgx, orgy - 3 * i);
   }
   
   Print (orgx, orgy, max_x+1, (3*MAX_HEIGHT + 2*MAX_DEPTH +1 - min_y));
   return 0;
}

void DrawBlock (int x, int y)
{
   memcpy (&canvas[y-5][x+2], block[0], strlen(block[0]));
   memcpy (&canvas[y-4][x+1], block[1], strlen(block[1]));
   memcpy (&canvas[y-3][x], block[2], strlen(block[2]));
   memcpy (&canvas[y-2][x], block[3], strlen(block[3]));
   memcpy (&canvas[y-1][x], block[4], strlen(block[4]));
   memcpy (&canvas[y][x], block[5], strlen(block[5]));
}

void Print (int x, int y, int width, int height)
{
   for (int i = y-height + 1; i <= y; i++) {
      for (int j = x; j < x+width; j++) {
         printf ("%c", canvas[i][j]);
      }
      printf ("\n");
   }
}

void ReadInMap (int depth, int width)
{
   for (int i = 0; i < depth; i ++) {
      for (int j = 0; j < width; j++) {
         scanf ("%d", &map[i][j]);
         layers = MAX (layers, map[i][j]);
      }
   }
}

void DrawLayer (int layer, int depth, int width, int x, int y)
{
   int x0 = x + 2 * depth;
   int y0 = y - 2 * depth;
   for (int i = 0; i < depth; i ++) {
      y0 += 2;
      x0 -= 2;
      int x1 = x0;
      for (int j = 0; j < width; j++) {
          if (map[i][j] > layer) {
            DrawBlock (x1, y0);
            max_x = MAX(max_x, x1+6);
            min_y = MIN(min_y, y0-5);
         }
         x1 +=4;
      }
   }
}
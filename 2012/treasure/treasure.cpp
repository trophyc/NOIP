#include <stdio.h>

#define MAX_FLOORS 10000
#define MAX_ROOMS 100
#define MOD 20123

struct Room {
   bool stairs;
   int sign;
};

Room rooms[MAX_FLOORS][MAX_ROOMS];
int upRooms[MAX_FLOORS];

int GetRoomUp (int floor, int start, int total, int upRooms);

int main ()
{
   int n, m;

   freopen ("treasure.in", "r", stdin);
   freopen ("treasure.out", "w", stdout);

   scanf ("%d %d\n", &n, &m);
   for (int i = 0; i < n; i++) {
      upRooms[i] = 0;
      for (int j = 0; j < m; j++) {
         int stairs, sign;
         scanf ("%d %d\n", &stairs, &sign);
         rooms[i][j].stairs = (stairs == 1 ? true : false);
         upRooms[i] += stairs;
         rooms[i][j].sign = sign;
      }
   }

   int start;
   scanf ("%d", &start);
   
   int sum = rooms[0][start].sign % MOD;
   for (int i = 0; i < n-1; i++) {
      start = GetRoomUp (i, start, m, upRooms[i]);
      sum += rooms[i+1][start].sign;
      sum %= MOD;
   }

   printf ("%d\n", sum);
   fclose (stdin);
   fclose (stdout);
   return 0;
}

int GetRoomUp (int floor, int start, int total, int upRooms)
{
   int togo = rooms[floor][start].sign % upRooms;
   int i = 0;
   int roomid = start-1;
   do {
      roomid ++;
      roomid = (roomid > total ? 0 : roomid);
      if (rooms[floor][roomid].stairs) {
         i++;
      }
   } while (i < togo);
   return roomid;
}
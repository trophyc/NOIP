#include <stdio.h>
#include <queue>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main ()
{
    priority_queue< int, vector<int>, greater<int> > q;
    int people, taps;
    scanf ("%d %d\n", &people, &taps);

    int time = 0;
    int i = 0;
    for (; i < taps; i++) {
        int next;
        scanf ("%d", &next);
        time = MAX (time, next);
        q.push(next);
    }

    for (; i < people; i++) {
        int next;
        scanf ("%d", &next);
        int top = q.top() + next;
        time = MAX (top, time);
        q.pop();
        q.push(top);
    }

    printf ("%d\n", time);
    return 0;
}
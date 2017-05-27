#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int l, int u);

int main ()
{
    srand (time(0));
    printf ("10000 100\n");

    int j = 0;
    for (int i = 0; i < 10000; i++) {
        printf ("%d", random(1,100));
        j++;
        if (j == 10) {
            j = 0;
            printf ("\n");
        } else {
            printf (" ");
        }
    }
    return 0;
}

int random(int l, int u)
{
    return rand() % (u-l+1) + l;
}
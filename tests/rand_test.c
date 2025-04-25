
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (int i=0;i<100;i++) {
    int ran = rand() % 9;
    printf("%d\n",ran);
    }
    return 0;
}

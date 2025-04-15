#include <stdio.h>
#include "level.c"
//640x480

int main(int argc, char *argv[])
{
    // level_t one = {0};
    level_t one = new_level("levels/level_one.txt","Intro: Hello World!","Prompt: What do you like?",1);

    int status = print_ascii(one);
    printf("Print ascii exit code: %d\n",status);


    return 0;
}

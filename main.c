#include <stdio.h>
#include "level.c"
//640x480

int main(int argc, char *argv[])
{
    // level_t one = {0};
    char *intro_l1 = "Intro: Hello World!";
    char *prompt_l1 = "Prompt: What do you like?";
    level_t one = new_level("levels/level_one.txt",intro_l1,prompt_l1,1);

    int status = print_ascii(one);
    printf("Print ascii exit code: %d\n",status);

    return 0;
}

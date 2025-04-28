#include "../dialogue.c"
#include <stdio.h>

int main()
{
    char ret='0';

    while (ret=='0') {

    printf("Enter any character\n");
    ret = requestChar();
    printf("%c was returned\n",ret);

    }

    mysteriousManIntro();
    return 0;
}

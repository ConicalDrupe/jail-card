#include <stdio.h>
#include <stdlib.h>
#include "level.h"
#include "utils.c"
// implementation

level_t new_level(char *ascii_path, char *intro_p, char *prompt_p, int num) {
    level_t level = {
        .ascii_path = ascii_path,
        .intro_p = intro_p,
        .prompt_p = prompt_p,
        .num = num
    };
    return level;
}


void prompt(level_t level,int loss_count) {
    int response;
    printf("%s\n",level.prompt_p);
    scanf("%d",&response);
    if (loss_count ==2) {
        printf("You LOSE!\n");
        exit(0);
    }
    else if (response==1){
        printf("Correct!\n");
    }
    else if (response==2){
        printf("Incorrect\n");
        prompt(level,loss_count+1);
    }
    else if (response==3){
        printf("Incorrect\n");
        prompt(level,loss_count+1);
    }
    else if (response==4){
        printf("Incorrect\n");
        prompt(level,loss_count+1);
    }
    else {
        printf("Don't spit that Jibbrish at me!\n");
        prompt(level,loss_count);
    }
}

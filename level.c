#include <stdio.h>
#include "level.h"
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

int print_ascii(level_t level) {
    FILE *fp;
    char buffer[100];

    fp = fopen(level.ascii_path,"r");

    if (fp==NULL){
        printf("Could not find file");
        return 1;
    }

    while(fgets(buffer,sizeof(buffer),fp) != NULL){
        printf("%s",buffer);
    }

    fclose(fp);
    return 0;
}

#pragma once

typedef struct Level {
    char *ascii_path;
    char *intro_p;
    char *prompt_p;
    int num;
} level_t;

level_t new_level(char *ascii_path,char *intro_p, char *promp_p, int num);

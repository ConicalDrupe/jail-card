#pragma once
#include "utils.c"

typedef struct Puzzle {
    char *question;
    char *art_path;
    char *answer; //correct answer
    int opt_n; //number of options
    char *options[4]; //array of 4 pointers, that each point to the beggining of an string (array of chars)
} puzzle_t;

puzzle_t create_puzzle(char *question,char *art_path, char *options[4], char *answer, int opt_n) {
    puzzle_t new_puzzle;
    new_puzzle.question = question;
    new_puzzle.art_path = art_path;
    new_puzzle.answer = answer;
    new_puzzle.opt_n = opt_n;

    int i;
    for (i=0; i<opt_n; i++){
        new_puzzle.options[i] = options[i];
    }

    return new_puzzle;
}

void play_puzzle(puzzle_t Puzzle) {
    int number_of_attempts = 0;

    if (Puzzle.art_path != NULL) {
        print_art(Puzzle.art_path);
        printf("\n");
    }

    while (1) {
    printf("%s\n",Puzzle.question);
    for (int i = 0; i<Puzzle.opt_n;i++){
        printf("%s",Puzzle.options[i]);
        }

    char *user_response;
    scanf("%s",user_response);
    if (user_response==Puzzle.answer) {

        }
    else if (number_of_attempts==2) {
            printf("Too bad, You DIED!\n");
            // display death screen
            exit(0);
        }
    else {
        number_of_attempts++;
        }
    }
};

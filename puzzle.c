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
    if (Puzzle.art_path != NULL) {
        print_art(Puzzle.art_path);
    }
    // else if () {
    //
    // }
    // else {
    //
    // }
};

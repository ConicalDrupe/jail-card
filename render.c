#pragma once

#include <string.h>
#include <stdio.h>
#include "card.c"

// Needs to be redone with board layout in mind
// Canvas size [80x20] = 1600
// Left padding 
// Opponent Hand
// Your Hand
//
// Think of it as a grid? We can access array elemnts.



char Canvas[20][81]; // 1620 bytes, extra 20 for null terminator on each row
//
// Each is 20 bytes. So all together are 9x20 = 180 bytes
// MUST MAKE ROOM FOR NULL TERMINATOR! so expand from 5 bytes to 6
static char ace_art[4][6] = {"*---*","| A |","|   |","*---*"};
static char king_art[4][6] = {"*---*","| K |","|   |","*---*"};
static char queen_art[4][6] = {"*---*","| Q |","|   |","*---*"};
static char jack_art[4][6] = {"*---*","| J |","|   |","*---*"};
static char two_art[4][6] = {"*---*","| 2 |","|   |","*---*"};
static char three_art[4][6] = {"*---*","| 3 |","|   |","*---*"};
static char four_art[4][6] = {"*---*","| 4 |","|   |","*---*"};
static char five_art[4][6] = {"*---*","| 5 |","|   |","*---*"};
static char unkn_art[4][6] = {"*---*","| ? |","|   |","*---*"};

// Left Padding for number of cards. 1 Card, 2 Cards, 3 Cards, 4 Cards, 5 Cards
char *one_card_pad = "";
char *two_card_pad = "";
char *three_card_pad = "";
char *four_card_pad = "";

// Left padding for game board option rendering. 2 options (call or fold), 3 options (call, play or fold)


// User for O(n) time complexity
char *mystrcat(char* dest, char* src) {
    while (*dest) dest++;
    while (*dest++ = *src++);
    return --dest;
}


// Needs to be redone for the board
// Left pad
void renderCards(card_t cards_arry[], int num_of_cards, int prompt_flag) {
    int unseen_card=0;

    // Iterate over lines
    for (int ln=0;ln<4;ln++) {
        // iterate over cards
        for (int i=0;i<num_of_cards;i++) {
            card_t current_card = cards_arry[i];

            // if padding, print padding here
            // printf("%s",middle_pad)
            // printf("%s",oponent_pad)
            // printf("%s",player_pad)
            // printf("%s",options_pad)

            // Print card line by line
            switch (current_card.name) {
                case 'A':
                    printf("%s ",ace_art[ln]);
                    break;
                case 'K':
                    printf("%s ",king_art[ln]);
                    break;
                case 'Q':
                    printf("%s ",queen_art[ln]);
                    break;
                case 'J':
                    printf("%s ",jack_art[ln]);
                    break;
                case '5':
                    printf("%s ",five_art[ln]);
                    break;
                case '4':
                    printf("%s ",four_art[ln]);
                    break;
                case '3':
                    printf("%s ",three_art[ln]);
                    break;
                case '2':
                    printf("%s ",two_art[ln]);
                    break;
                case '?':
                    printf("%s ",unkn_art[ln]);
                    break;
                default:
                    printf("Render could not find card name %c",current_card.name);
                    break;
            }
        }
        printf("\n");
    }
    // Here is the user inputs on display (could depend on user controls)
    if (prompt_flag ==1) {
        for (int car=0; car<num_of_cards; car++) {
            printf("  [%d]   ",car+1);
        }
        printf("\n");
    }

}

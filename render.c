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

// TWO OPTIONS FOR PADDING. 1) string cat 2) Pointer fun in canvas array.
// StringCat uses more RAM, because we copy two strings in memory into a new string
// Pointer method uses less memory, because we just alter the values we already initialized
//one card, 36 whitespaces
//two cards, 33 whitespaces
//three cards, 30 whitespaces
//four cards, 27 whitespaces
//five cards, 24 whitespaces
static char oneCardPad[37] = "                                    ";
static char twoCardPad[34] = "                                 ";
static char threeCardPad[31] = "                              ";
static char fourCardPad[28] = "                           ";
static char fiveCardPad[25] = "                        ";

// Left padding for game board option rendering. 2 options (call or fold), 3 options (call, play or fold)
// 28 white spaces, then 9 between call/fold. 26 for (-5 coins), then 6 spaces to (-1 card)
//call,fold
static char lpad_two_opts[29] = "                            ";
static char between_two_opts[10] = "         ";
static char sub_lpad_two_opts[27] = "                          ";
static char sub_between_two_opts[7] = "      ";
//call,play,fold
static char lpad_three_opts[23] = "                      ";
static char between_three_opts[8] = "       ";
static char sub_lpad_three_opts[21] = "                    ";
static char sub_between_three_opts[4] = "   ";
// 22 white spaces, then 7 between each
// 20 white spaces til (-5 coins), then 3 till each (play card) and (-1 card)


// User for O(n) time complexity
char *mystrcat(char* dest, char* src) {
    while (*dest) dest++;
    while (*dest++ = *src++);
    return --dest;
}


// Needs to be redone for the board
// Left pad
void renderCards(card_t cards_arry[], int num_of_cards) {

    // Iterate over lines
    for (int ln=0;ln<4;ln++) {
        // Padding then iterate over cards

        switch (num_of_cards) {
            case 1:
                printf("%s",oneCardPad);
                break;
            case 2:
                printf("%s",twoCardPad);
                break;
            case 3:
                printf("%s",threeCardPad);
                break;
            case 4:
                printf("%s",fourCardPad);
                break;
            case 5:
                printf("%s",fiveCardPad);
                break;
            default:
                printf("\n\n\n\n");
                break;
        }

        for (int i=0;i<num_of_cards;i++) {
            card_t current_card = cards_arry[i];


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

}

void renderGame(player_t player,player_t opponent,card_t board_cards[5],int options_flag) {

    int opp_len = opponent.num_cards;
    int plr_len = player.num_cards;
    // Need to correct padding - 33 spaces
    // printf("%s",twoCardPad);
    printf("%s","                                 ");
    printf("%s","Enemy Hand\n");
    renderCards(opponent.inventory,opp_len);
    printf("\n");
    renderCards(board_cards,5);

    printf("\n");
    // Need to correct padding- 34 spaces
    printf("%s","                                  ");
    printf("%s","Your Hand\n");
    renderCards(player.inventory,plr_len);

    printf("\n");

    switch (options_flag) {
        case 2:
            // padding for options
            // padding for description
            printf("%s",lpad_two_opts);
            printf("[c]all%s[f]old\n",between_two_opts);
            printf("%s",sub_lpad_two_opts);
            printf("(-5 coins)%s(-1 card)",sub_between_two_opts);
            printf("\n");
            break;
        case 3:
            printf("%s",lpad_three_opts);
            printf("[c]all%s[p]lay%s[f]old\n",between_three_opts,between_three_opts);
            printf("%s",sub_lpad_three_opts);
            printf("(-5 coins)%s(play card)%s(-1 card)",sub_between_three_opts,sub_between_three_opts);
            printf("\n");
            break;
        default:
            printf("[renderGame] %d is not a valid options_flag",options_flag);
            break;
    }
}

#pragma once
#include <stdlib.h>
#include <stdio.h>

// typedef enum {
//     INTRO,
//     TUTORIAL,
//     LEVEL1,
//     LEVEL2,
//     SHOP,
//     // FREEPLAY
//     SLEEP,
//     BOSS,
//     DEAD
// } State;


// Can we make a dialogue function that takes advantage of tail reccursion?
typedef struct Dialogue dialogue_t;
typedef struct Dialogue {
    char *question;
    char answer;
    char art_path[16];
    dialogue_t *next;
} dialogue_t;

// dialogue_t = createDialogue(char q*,char answer,char art_path[16],dialogue_t *next);
//runDialogue()

State GAMESTATE = INTRO; //meets mysterious man

char requestChar(void) {
    char buffer[2];
    int success = scanf("%c",&buffer[0]);
    if (success!=1){
        return '0';
    }
    else {
        return buffer[0];
    }
}


char requestEnter(void) {
    char buffer[2];
    scanf("%99[^\n]%*c",buffer);
    return '1';
}

int mysteriousManIntro() {
    // render room
    // render face
    // render question in window
    char *intro_l3 = "Well look-ey here, a newcomer! eheheh!\nAs dazed as they come!\nA word of advice, give the gaurds what they ask for and you'll make it to tommorow.\n";
    char *prompt_l3 = "[1] Who are you?\n[2] How do I get out of here?\n";
    while(1) {
        printf("GameState: %d\n",GAMESTATE);
        char c;
        c = requestChar();
        switch (c) {
            case '1':
                printf("Mysterious Man:\n");
                printf("I am just like you, inprisoned unfairly for gambling... The Castle has been cracking down us for as long as I remember.\n");
                break;
            case '2':
                printf("Mysterious Man:\n");
                printf("\n<The man lets out a chuckle>\nAhh the same way you got in.\n I was in your position once, a caged animal. I played cards until the Castle could't ignore me anymore\n. In a way they need gamblers like you and I.\n");
                printf("Those who run out of luck don't make it.\n");
                GAMESTATE = INHAND; // global, would move to TUTORIAL once game mechanics work
                break;
            default:
                printf("What did you say? Try again.\n");
                break;
        }
    }

};

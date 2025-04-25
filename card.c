#pragma once

#include <stdlib.h>
#include <stdio.h>


typedef enum {
    TWO=0,
    THREE=1,
    FOUR=2,
    FIVE=3,
    JACK=4,
    QUEEN=5,
    KING=6,
    ACE=7,
    UNKNOWN=100,

} CardType;

typedef struct Card {
    CardType type;
    int value;
    char name;
} card_t;



// Essentially a card Factory
// Takes 1-14 as values, or 100 for unknown card
card_t createCard(CardType type) {
    card_t card;

    switch (type) {
        case TWO:
            card.type = TWO;
            card.value = 2;
            card.name = '2';
            return card;
        case THREE:
            card.type = THREE;
            card.value = 3;
            card.name = '3';
            return card;
        case FOUR:
            card.type = FOUR;
            card.value = 4;
            card.name = '4';
            return card;
        case FIVE:
            card.type = FIVE;
            card.value = 5;
            card.name = '5';
            return card;
        case JACK:
            card.type = JACK;
            card.value = 11;
            card.name = 'J';
            return card;
        case QUEEN:
            card.type = QUEEN;
            card.value = 12;
            card.name = 'Q';
            return card;
        case KING:
            card.type = KING;
            card.value = 13;
            card.name = 'K';
            return card;
        case ACE:
            card.type = ACE;
            card.value = 14;
            card.name = 'A';
            return card;
        case UNKNOWN:
            card.type = UNKNOWN;
            card.value = 0;
            card.name = '?';
            return card;
        default:
            printf("Unknown CardType %d",type);
            return card;
}
}

card_t generateCard(void) {
    int rand_num = rand() % 8;
    card_t new_card = createCard(rand_num);
    return new_card;
}

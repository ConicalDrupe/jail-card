#pragma once

typedef struct Card {
    int id;
    char name;
} card_t;

char returnCardName(int card_id) {
    switch (card_id):
        case 0:
            return 'A';
        case 1:
            return 'K';
        case 2:
            return 'Q';
        case 3:
            return 'J';
        case 4:
            return '5';
        case 5:
            return '4';
        case 6:
            return '3';
        case 7:
            return '2';
}

// Essentially a card Factory
card_t createCard(int gen_value) {
    card_t card;

    switch (gen_value):
        case 0:
            card.id = 7;
            card.name = '2';
            return card;
        case 1:
            card.id = 6;
            card.name = '3';
            return card;
        case 2:
            card.id = 5;
            card.name = '4';
            return card;
        case 3:
            card.id = 4;
            card.name = '5';
            return card;
        case 4:
            card.id = 3;
            card.name = 'J';
            return card;
        case 5:
            card.id = 2;
            card.name = 'Q';
            return card;
        case 6:
            card.id = 1;
            card.name = 'K';
            return card;
        case 7:
            card.id = 0;
            card.name = 'A';
            return card;
    default:
        card.id = 100;
        card.name = '?';
        return card;
}

card_t generateCard(void) {
    int rand_num = rand() % 8;
    card_t new_card = createCard(rand_num);
    return new_card;
}

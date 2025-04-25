#pragma once

typedef struct Card card_t;

typedef struct Player {
    card_t inventory[5];
    int chips;
    int num_cards;
    unsigned int seed;
} player_t;

void addCard(player_t *player);
void removeCard(player_t *player);
void addChips(player_t *player);
void removeChips(player_t *player);

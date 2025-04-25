#pragma once
#include "card.c"

typedef struct Card card_t;

typedef struct Player {
    card_t inventory[5];
    int chips;
    int num_cards;
    unsigned int seed;
} player_t;

void addCard(player_t player,card_t card){
    if (num_cards < 5) {
        player.inventory[num_cards] = card;
        player.num_cards++;
    }
    else {
        printf("Inventory is full");
    }
}

void removeCard(player_t player) {
    if (player.num_cards > 1) {
        int idx_to_remove = rand() % num_cards;
        if (idx_to_remove == num_cards-1) {
            player.inventory[num_cards-1] = {0};
            player.num_cards--;
        }
        else {
            card_t *ptr_to_card = &player.inventory[idx_to_remove];
            ptr_to_card = player.inventory[num_cards-1];
            player.inventory[num_cards-1] = {0}; //removing dulpicate card
            player.num_cards--;
        }
    }
};

void addChips(player_t player, int amount) {
    player.chips += amount;
}

void removeChips(player_t player, int amount){
    if (player.chips > amount) {
        player.chips -= amount;
    }
    else {
        player.chips = 0;
    }
}

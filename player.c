#pragma once
#include "card.c"

typedef struct Card card_t;

typedef struct Player {
    card_t inventory[5];
    char *name;
    int chips;
    int num_cards;
    unsigned int seed;
} player_t;

// MUST INSTATIATE PLAYER, else we get bad values for chips/num_cards by default.
player_t createPlayer(char *name) {
    player_t player = {.name = name};
    return player;
}

void addCard(player_t *player,card_t card){
    if (player->num_cards < 5) {
        player->inventory[player->num_cards] = card;
        // int *nCards_ptr = &player.num_cards;
        player->num_cards++;
        // printf("From struct directly: %d\n",player->num_cards);
        // printf("From pointer: %d\n",*nCards_ptr);
        // player.num_cards = player.num_cards + 1;
    }
    else {
        printf("Inventory is full\n");
    }
}

void removeCard(player_t *player) {
    int n = player->num_cards;
    if (n > 0) {
        int idx_to_remove = rand() % n;
        printf("removeCard() chose index %d\n",idx_to_remove);
        if (idx_to_remove == n-1) {
            // card_t *ptr_to_card = &player.inventory[n-1];
            // *ptr_to_card = createCard(100);//{0};
            player->inventory[n-1] = createCard(100);
            player->num_cards--;
        }
        else {
            // If not the last card in inventory, swap with last card & clear marked card.
            card_t *temp = &player->inventory[n-1]; //last card in inventory
            card_t *ptr_to_card = &player->inventory[idx_to_remove];
            *ptr_to_card = *temp;
            player->inventory[n-1] = createCard(100); //removing dulpicate card
            // *temp = createCard(100);
            player->num_cards--;
        }
    }
    else {
        printf("%s has no cards to remove\n",player->name);
        printf("Player has %d cards\n",player->num_cards);
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

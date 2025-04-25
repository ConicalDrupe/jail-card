#include "../card.c"
#include "../player.c"
#include "../render.c"
#include <stdio.h>


int main()
{
    player_t player;
    player_t mystery_man;

    card_t my_card = generateCard();
    printf("Card name %c\n",my_card.name);

    player.inventory[0] = generateCard();
    player.inventory[1] = generateCard();
    player.num_cards = 2;

    mystery_man.inventory[0] = generateCard();
    mystery_man.inventory[1] = generateCard();
    mystery_man.inventory[2] = generateCard();
    mystery_man.num_cards = 3;

    // card_t board[5] = {generateCard(),generateCard(),generateCard(),generateCard(),generateCard()};

    card_t board[5];
    board[0] = generateCard();
    board[1] = generateCard();
    board[2] = generateCard();
    board[3] = generateCard();
    board[4] = generateCard();

    renderGame(player,mystery_man,board,3);

    // char ace_art[4][5] = {"*---*","| A |","|   |","*---*"};
    // printf(" %s ",ace_art[0]);
    // printf("\n");
    return 0;
}


#include "../player.c"
#include "../render.c"

int main()
{
    // IMPORTANT! Instantiate every player, so they start with 0 chips and 0 cards.
    player_t player = {0};

    printf("player.num_cards %d\n",player.num_cards);
    // player.inventory[0] = createCard(1);
    card_t temp = generateCard();

    // card_t temp = createCard(7); //bug
    // player.inventory[0] = createCard(7);
    player.num_cards++;


    addCard(player,temp);
    renderCards(player.inventory,1);

    return 0;
}

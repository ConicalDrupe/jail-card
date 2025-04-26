
#include "../player.c"
#include "../render.c"

int main()
{
    // IMPORTANT! Instantiate every player, so they start with 0 chips and 0 cards.
    player_t player = createPlayer("PlayerTest");

    printf("player.num_cards %d\n",player.num_cards);

    addCard(&player,generateCard());
    renderCards(player.inventory,1);
    printf("New Number of cards after addCard(): %d\n",player.num_cards);

    removeCard(&player);
    printf("New Number of cards after removeCard(): %d\n",player.num_cards);

    printf("Displaying 1 cards:\n");
    renderCards(player.inventory,1);

    ////////////////////////////////////////////
    printf("\n\n\n");
    player_t player2 = createPlayer("PlayerTest2");

    printf("player2.num_cards %d\n",player2.num_cards);

    addCard(&player2,generateCard());
    addCard(&player2,generateCard());
    addCard(&player2,generateCard());
    renderCards(player2.inventory,player2.num_cards);
    printf("New Number of cards after addCard(): %d\n",player2.num_cards);

    removeCard(&player2);
    printf("New Number of cards after removeCard(): %d\n",player2.num_cards);

    printf("Displaying 3 cards:\n");
    renderCards(player2.inventory,player2.num_cards+1);

    return 0;
}

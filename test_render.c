#include "render.c"
#include <stdio.h>

int main()
{
    card_t my_card = generateCard();
    // char card_name = returnCardName(my_card.id);

    printf("Card name %c\n",my_card.name);

    card_t card_arry[1];
    card_arry[0] = my_card;
    card_arry[1] = generateCard();
    renderCards(card_arry,2,0);


    // char ace_art[4][5] = {"*---*","| A |","|   |","*---*"};
    // printf(" %s ",ace_art[0]);
    // printf("\n");
    return 0;
}

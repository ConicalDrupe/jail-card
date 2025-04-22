#include "render.c"
#include <stdlib.h>
#include <stdio.h>


    /* Card game states */
/*
 *  - the flop (1st 2 cards)
 *  - call or play card. *playing a card keeps it in your inventory, until you lose.
 *   -> [c] the river (3 cards)
 *   or
 *   ->  [p]->[num] , play card into hand, (the river is only 2 cards)
 *      - costs 5 coins and play 1 card
 *  - the river (3 cards)
 */

// ** Logic to rank card collection
// - Takes pointer to card_t array
// prime point system?
// Straight? A234, JQKA, 345A, JQKA

// render other character cards



// Should be within game loop?
// if day ==1 then mysterious character, gaurd, then sleep
// if day ==2 shop, then gaurd, mysterious character then sleep
// if day ==3 gaurd, then shop, then sleep
// if day ==4 final battle, escape
int main()
{
    typedef struct Player {
        card_t inventory[5];
        int num_cards;
    } player_t;

    player_t player;
    player.num_cards=0;

    card_t first_card = createCard(1);
    player.inventory[0] = first_card;
    player.num_cards++;
    //


    // Game 1
    // What is the proper abstraction.
    /*
     1) Render 5 Cards (only show 2)
     2) (reference character inventory, enemy inventory)
     3) (c)all or (f)old [A.k.a continue or fold and loose currency/card]
     4) Show new card (show 3 total, 2 unknown). Show 1 of adversaries
     5) (c)all or (f)old
     6) calculate best score (straight, pairs, triples)
     7) Declare winner
     8) Loose card, or gain card
     9) if no cards left, player dies
    */

    // 1.a) Generate hand and render

    card_t hand[5];
    for (int i=0;i<5;i++){
        hand[i] = generateCard();
    }


    // 1.b) Render Hand, only showing 3
    card_t flop[5];
    flop[0] = hand[0];
    flop[1] = hand[1];
    flop[2] = hand[2];
    flop[3] = createCard(100);
    flop[4] = createCard(100);
    renderCards(flop,5,0);

    // print player inventory
    printf("\n");
    printf("Inventory:\n");
    renderCards(player.inventory,player.num_cards,0);
    printf("\n");

    // Prompt player to call or fold
    // call -10 coins, fold (lose a card)
    while (1) {
        char c_buffer[2];
        printf("\t[c]all (-5 coins)\n");
        printf("\t[f]old (-1 card)\n");
        scanf("%s",c_buffer);
        if (c_buffer == 'c') {
            //
            //continue game
            //
            //Choose the card to pair fill ? spot
            //
        }
        else if (c_buffer =='f') {
            //
            //are you sure you want to forfiet? You cannot get this card back after you lost it. [y]es/[n]o
            printf("Are you sure you want to forfiet? You will loose 1 card.\n [y]es/[n]o\n");
            //end game dialogue, give consequence to player

        }
        else {
            printf("Enter c or f.");
        }
    }

    return 0;
}

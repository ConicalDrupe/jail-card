#include <string.h>
#include <stdio.h>

typedef struct Card {
    int value;
    char name;
    char art[6][8];
} card_t;

// Essentially a card Factory
card_t createCard(int value) {
    card_t card;

    if (value==1) {
        card.value = 1;
        card.name = '2';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|2    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    2|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==2) {
        card.value = 2;
        card.name = '3';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|3    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    3|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==3) {
        card.value = 3;
        card.name = '4';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|4    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    4|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==4) {
        card.value = 4;
        card.name = '5';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|5    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    5|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==0) {
        card.value = 0;
        card.name = 'A';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|A    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    A|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==5) {
        card.value = 5;
        card.name = 'J';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|J    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    J|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==6) {
        card.value = 6;
        card.name = 'Q';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|Q    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    Q|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==7) {
        card.value = 7;
        card.name = 'K';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|K    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    K|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (value==100) {
        card.value = 0;
        card.name = '?';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|?    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    ?|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else {
        printf("Not valid value map %d\n",value);
    }

    return card;
}

void renderCard(card_t,int offset){
}

typedef struct Hand {   
    // card_t[5] cards_arry;
    int seed;
} hand_t;

void renderCards(card_t cards_arry[], int num_of_cards, int prompt_flag) {

    // Iterate over lines
    for (int ln=0;ln<6;ln++) {
        // iterate over cards
        for (int i=0;i<num_of_cards;i++) {
            card_t current_card = cards_arry[i];
            printf("%s ",current_card.art[ln]);
        }
        printf("\n");
    }
    // Here is the user inputs on display (could depend on user controls)
    if (prompt_flag ==1) {
        for (int car=0; car<num_of_cards; car++) {
            printf("  [%d]   ",car+1);
        }
        printf("\n");
    }

}


// int main()
// {
//     card_t Two = createCard(2);
//     card_t Ace = createCard(14);
//     card_t Queen = createCard(12);
//     card_t King = createCard(13);
//     card_t Jack = createCard(11);
//     // for (int i=0;i< 6;i++) {
//     //     printf("%s\n",two.art[i]);
//     // }
//     card_t current_cards[5] = {Two,Ace,Queen,King,Jack};
//     renderCards(current_cards,5,1);
//     return 0;
// }

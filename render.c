#include <string.h>
#include <stdio.h>

typedef struct Card {
    int value;
    char name;
    char art[6][8];
} card_t;

// Essentially a card Factory
card_t createCard(char name) {
    card_t card;

    if (name=='2') {
        card.value = 2;
        card.name = '2';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|2    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    2|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='3') {
        card.value = 3;
        card.name = '3';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|3    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    3|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='4') {
        card.value = 4;
        card.name = '4';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|4    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    4|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='5') {
        card.value = 5;
        card.name = '5';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|5    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    5|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='A') {
        card.value = 14;
        card.name = 'A';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|A    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    A|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='J') {
        card.value = 11;
        card.name = 'J';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|J    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    J|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='Q') {
        card.value = 12;
        card.name = 'Q';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|Q    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    Q|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else if (name=='K') {
        card.value = 12;
        card.name = 'K';

        strcpy(card.art[0],"+-----+");
        strcpy(card.art[1],"|K    |");
        strcpy(card.art[2],"|     |");
        strcpy(card.art[3],"|     |");
        strcpy(card.art[4],"|    K|");
        strcpy(card.art[5],"+-----+");
        return card;
    }
    else {
        printf("Not valid char %c\n",name);
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
//     card_t Two = createCard('2');
//     card_t Ace = createCard('A');
//     card_t Queen = createCard('Q');
//     card_t King = createCard('K');
//     card_t Jack = createCard('J');
//     // for (int i=0;i< 6;i++) {
//     //     printf("%s\n",two.art[i]);
//     // }
//     card_t current_cards[5] = {Two,Ace,Queen,King,Jack};
//     renderCards(current_cards,5,1);
//     return 0;
// }

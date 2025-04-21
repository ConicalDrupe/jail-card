#include <string.h>
#include <stdio.h>
// Initialize Card paths in global state
//
// char two_art[7][5] = {"+-----+", "|     |", "|     |", "|     |", "+-----+"};

typedef struct Card {
    int value;
    char name;
    char art[6][8];
} card_t;

// 1
// 2
// 3
// 4
// 5
//
// A
// K
// Q
// J

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
        printf("Not valid char%c\n",name);
    }

    return card;
}

void renderCard(card_t,int offset){
}

typedef struct Hand {   
    // card_t[5] cards_arry;
    int seed;
} hand_t;

void renderCards(card_t cards_arry[], int num_of_cards) {
    char Canvas[1600]; //17x70 , round up to, go 80x60 = 5200, or 80x(length of longest artwork) = 80x20 = 1600
    //
    int card_height = 6; //card height
    int card_width = 7;
    int line_numbers = card_height + 2; // 2 or number options [1] [2] [3] [4]

    int num_spaces = num_of_cards-1;

    // width of each card, plus 1 space between each
    int max_width = card_width*num_of_cards + num_of_cards-1;

    // Iterate over lines
    for (int ln=0;ln<6;ln++) {
        // iterate over cards
        for (int i=0;i<num_of_cards;i++) {
            card_t current_card = cards_arry[i];
            printf("%s ",current_card.art[ln]);
        }
        printf("\n");
    }

    // for (int i=0;i< num_spaces;i++) {
    //     strcat(Canvas,"+-----+");
    //     strcat(Canvas," ");
    // }
    // strcat(Canvas,"\n");
}


int main()
{
    card_t two = createCard('2');
    card_t ace = createCard('A');
    // for (int i=0;i< 6;i++) {
    //     printf("%s\n",two.art[i]);
    // }
    card_t current_cards[2] = {two,ace};
    renderCards(current_cards,2);
    return 0;
}

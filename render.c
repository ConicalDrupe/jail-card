#include <string.h>
#include <stdio.h>
#include "card.c"

// User for O(n) time complexity
char * mystrcat(char* dest, char* src) {
    while (*dest) dest++;
    while (*dest++ = *src++);
    return --dest
}

char [4][5] renderCard(card_id){
    char card_img[4][5];
    strcpy(card_img[0],"*---*");
    strcpy(card_img[2],"|   |");
    strcpy(card_img[3],"*---*");

    // SKIPS id=4 so we can count consecutive cards.
    switch (card_id):
        case 0:
            strcpy(card_img[1],'| A |');
            return card_img;
        case 1:
            strcpy(card_img[1],'| K |');
            return card_img;
        case 2:
            strcpy(card_img[1],'| Q |');
            return card_img;
        case 3:
            strcpy(card_img[1],'| J |');
            return card_img;
        case 5:
            strcpy(card_img[1],'| 5 |');
            return card_img;
        case 6:
            strcpy(card_img[1],'| 4 |');
            return card_img;
        case 7:
            strcpy(card_img[1],'| 3 |');
            return card_img;
        case 8:
            strcpy(card_img[1],'| 2 |');
            return card_img;
    default:
        strcpy(card_img[1],'| ? |');
        return card_img;
}

void renderCards(card_t cards_arry[], int num_of_cards, int prompt_flag) {
    int unseen_card=0;

    // Iterate over lines
    for (int ln=0;ln<6;ln++) {
        // iterate over cards
        for (int i=0;i<num_of_cards;i++) {
            card_t current_card = cards_arry[i];
                char art[4][5] = renderCard(current_card.id);
                printf("%s ",art[ln]);

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

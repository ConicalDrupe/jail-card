
// Initialize Card paths in global state
//

typedef struct Card {
    char* name;
    int value;
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

void createCard(value) () {

}

void renderCard(card_t,int offset){
    char *end = "+---+";
    char *top= "|A  |";
    char *mid= "|   |";
    char *bot= "|  A|";

    printf("%s",end);
    printf("%s",top);
    printf("%s",mid);
    printf("%s",bot);
    printf("%s",end);
}

typedef struct Hand {   card_t[5] cards_arry;
    int seed;
} hand_t;

void renderCards(cards_t cards_arry[], int num_of_cards) {
    char Canvas[1600]; //17x70 , round up to, go 80x60 = 5200, or 80x(length of longest artwork) = 80x20 = 1600
    //
    int card_height = 6;
    int card_width = 7

    // width of each card, plus 1 space between each
    int max_width = card_width*num_of_cards + num_of_cards-1;
    for (int i=0;i< arry_size;i++) {
        // cards_t card = cards_arry[i];
            "+-----+"
    }

    int *canvas_ptr = Canvas;
}

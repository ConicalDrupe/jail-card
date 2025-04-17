#include <stdio.h>
#include "level.c"
#include "puzzle.c"
//640x480
//

int main(int argc, char *argv[])
{
    char *press_enter_1;

    char *intro_l1 = "You wake up to the sensation of cold and wet concrete.\nAs you collect yourself, you note this small concrete room is filled hot stale air.\nThere is no exit, only a small window covered in metal bars.\nIt seems you are in a jail cell, and boy is it dank.\n";
    char *prompt_l1 = "Press Enter to standup.\n";
    level_t one = new_level("levels/big_bricks_with_bars_2.txt",intro_l1,prompt_l1,1);

    printf("\n%s\n",intro_l1);
    int status = print_art(one.ascii_path);
    printf("\n%s\n",prompt_l1);
    scanf("%99[^\n]%*c",press_enter_1);


    char *intro_l2 = "As you collect yourself to standup, you hear footsteps scraping the floor outside the cell.\nIt sounds as if the footsteps are coming closer.";
    char *prompt_l2 = "Press Enter to look through the cell window.\n";
    // level_t two = new_level("levels/suspicious_man.txt",intro_l2,prompt_l2,2);
    char *press_enter_2;
    printf("\n%s\n",intro_l2);
    printf("\n%s\n",prompt_l2);

    getchar();
    scanf("%99[^\n]%*c",press_enter_2);
    // status = print_art(two.ascii_path);
    // printf("Print ascii exit code: %d\n",status);

    char *intro_l3 = "Well look-ey here, a newcomer! eheheh!\nAs dazed as they come!\nA word of advice, give the gaurds what they ask for and you'll make it to tommorow.\n";
    char *prompt_l3 = "[1] Who are you?\n[2] How do I get out of here?\n";

    level_t three= new_level("levels/suspicious_man.txt",intro_l3,prompt_l3,3);
    status = print_art(three.ascii_path);
    printf("%s\n",intro_l3);
    int number_of_tries = 0;
    int input_1 = 0;
    int input_2 = 0;
    while (1) {
        printf("\n%s\n",prompt_l3);
        int user_response;
        int success = scanf("%d",&user_response);
        if (success!=1) {
            printf("Enter 1 or 2.");
        }
        else if (input_1==1 && input_2==1) {
            printf("\n%s\n","To celebrate your awakening, let's play a little game.");
            break;
        }
        else if (user_response==1) {
            input_1=1;
            printf("%s\n","Ohhh I was just like you once.\nWe are not so different, except I have earned my freedom.");
            continue;
        }
        else if (user_response==2){
            input_2=1;
            printf("%s\n","Some may call this Paradise! Considering the state of things outside.\nNewcomers have it rough, so I suggest you be on your best behavior!\n");
            prompt_l3 = "[1] Who are you?\n[2] How do I get out of here?\n[3] How do I be free?\n";
            continue;
        }
        else {
            printf("Im not sure what that means.\n");
            continue;
        }
    };
    // printf("%s\n",prompt_l3);
    // char *input_l3;
    // prompt(three,0);

    char *opts[4] = {"Ace","Jack","Queen","King"};
    puzzle_t p1 = create_puzzle("Pick a card, pick any card...","levels/first_card_game.txt","Queen",4,opts);
    play_puzzle(p1);


    return 0;
}

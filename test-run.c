// #include <stdio.h>
// #include <stdlib.h>
#include "card.c"
#include "player.c"
#include "prompt.c"
#include "render.c"

typedef enum {
    INTRO,
    //TUTORIAL,
    INHAND,
    LEVEL1,
    LEVEL2,
    SHOP,
    SLEEP,
    DEAD,
    FREEPLAY,
    BOSS
} State;

#include "dialogue.c"

// add seed to player structure
// = {.seed = new_seed};
// char *player_name = "PlayerName";
player_t player = {.name="Player"};// createPlayer("Plr");
player_t mman = {.name="Mysterious Man"};//createPlayer("Mysterious Man");


int main(int argc, char *argv[])
{
    // ascii art paths
    //

    //buffer type
    // char requestCharInput
    // char requestEnterInput
    //
    // For Dialogue, have switch statement for each charInput, and a default value
    // For in-game playing a hand, have a series of InGame - HandStates, that take through each step of game.

    char *press_enter_1;
    char *intro_l1 = "You wake up to the sensation of cold and wet concrete.\nAs you collect yourself, you note this small concrete room is filled hot stale air.\nThere is no exit, only a small window covered in metal bars.\nIt seems you are in a jail cell, and boy is it dank.\n";
    char *prompt_l1 = "Press Enter to standup.\n";
    // level_t one = new_level("levels/big_bricks_with_bars_2.txt",intro_l1,prompt_l1,1);
    char ascii_start[48] = "levels/big_bricks_with_bars_2.txt";
    char ascii_mman[48] = "levels/suspicious_man.txt";
    // char ascii_[48] = "levels/big_bricks_with_bars_2.txt";

    printf("\n%s\n",intro_l1);
    int status = print_art(ascii_start);
    // runDialogue(dialogue,art_path)
    // rD -> print art, print dialogue
    // rd(struct dialog {char *question,char answer, char *art_path[20]})
    // Q-A loop: Question Answer loop decision tree

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
    status = print_art(ascii_mman);
    // printf("Print ascii exit code: %d\n",status);

    char *intro_l3 = "Well look-ey here, a newcomer! eheheh!\nAs dazed as they come!\nA word of advice, give the gaurds what they ask for and you'll make it to tommorow.\n";
    char *prompt_l3 = "[1] Who are you?\n[2] How do I get out of here?\n";

    // status = print_art(three.ascii_path);
    printf("%s\n",intro_l3);
    int number_of_tries = 0;
    int input_1 = 0;
    int input_2 = 0;


    // while(1) {

        // mysteriousManIntro()
        // print("")
    // } 
    // old main logic
    // Intro Mysterious Man 
    // while (1) {
    //     printf("\n%s\n",prompt_l3);
    //     int user_response;
    //     int success = scanf("%d",&user_response);
    //     if (success!=1) {
    //         printf("Enter 1 or 2.");
    //     }
    //     else if (input_1==1 && input_2==1) {
    //         printf("\n%s\n","To celebrate your awakening, let's play a little game.");
    //         break;
    //     }
    //     else if (user_response==1) {
    //         input_1=1;
    //         printf("%s\n","Ohhh I was just like you once.\nWe are not so different, except I have earned my freedom.");
    //         continue;
    //     }
    //     else if (user_response==2){
    //         input_2=1;
    //         printf("%s\n","Some may call this Paradise! Considering the state of things outside.\nNewcomers have it rough, so I suggest you be on your best behavior!\n");
    //         prompt_l3 = "[1] Who are you?\n[2] How do I get out of here?\n[3] How do I be free?\n";
    //         // print("Okay you scrumpt muppet now play me a game in cards")
    //         continue;
    //     }
    //     else {
    //         printf("Im not sure what that means.\n");
    //         continue;
    //     }
    };


    // Player gains a card and coins
    //characterStart
    // Placeholder
    addCard(&player,generateCard());
    addCard(&player,generateCard());
    addCard(&player,generateCard());
    addChips(&player,10);
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

    // Prompt player to call or fold
    // run playHand()
    // call -10 coins, fold (lose a card)
    char c_buffer[2];
    printf("\t[c]all (-5 coins)\n");
    printf("\t[f]old (forfiet and -20 coins or a card)\n");
    scanf("%s",c_buffer);

    return 0;
}

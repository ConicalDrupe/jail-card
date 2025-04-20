#include "utils.c"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prompt {
    char *question;
    char *art_path;
    char *answer; //correct answer
    int opt_n; //number of options
    char *options[4]; //array of 4 pointers, that each point to the beggining of an string (array of chars)
} prompt_t;

prompt_t create_prompt(char *art_path, char *question, char *answer, int opt_n,char *options[4]) {
    // Danger here if options is less than opt_n

    prompt_t new_prompt;
    new_prompt.art_path = art_path;
    new_prompt.question = question;
    new_prompt.answer = answer;
    new_prompt.opt_n = opt_n;

    for (int i=0; i<opt_n; i++){
        new_prompt.options[i] = options[i];
    }

    return new_prompt;
}

void play_prompt(prompt_t prompt) {
    int number_of_attempts = 0;

    // if (prompt.art_path != NULL) {
    //     print_art(prompt.art_path);
    //     printf("\n");
    // }

    do {
    // Print Question and Options
    printf("Attempt number: %d\n",number_of_attempts);
    printf("%s\n",prompt.question);

    for (int i = 0; i<prompt.opt_n;i++){
        printf("[%d] ",i+1);
        // printf("%s\n",prompt.options[i]);
        printf("Array: %s\n",prompt.options[i]);
        printf("\tPointer Math: %s\n",*(prompt.options+i));
        // printf
        }

    // get user input
    char buffer[2];
    // fgets(buffer,sizeof(buffer),stdin);
    scanf("%s",buffer);


    int success = strcmp(buffer,prompt.answer);
    // printf("string Comparison result: %d",success);

    // Answer Success/Failure Logic
    if (success==0) {
            printf("Correct answer!\n");
            exit(0);
        }
    else if (number_of_attempts==2) {
            printf("Too bad, You DIED!\n");
            // display death screen
            exit(0);
        }
    else {
        printf("\nNo Wrong!\n");
        printf("Select 1,2,3 or 4 as your answer.\n\n");
        number_of_attempts++;
        continue;
        }
    } while (1);
};


int main(int argc, char *argv[])
{
    char *q = "What is your fav icecream flavor?";
    char *art = "levels/man_2.txt";
    char *a = "2";//"Mint";
    int o_n = 4;
    char *opts[] = {"Vanilla","Mint","Strawberry","Chocolate"};
    // printf("%s\n",p0.options[0]);

    prompt_t p1 = create_prompt(art,q,a,o_n,opts);

    for (int j =0;j<o_n;j++) {
        printf("%s\n",p1.options[j]);
    }

    play_prompt(p1);

    return 0;
}

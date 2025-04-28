#pragma once

#include <stdio.h>


int print_art(char *path) {
    FILE *fp;
    char buffer[100];

    fp = fopen(path,"r");

    if (fp==NULL){
        printf("Could not find file");
        return 1;
    }

    while(fgets(buffer,sizeof(buffer),fp) != NULL){
        printf("%s",buffer);
        // HAL_UART_Transmit(artaddy,buffer,sizeof(buffer));
    }

    fclose(fp);
    return 0;
}

char * mystrcat(char* dest, char* src) {
    while (*dest) dest++;
    while (*dest++ = *src++);
    return --dest;
}


#include <stdio.h>

int main(){
    FILE *fp = fopen("game.txt", "r");

    fprintf(fp, "This is testing for fprintf...\n");
}
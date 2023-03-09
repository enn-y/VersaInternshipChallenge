#include <stdio.h>
#include <stdlib.h>

int main() {
    char array[100][9];
    int i = 1;

    for (i=1; i<=100; i++){
        if (i % 15 == 0) {
            sprintf(array[i-1], "BIG BANG");
        }
        else if (i % 3 == 0) {
            sprintf(array[i-1], "BIG");
        }
        else if (i % 5 == 0) {
            sprintf(array[i-1], "BANG");
        }
        else {
            sprintf(array[i-1], "%d", i);
        }
    }

    for (int i = 0; i < 100; i++){
        printf("%s ", array[i]);
    }

    FILE *fileptr;

    fileptr = fopen("output.json", "w");

    if (fileptr == NULL) {
        printf("\nError.");
        exit(1);
    }
    else{
        fprintf(fileptr, "[");
        for(int i = 0; i < 99; i++) {
            fprintf(fileptr, "\"%s\",", array[i]);
        }

        fprintf(fileptr, "\"%s\"]", array[99]);
        
        fclose(fileptr);
    }
    
    return 0;
}
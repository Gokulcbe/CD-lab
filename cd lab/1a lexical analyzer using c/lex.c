#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int keywordsLength = 3;
const int operatorsLength = 5; 
const int symbolsLength = 5;

char *keywords[3] = {"void", "int", "main"};
char *operators[5] = {"+", "-", "", "/", "="}; 
char *symbols[5] = {"(", ")", "{", "}", ";"};

void clearToken(char token[], int size) {
    for (int i = 0; i < size; i++) {
        token[i] = '\0';
    }
}

void processToken(char token[], int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i < keywordsLength; ++i) {
        if (strcmp(token, keywords[i]) == 0) {
            printf("%s  |(keyword)\n", keywords[i]);
            return;
        }
    }
    for (int i = 0; i < operatorsLength; ++i) {
        if (strcmp(token, operators[i]) == 0) {
            printf("%s    |(operator)\n", operators[i]);
            return;
        }
    }
    for (int i = 0; i < symbolsLength; ++i) {
        if (strcmp(token, symbols[i]) == 0) {
            printf("%s    |(symbol)\n", symbols[i]);
            return;
        }
    }
}

void logic(char buffer[], int size) {
    char temp[100];
    int tempIndex = 0;
    for (int i = 0; i < size; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\n') {
            temp[tempIndex] = '\0';
            processToken(temp, tempIndex);
            clearToken(temp, 100);
            tempIndex = 0;
            continue;
        }
        temp[tempIndex] = buffer[i];
        tempIndex += 1;
    }
}

int main() {
    FILE *file;
    file = fopen("lex.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int lSize;
    fseek(file, 0L, SEEK_END);
    lSize = ftell(file);
    rewind(file);

    char *buffer;
    buffer = calloc(1, lSize + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(buffer, lSize, 1, file);
    logic(buffer, lSize);
    fclose(file);
    free(buffer);
    return EXIT_SUCCESS;
}
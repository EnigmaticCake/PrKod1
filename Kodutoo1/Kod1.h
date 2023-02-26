#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HUVI 10

struct Inimene {
    char nimi[50];
    int H;
    char hobi[MAX_HUVI][20];
};

int lugemine(FILE *fail, struct Inimene *inimene);
void print(char *otsi_huviala, int, FILE *out_fail, struct Inimene *inimene);
void algandmed(FILE *fail, char *line);

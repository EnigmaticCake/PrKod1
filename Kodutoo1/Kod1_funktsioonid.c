#include "Kod1.h"

int lugemine(FILE *fail, struct Inimene *inimene)
{
    char line[100];
    int inimeste_arv = 0;
    while (fgets(line, sizeof(line), fail))
    {
        sscanf(line, "%s %d %[^\n]",
	       inimene[inimeste_arv].nimi,
	       &inimene[inimeste_arv].H,
		line);

        char *hobi = strtok(line, " ");
        int i = 0;

        while (hobi != NULL && i < MAX_HUVI)
	{
            strncpy(inimene[inimeste_arv].hobi[i], hobi, sizeof(inimene[inimeste_arv].hobi[i]) - 1);
            inimene[inimeste_arv].hobi[i][sizeof(inimene[inimeste_arv].hobi[i]) - 1] = '\0';
            hobi = strtok(NULL, " ");
            i++;
        }
        inimeste_arv++;
    }

    return inimeste_arv;
}

void print(char *otsi_huviala, int inimeste_arv, FILE *out_fail, struct Inimene *inimene)
{
    int ei = 0;
    printf("Inimesed kellele meeldib %s:\n", otsi_huviala);
    fprintf(out_fail, "Inimesed kellele meeldib %s:\n", otsi_huviala);
    for (int i = 0; i < inimeste_arv; i++) 
    {
        for (int j = 0; j < inimene[i].H; j++)
        {
            if (strcmp(inimene[i].hobi[j], otsi_huviala) == 0) 
            {
                printf("%s\n", inimene[i].nimi);
		fprintf(out_fail, "%s\n", inimene[i].nimi);
                ei++;
                break;
            }
        }
    }

    if(ei < 1)
    {
        printf("Kellelegi ei meeldi see huviala :(\n");
        fprintf(out_fail, "Kellelegi ei meeldi see huviala :(\n");
    }
}

void algandmed(FILE *fail, char *line)
{
    printf("\nAlgne fail:\n");
    fail = fopen("Kod1f", "r");
    if (fail == NULL) {
        printf("Could not open file\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fail))
    {
        printf("%s", line);
    }
    fclose(fail);
}

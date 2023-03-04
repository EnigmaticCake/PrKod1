#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HUVI 10

struct Inimene {
    char nimi[50];
    int H;
    char hobi[MAX_HUVI][20];
};

int main() 
{
    struct Inimene inimene[100];
    int inimeste_arv = 0;

    FILE *fail = fopen("Kod1f", "r");
    if (fail == NULL) 
    {
        printf("Fail ei avanenud!!!\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fail))
    {
        sscanf(line, "%s %d %[^\n]",
	       inimene[inimeste_arv].nimi,
	       &inimene[inimeste_arv].H,
		line);

        char *hobbi = strtok(line, " ");
        int i = 0;

        while (hobbi != NULL && i < MAX_HUVI)
	{
            strncpy(inimene[inimeste_arv].hobi[i], hobbi, sizeof(inimene[inimeste_arv].hobi[i]) - 1);
            inimene[inimeste_arv].hobi[i][sizeof(inimene[inimeste_arv].hobi[i]) - 1] = '\0';
            hobbi = strtok(NULL, " ");
            i++;
        }
        inimeste_arv++;
    }
	
    FILE *out_fail = fopen("Kod1f_out", "w");
     if (out_fail == NULL) 
    {
        printf("Fail ei avanenud\n");
        exit(1);
    }
	
    char otsi_huviala[20];
    printf("Sisesta huviala: ");
    scanf("%19s", otsi_huviala);

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
                break;
            }
        }
    }

    fclose(fail);
    fclose(out_fail);


    printf("\nAlgne fail:\n");
    fail = fopen("Kod1f", "r");
    if (fail == NULL) 
    {
        printf("Fail ei avanenud\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fail)) 
    {
        printf("%s", line);
    }
    fclose(fail);


    return 0;
}

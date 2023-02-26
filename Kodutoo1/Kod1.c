#include "Kod1.h"

int main() 
{
    struct Inimene inimene[100];

    FILE *fail = fopen("Kod1f", "r");
    if (fail == NULL) 
    {
        printf("Fail ei avanenud!!!\n");
        exit(1);
    }
    FILE *out_fail = fopen("Kod1f_out", "w");
    if (out_fail == NULL) 
    {
        printf("Fail ei avanenud\n");
        exit(1);
    }

    char line[100];
    int inimeste_arv = lugemine(fail, inimene);  

    char otsi_huviala[20];
    printf("Sisesta huviala: ");
    scanf("%19s", otsi_huviala);

    print(otsi_huviala, inimeste_arv, out_fail, inimene);
 
    fclose(fail);
    fclose(out_fail);

    algandmed(fail, line);

    return 0;
}


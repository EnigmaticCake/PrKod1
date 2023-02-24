#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPORTS 10

struct Person {
    char name[50];
    int num_sports;
    char sports[MAX_SPORTS][20];
};

int main() 
{
    struct Person people[100];
    int num_people = 0;

    FILE *fp = fopen("Kod1f", "r");
    if (fp == NULL) 
    {
        printf("Could not open file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%s %d %[^\n]",
	       people[num_people].name,
	       &people[num_people].num_sports,
		line);

        char *sport = strtok(line, " ");
        int i = 0;

        while (sport != NULL && i < MAX_SPORTS)
	{
            strncpy(people[num_people].sports[i], sport, sizeof(people[num_people].sports[i]) - 1);
            people[num_people].sports[i][sizeof(people[num_people].sports[i]) - 1] = '\0';
            sport = strtok(NULL, " ");
            i++;
        }
        num_people++;
    }

 

    // Search for people with the same sports
    char search_sport[20];
    printf("Enter a sport to search for: ");
    scanf("%19s", search_sport);

    printf("People who play %s:\n", search_sport);
    for (int i = 0; i < num_people; i++) 
    {
        for (int j = 0; j < people[i].num_sports; j++)
        {
            if (strcmp(people[i].sports[j], search_sport) == 0) 
            {
                printf("%s\n", people[i].name);
	
                break;
            }
        }
    }
    fclose(fp);
   


    // Display the original file
    printf("\nOriginal file:\n");
    fp = fopen("Kod1f", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) 
    {
        printf("%s", line);
    }
    fclose(fp);


    return 0;
}

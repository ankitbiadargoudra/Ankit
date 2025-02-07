#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#define MAX_CITY_LEN 101

#define MAX_TICKETS 100001

typedef struct
{

    char source[MAX_CITY_LEN];

    char destination[MAX_CITY_LEN];

} Ticket;

int main()
{

    int n;

    scanf("%d", &n);

    getchar();

    Ticket tickets[MAX_TICKETS];

    for (int i = 0; i < n; i++)
    {

        char line[2 * MAX_CITY_LEN];

        fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, " -> ");

        strcpy(tickets[i].source, token);

        token = strtok(NULL, " -> ");

        strcpy(tickets[i].destination, token);
    }

    char startCity[MAX_CITY_LEN];

    bool foundStart = false;

    for (int i = 0; i < n; i++)
    {

        bool isStart = true;

        for (int j = 0; j < n; j++)
        {

            if (i != j && strcmp(tickets[i].source, tickets[j].destination) == 0)
            {

                isStart = false;

                break;
            }
        }

        if (isStart)
        {

            strcpy(startCity, tickets[i].source);

            foundStart = true;

            break;
        }
    }

    if (!foundStart)
    {

        printf("Invalid Input: No clear starting city found.\n");

        return 1;
    }

    char currentCity[MAX_CITY_LEN];

    strcpy(currentCity, startCity);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (strcmp(currentCity, tickets[j].source) == 0)
            {

                printf("%s->%s", tickets[j].source, tickets[j].destination);

                if (i < n - 1)
                {

                    printf(", ");
                }

                strcpy(currentCity, tickets[j].destination);

                break;
            }
        }
    }

    printf("\n");

    return 0;
}

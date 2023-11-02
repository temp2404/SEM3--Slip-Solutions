#include <stdio.h>
#include <string.h>

int main()
{
    int i, n;
    char city[20][20], sk[20];
    printf("Give number of city name: ");
    scanf("%d", &n);
    printf("Enter city names: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", city[i]);
    }
    printf("City Names : ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", city[i]);
    }
    printf("\nGive City to search: ");
    // gets(sk);
    scanf("%s", sk);
    for (i = 0; i < n; i++)
    {
        if (strcmp(sk, city[i]) == 0)
        {
            printf("\nGiven city is at position %d", i);
            break;
        }
    }
    if (i == n)
    {
        printf("\nGiven city not found");
    }

    return 0;
}
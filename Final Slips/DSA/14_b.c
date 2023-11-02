#include <stdio.h>
#include <string.h>

void bubble_sort(char name[10][10], int n)
{
    int i, j;
    char temp[10];
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(name[j], name[j + 1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }
}

void display(char name[10][10], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%s ", name[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    char name[10][10];
    int n, i;
    printf("Enter number of names: ");
    scanf("%d", &n);
    printf("Enter Names: ");
    i = 0;
    while (i < n)
    {
        scanf("%s", name[i]);
        i++;
    }
    printf("Original Array: ");
    display(name, n);
    bubble_sort(name, n);
    printf("Sorted Array: ");
    display(name, n);
    return 0;
}
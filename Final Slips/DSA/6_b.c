#include <stdio.h>

void bubble_sort(int lists[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (lists[j] > lists[j + 1])
            {
                int temp = lists[j];
                lists[j] = lists[j + 1];
                lists[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int lists[10], n, i, j;
    printf("Enter Size of list: ");
    scanf("%d", &n);
    printf("Enter List elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lists[i]);
    }
    printf("Original List: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", lists[i]);
    }
    bubble_sort(lists, n);
    printf("\nSorted List: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", lists[i]);
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int a[20], n, i, sk;
    printf("Give array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nGive search key: ");
    scanf("%d", &sk);
    for (i = 0; i < n; i++)
    {
        if (sk == a[i])
        {
            printf("\nSearch key is at position %d", i);
            break;
        }
    }
    if (i == n)
    {
        printf("\nSearch key not found");
    }

    return 0;
}
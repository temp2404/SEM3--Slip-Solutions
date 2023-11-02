#include <stdio.h>

int binary_search(int a[], int lb, int ub, int sk)
{
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (sk == a[mid])
            return mid;

        else if (sk < a[mid])
            ub = mid - 1;

        else if (sk > a[mid])
            lb = mid + 1;
    }
    return -1;
}

int main()
{
    int a[20], i, n, sk, result;
    printf("Give array size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nGive search key: ");
    scanf("%d", &sk);

    result = binary_search(a, 0, n - 1, sk);
    if (result == -1)
        printf("Search key not found");
    else
        printf("Search key found at position %d", result);

    return 0;
}
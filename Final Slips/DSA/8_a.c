#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *root = NULL;

void insert(int n)
{
    if (root == NULL)
    {
        root = (NODE *)malloc(sizeof(NODE));
        root->data = n;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        NODE *temp = root;
        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;

        while (temp != NULL)
        {
            if (n < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newnode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int search(NODE *node, int n)
{
    if (node == NULL)
        return 0;

    if (node->data == n)
        return 1;
    else if (n < node->data)
        return search(node->left, n);
    else
        return search(node->right, n);
}

int main()
{
    int ch, n, data;
    do
    {
        printf("\n\n1. Create\n2. Display\n3. Search\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter No of Elements: ");
            scanf("%d", &n);
            printf("Enter %d elements: ", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                insert(data);
            }
            break;
        case 2:
            printf("BST: ");
            inorder(root);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            int result = search(root, data);
            if (result)
                printf("Element %d found in the BST.\n", data);
            else
                printf("Element %d not found in the BST.\n", data);
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Choice");
            break;
        }
    } while (ch != 4);
    return 0;
}

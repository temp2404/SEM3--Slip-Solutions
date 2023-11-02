// Incomplete

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
        NODE *t = root;
        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;

        while (t != NULL)
        {
            if (n < t->data)
            {
                if (t->left == NULL)
                {
                    t->left = newnode;
                    break;
                }
                else
                    t = t->left;
            }
            else
            {
                if (t->right == NULL)
                {
                    t->right = newnode;
                    break;
                }
                else
                    t = t->right;
            }
        }
    }
}

void preOrder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void delete(int n)
{
}

int main()
{
    int ch, n;
    do
    {
        printf("\n1. Insert Element\n2. Preorder Traversal\n3. Delete an Element\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("\nPreorder Traversal: ");
            preOrder(root);
            break;
        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &n);
            delete (n);
        case 4:
            exit(1);
        default:
            printf("Invalid Choice");
            break;
        }
    } while (ch != 4);
    return 0;
}
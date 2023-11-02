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

int main()
{
    insert(14);
    insert(34);
    insert(4);
    insert(114);
    inorder(root);
    printf("\n");
    return 0;
}

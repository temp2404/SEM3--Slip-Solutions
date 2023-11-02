#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *root = NULL;

NODE *insert_node(NODE *root, int n)
{
    if (root == NULL)
    {
        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    else
    {
        if (n < root->data)
            root->left = insert_node(root->left, n);

        else
            root->right = insert_node(root->right, n);
        return root;
    }
}

int count_nodes(NODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }
}

int count_degree_of_tree(NODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left != NULL && root->right != NULL)
    {
        return 2;
    }
    else if (root->left != NULL || root->right != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int count_leaf_nodes(NODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
    }
}

int main()
{
    int n, data;

    printf("Enter The Number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Integer %d: ", i + 1);
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    int number_of_nodes = count_nodes(root);
    int degree_of_tree = count_degree_of_tree(root);
    int leaf_nodes = count_leaf_nodes(root);

    printf("Number of nodes in the BST: %d\n", number_of_nodes);
    printf("Degree of the BST: %d\n", degree_of_tree);
    printf("Number of leaf nodes in the BST: %d\n", leaf_nodes);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct node *empty(struct node *root)
{
    if(root != NULL)
    {
        empty(root->left);
        empty(root->right);
    }
    return NULL;
}

struct node *insert(struct node *root, int x)
{
    if(root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    return root;
}

int find(struct node *root, int x)
{
    if(root == NULL)
        return 0;
    if(x == root->data)
        return 1;
    else if(x < root->data)
        find(root->left, x);
    else if(x > root->data)
        find(root->right, x);
    else
        return 0;
}

struct node *findMin(struct node *root)
{
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return findMin(root->left);
}

struct node *del(struct node *root, int x)
{
    int flag = find(root, x);
    if(flag == 1)
    {
        struct node *temp;
        if(root == NULL)
            return NULL;
        else if(x < root->data)
            root->left = del(root->left, x);
        else if(x > root->data)
            root->right = del(root->right, x);
        else if(root->left && root->right)
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, root->data);
        }
        else
        {
            temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
        }
    }
    else
        printf("Key is not present");
}

int main()
{
    int choice, x, tmp, flag;
    while(1)
    {
        printf("1. Construct a BST\n2. Search\n3. Traverse Inorder\n4. Traverse Preorder\n5. Traverse Postorder\n6. Delete a node\n7. Exit\n");
        printf("\nEnter your choice(1-7): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the key: ");
                scanf("%d", &x);
                root = insert(root, x);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("Enter the key: ");
                scanf("%d", &x);
                flag = find(root, x);
                if(flag == 0)
                    printf("Key is not present\n");
                else
                    printf("Key is present\n");
                printf("\n");
                break;
            }
            case 3:
            {
                inorder(root);
                printf("\n\n");
                break;
            }
            case 4:
            {
                preorder(root);
                printf("\n\n");
                break;
            }
            case 5:
            {
                postorder(root);
                printf("\n\n");
                break;
            }
            case 6:
            {
                printf("Enter the key: ");
                scanf("%d", &x);
                root = del(root, x);
                printf("\n\n");
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                printf("Invalid Input!!\n\n");
                break;
            }
        }
    }
    return 0;
}

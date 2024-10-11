#include<stdio.h>
#include<stdlib.h>

int preIndex = 0;

struct node
{
	char data;
	struct node *left, *right;
};

int search(char a[], int ini, int fin, char val)
{
	for(int i = ini; i <= fin; i++)
    {
		if(a[i] == val)
			return i;
	}
	return -1;
}

struct node *newNode(char val)
{
	struct node *treeNode = (struct node *)malloc(sizeof(struct node));
	treeNode->data = val;
	treeNode->left = NULL;
	treeNode->right = NULL;
	return treeNode;
}

struct node *tree(char pre[], char in[], int ini, int fin)
{
	if(ini > fin)
		return NULL;
	struct node *tNode = newNode(pre[preIndex++]);
	if(ini == fin)
        return tNode;
	int i = search(in, ini, fin, tNode->data);
    tNode->left = tree(pre, in, ini, i - 1);
	tNode->right = tree(pre, in, i + 1, fin);
	return tNode;
}

void print(struct node *node)
{
	if(node == NULL)
		return;
	print(node->left);
	print(node->right);
	printf("%c ", node->data);
}

int main()
{
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};
	int n = sizeof(pre) / sizeof(pre[0]);
	struct node *ele = tree(pre, in, 0, n - 1);
	printf("Preorder: ");
	for(int i = 0; i < n; i++)
        printf("%c ", pre[i]);
    printf("\nInorder: ");
    for(int i = 0; i < n; i++)
        printf("%c ", in[i]);
	printf("\n\nPostorder: ");
	print(ele);
	return 0;
}

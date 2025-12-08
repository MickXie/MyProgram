#include <stdio.h>
#include <stdlib.h>
typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} Node;
treePointer newNode(int data)
{
    treePointer n = (treePointer)malloc(sizeof(Node));
    n->data = data;
    n->leftChild = n->rightChild = NULL;
    return n;
}
void postorderIter(treePointer root)
{
    treePointer stack[1000];
    int top = -1;
    treePointer curr = root;
    treePointer lastVisited = NULL;
    while (curr != NULL || top != -1)
    {
        if (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->leftChild;
        }
        else
        {
            treePointer peek = stack[top];
            if (peek->rightChild != NULL && lastVisited != peek->rightChild)
            {
                curr = peek->rightChild;
            }
            else
            {
                printf("%d ", peek->data);
                lastVisited = peek;
                top--;
            }
        }
    }
}

treePointer buildExampleTree()
{
    treePointer root = newNode(1);
    root->leftChild = newNode(2);
    root->rightChild = newNode(3);
    root->leftChild->leftChild = newNode(4);
    root->leftChild->rightChild = newNode(5);
    return root;
}

int main()
{
    treePointer root = buildExampleTree();
    printf("Iterative postorder: ");
    postorderIter(root);
    printf("\n");

    return 0;
}
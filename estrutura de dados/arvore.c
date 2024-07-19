#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* leftChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* rightChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (root == NULL || leftChild == NULL || rightChild == NULL) {
        printf("Erro ao alocar mem�ria para os n�s.\n");
        exit(1);
    }

    root->data = 1;
    leftChild->data = 5;
    rightChild->data = 8;

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = NULL;
    leftChild->right = NULL;
    rightChild->left = NULL;
    rightChild->right = NULL;

    printf("Valor do n� raiz: %d\n", root->data);
    printf("Valor do filho � esquerda: %d\n", root->left->data);
    printf("Valor do filho � direita: %d\n", root->right->data);

    free(root);
    free(leftChild);
    free(rightChild);

    return 0;
}


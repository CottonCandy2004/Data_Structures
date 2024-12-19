#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    TreeNode* root = NULL;

    root = searchAndInsert(root, 50);
    root = searchAndInsert(root, 30);
    root = searchAndInsert(root, 70);
    root = searchAndInsert(root, 20);
    root = searchAndInsert(root, 40);
    root = searchAndInsert(root, 60);
    root = searchAndInsert(root, 80);

    printf("\n����������: ");
    inorderTraversal(root);
    printf("\n");

    searchAndInsert(root, 30);
    searchAndInsert(root, 35);

    printf("\n�����½ڵ�������������: ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);
    
    return 0;
}
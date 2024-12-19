#ifndef __TREE_H__
#define __TREE_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* searchAndInsert(TreeNode* root, int key) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        printf("节点 %d 不存在，已插入到树中\n", key);
        return newNode;
    }


    if (key == root->data) {
        printf("找到节点 %d\n", key);
        return root;
    }
    
    if (key < root->data) {
        root->left = searchAndInsert(root->left, key);
    }
    else {
        root->right = searchAndInsert(root->right, key);
    }
    
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

#endif
/*
 * File:   BST.h
 * Author: dsmith
 *
 * Created on April 13, 2011, 3:32 PM
 */
#include <stdio.h>
#include "BST.h"

FILE *debug;

BTNode *BSTInsert(BTNode **root, int data) {//add a node
    if (!(*root)) {
        (*root) = (BTNode*) calloc(1, sizeof (BTNode));
        (*root)->data.value = data;
        return *root;
    } else if ((*root)->data.value < data) {
        (*root)->right = BSTInsert(&(*root)->right, data);
        (*root)->right->pParent = (*root);
    } else if ((*root)->data.value > data) {
        (*root)->left = BSTInsert(&((*root))->left, data);
        (*root)->left->pParent = (*root);
    }
    return *root;
}

int BTCount(BTNode *phere) {
    int res = 0;
    if (phere) {
        res = 1 + BTCount(phere->left) + BTCount(phere->right);
    }
    return res;
}

int BTDepth(BTNode *phere) {
    int res = 0;
    int left, right;
    if (phere) {
        left = BTDepth(phere->left);
        right = BTDepth(phere->right);
        res = 1 + ((left > right) ? left : right);
    }
    return res;
}

/*
void deleteFromBST(BTNode *phere) {
    BTNode *lookAt;

    if (!(phere->left)) {
 *(phere->ppMe) = phere->right;
        free(phere);
         //phere->data.value=1;
    } 
    else if (!(phere->right)) {
 *(phere->ppMe) = phere->left;
        free(phere);
        //phere->data.value=1;
    } else {
        if (BTDepth(phere->left) > BTDepth(phere->right)) {

            lookAt = phere->left;
            while (lookAt->right) {
                lookAt = lookAt->right;
            }
            phere->data.value = lookAt->data.value;
            deleteFromBST(lookAt);
        } else {

            lookAt = phere->right;
            while (lookAt->left) {
                lookAt = lookAt->left;
            }
            phere->data.value = lookAt->data.value;
            deleteFromBST(lookAt);
        }
    }
}
 */

void deleteFromBST(BTNode *phere2) {
    BTNode *pleast;

    if (!phere2->right && !phere2->left) {
        if (phere2->pParent->right == phere2) {
            phere2->pParent->right = NULL;
            phere2->pParent->right = NULL;
            free(phere2);
        }

        if (phere2->pParent->left == phere2) {
            phere2->pParent->left = NULL;
            free(phere2);
        }
    } else if (phere2->left && !phere2->right) {
        phere2->left->pParent = phere2->pParent;
        phere2->pParent->left = phere2->left;
        free(phere2);
    } else if (phere2->right && !phere2->left) {
        phere2->right->pParent = phere2->pParent;
        phere2->pParent->right = phere2->right;
        free(phere2);
    } else {
        pleast = phere2->right;
        while (pleast->left) {
            pleast = pleast->left;
        }

        phere2 = pleast;
        deleteFromBST(pleast);
    }

}

void drawCursor(BTNode *phere) {
    drawCircle(phere->data.col, phere->data.row, 4, 0);
}

void drawTree(BTNode *phere, int r, int c, int dc, int dr) {
    if (phere) {
        //draw my node in inorder
        if (phere->left) {
            drawLine(r + 2, c - 2, r + 2 + dr, c - 2 - dc, 0);
            drawTree(phere->left, r + dr, c - dc, dc / 2, dr);
        }

        fillCircle(r, c, 2, phere->data.value);
        phere->data.row = r;
        phere->data.col = c;

        if (phere->right) {
            drawLine(r + 2, c + 2, r + 2 + dr, c + 2 + dc, 0);
            drawTree(phere->right, r + dr, c + dc, dc / 2, dr);
        }
    }
}

void BTfree(BTNode *phere) {
    if (phere) {
        BTfree(phere->left);
        BTfree(phere->right);
        free(phere);
    }
}


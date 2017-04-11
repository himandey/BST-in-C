/* 
 * File:   BST.h
 * Author: dsmith
 *
 * Created on April 13, 2011, 3:32 PM
 */

#ifndef BST_H
#define	BST_H

#include <stdlib.h>

/* type declarations */
typedef struct node_data_t {
    int value; // unique node value
    int row, col; // node location
} Node_data;

typedef struct BTNode_t {
    Node_data data;
    struct BTNode_t *pParent;
    struct BTNode_t **ppMe;
    struct BTNode_t *left;
    struct BTNode_t *right;
} BTNode;

/* global (static) data */
#ifdef _DEBUG
FILE *debug;
#endif

BTNode *BSTInsert(BTNode **pphere, int value);
int BTCount(BTNode *phere);
int BTDepth(BTNode *phere);
void printTree(BTNode *root, const char *title);
void deleteFromBST(BTNode *phere);
void drawTree(BTNode *phere,int r, int c, int dc, int dr);
void drawCursor(BTNode *phere);
void BTfree(BTNode *phere);
#endif	/* BST_H */


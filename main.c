/*----------------------------------------------------------------------
 *
 *         GBA Program
 *
 *		Author: Himanshu Pandey
 *--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GBA_basics.h"

typedef enum {
    STARTING, RUNNING
} STATE;

int main(void) {

    BTNode *root = NULL;
    BTNode *phere = NULL;
    BTNode *phere2 = NULL;
    int i, x = 1, depth = 0;
    int value;
    int time = 0;


    for (i = 0; i < 256; i++) {
        PALETTE_MEM[i] = rainbow[i];
    }

    STATE state = STARTING; //initializes state

    setup();


    while (keepGoing()) {
        waitForScan();
        flipPage();

        //uses DMA
        fillBackGround(1);

        switch (state) {

            case STARTING:
                time++;

                drawString4(65, 60, "Binary Tree of Colors", 42);

                if (check_key(BUTTON_NDX_START) == KEY_PRESSED)//press enter to start
                {
                    srand(time);
                    state = RUNNING;
                }
                break;


            case RUNNING:

                if (x) {
                    for (i = 0; i < 10; i++) {//add 10 random nodes
                        value = rand() % 256;
                        BSTInsert(&root, value);
                    }
                    phere = root;
                    x = 0; //so this if statement only runs once per program run but is complied after STARTING
                }


                if (check_key(BUTTON_NDX_A) == KEY_PRESSED)//press A to add nodes
                {
                    value = rand() % 256;
                    BSTInsert(&root, value);
                }

                depth = BTDepth(root); //find depth
                int dr = (SCREEN_HEIGHT - 10) / depth; //find delta row based on depth
                drawTree(root, 2, 120, 60, dr); //draw tree


                drawCursor(phere);

                if (check_key(BUTTON_NDX_LEFT) == KEY_PRESSED && phere->left) {
                    phere = phere->left;
                }

                if (check_key(BUTTON_NDX_RIGHT) == KEY_PRESSED && phere->right) {
                    phere = phere->right;
                }

                if (check_key(BUTTON_NDX_UP) == KEY_PRESSED && phere->pParent) {
                    phere = phere->pParent;
                }

                if (check_key(BUTTON_NDX_B) == KEY_PRESSED && phere) {
                    phere2 = phere;
                    phere = phere->pParent;
                    deleteFromBST(phere2);                    
                }

                // phere2=NULL;
                // if(phere->pParent)
                // drawCursor(phere2);

                break;

        }
    }
    BTfree(root);
    finish();
    return 0;
}



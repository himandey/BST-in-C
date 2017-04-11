/*----------------------------------------------------------------------
 *
 *         GBA Basics
 *
 *--------------------------------------------------------------------*/
#include <stdlib.h>
#include "video.h"

void setup() {
	REG_DISPCTL = MODE3 | BG2_ENABLE;
}

u16 *videoBuffer = (u16 *)0x6000000;
volatile u16* scanlineCounter = (volatile u16*) 0x4000006;

//Wait for scanline to be off visible screen
void waitForVBlank() {
    while(*scanlineCounter > 160);  // finish current scan
    while(*scanlineCounter < 160);  // finish next scan
}


int main(void) {
    setup();
    /* A GBA program should never end */
    int t = 0;
    int it = 0;
    int loc = OFFSET(80, 120);
    while (TRUE) {
        /* wait for end of screen write */
        waitForVBlank();
        videoBuffer[loc] = COLOR(0, 0, 0);
        t++;
        if(t%3 == 0) loc++;
        if(loc > (240*160)) {
            loc = 0;
            it = 99;
        } else {
            // do nothing
        }
//        setPixel3(80, 120, COLOR(31, 31, 0) );
        videoBuffer[loc]
                = COLOR(31, 31, 0);
    }
    return 0;
}

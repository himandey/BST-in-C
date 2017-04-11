/********************************************************
**                     video.h                         **
**                 Brian Granaghan                     **
**  Contains register locations, bit fields, buffers,  **
**  macros, and prototypes for video capabilities.     **
********************************************************/
#ifndef __VIDEO_H__
#define __VIDEO_H__
#include "gba_types.h"

// Registers
#define REG_DISPCTL *(u16 *)0x4000000
#define REG_DISPSTAT *(u16 *)0x4000004
#define VIDEO_BUFFER ((u16*)0x6000000)

// Bit Fields
#define BG2_ENABLE 1<<10
#define MODE3 3
#define MODE4 4
#define BACKBUFFER 1<<4

// Buffers, declated extern since variables should not be created
// in the header file
extern u16 *videoBuffer;
extern volatile u16* scanlineCounter;

// Macros
//Create a color with the specified RGB values
#define COLOR(r, g, b) ((r) | (g)<<5 | (b)<<10)
//Convert a row, column to a screen position
#define OFFSET(R,C) ((R)*240+(C))

// Colors
#define BLUE  COLOR(0, 0, 31)
#define RED   COLOR(31, 0, 0)
#define BLACK 0

// Prototypes
void waitForVBlank();
#define setPixel3(r, c, color) videoBuffer[OFFSET((r),(c))] = (color)
#endif

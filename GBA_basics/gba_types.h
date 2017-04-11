/********************************************************
**                     gba_types.h                     **
**                   Brian Granaghan                   **
**     Contains data types for GBA development         **
**  macros, and prototypes for video capabilities.     **
********************************************************/
#ifndef _GBATYPES_H_
#define _GBATYPES_H_

/* Variable types*/
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned char byte;

/* Defines*/
#define TRUE  1
#define FALSE 0
#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

#ifndef NULL
#define NULL (void *)0
#endif

#endif

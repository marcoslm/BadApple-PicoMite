/*
 * Bad Apple RLE decoder para PicoMite HDMI/USB
 * Author: Marcos López Merayo, 2025
 *
 *  - Decodifica una línea de video a partir de datos RLE en "chunk"
 *  - Pensado para video en blanco/negro
 *  - Cada línea empieza en color negro (colorIsWhite = 0)
 *  - El buffer "chunk" viene de MMBasic,
 *    por eso se accede como chunk[chunkPos + 1]
 *
 */
#include <stdint.h>
#include "csub/PicoCFunctions.h"

#define FRAME_WIDTH 319
#define COLOR_WHITE 0xFFFFFF

/* 
 * decode()
 *  Decodifica una linea de video RLE y dibuja los tramos blancos.
 *
 *  Parámetros (por puntero, coinciden con la CSUB en MMBasic):
 *    chunk         -> buffer con los bytes RLE (cadena de MMBasic)
 *    bytesInChunk  -> número de bytes válidos en chunk
 *    chunkPos      -> posición actual dentro del chunk (0..bytesInChunk-1)
 *    x, y          -> coordenadas actuales en la linea
 *    colorIsWhite  -> 0 = negro, 1 = blanco (se alterna cada run)
 */
void decode(unsigned char *chunk, int *bytesInChunk, int *chunkPos, int *x, int *y, 
            int *colorIsWhite) {

    int runLen;
    
    while (*x <= FRAME_WIDTH && *chunkPos < *bytesInChunk)
    {
        runLen = (chunk[*chunkPos + 1]);
        (*chunkPos)++;

        if (*colorIsWhite == 1 && runLen > 0) {
            DrawLine(*x, *y, *x + (runLen-1), *y, 1, COLOR_WHITE);
        }

        *x += runLen;
        *colorIsWhite = 1 - *colorIsWhite;	/* alternar negro/blanco */
    }
}

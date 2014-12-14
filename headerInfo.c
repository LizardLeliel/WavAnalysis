#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "headerInfo.h"

#define PRINT_TWO_BYTES(buf)  printf("Bytes: %02x%02x\n\n",\
                                    buf[0], buf[1]);
#define PRINT_FOUR_BYTES(buf) printf("Bytes: %02x%02x %02x%02x\n\n",\
                                    buf[0], buf[1], buf[2], buf[3]);



#define SEE_BYTE

uint32_t describeBytesByLittleEndian(
  const size_t bytes, const char* description,
  const char* note, FILE* wave
)
{
    byte_t buffer[bytes];

    scanBytes(buffer, bytes, wave);
    uint32_t result = fromLittleEndian(bytes, buffer);

    printf(description);
    printf("\n%u %s\n", result, note);

#ifdef SEE_BYTE
    switch (bytes) {
        case 2: PRINT_TWO_BYTES(buffer)  break;
        case 4: PRINT_FOUR_BYTES(buffer) break;
    }
#endif
    printf("\n");
    return result;
}

void describeBytesByString(
  const size_t bytes, const char* description,
  const char* note, FILE* wave
)
{
    byte_t buffer[bytes+1];
    buffer[bytes+1] = '\0';

    scanBytes(buffer, bytes, wave);

    printf(description);
    printf("\n%s %s\n", buffer, note);

#ifdef SEE_BYTE
    switch (bytes) {
        case 2: PRINT_TWO_BYTES(buffer)  break;
        case 4: PRINT_FOUR_BYTES(buffer) break;
    }
#endif
    printf("\n");
}

void scanBytes(byte_t* buffer, const size_t ammount, FILE* wave) {
    int i;
    for (i=0; i < ammount; ++i) {
        buffer[i] = fgetc(wave);
    }
}

uint32_t fromLittleEndian(const size_t bytes, const byte_t* buffer) {
    uint32_t returnVal=0;
    int i;
    for (i=0; i < bytes; ++i) {
        returnVal |= buffer[i] << (8*i);
    }

    return returnVal;
}

















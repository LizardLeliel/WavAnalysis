#ifndef HEADER_INFO_HEADER
#include <inttypes.h>
#include <stdio.h>

/* A data type suitable for storing a byte of data */
#define byte_t unsigned char

/* Prints two bytes */
#define PRINT_TWO_BYTES(buf)  printf("Bytes: %02x%02x\n\n",\
                                    buf[0], buf[1]);
/* Prints four bytes */
#define PRINT_FOUR_BYTES(buf) printf("Bytes: %02x%02x %02x%02x\n\n",\
                                    buf[0], buf[1], buf[2], buf[3]);

/* Macro; keep defined if you want the descrbeBytes functions to print
 * the data's little endian bytes (as how stored on the file) */
#define SEE_BYTE

/* A struct suitable for holding all nessecary header information;
 * and a pointer to a file for future functions */
struct wavHeaderStruct{
    FILE* wavFile;
    uint32_t fullChunkSize;

    uint32_t fmtSubSize;
    uint16_t audioFormat;
    uint16_t channels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;

    uint32_t bytesOfMusic;
};

/* A cross-program struct to store header information */
extern struct wavHeaderStruct wavHeader;

/* Takes a couple of characters form the buffer and writes it to buffer */
void scanBytes(byte_t* buffer, const size_t ammount, FILE* wave);

/* Describes a section of bytes in little-endian form, and returns them
 * as uint32_t (but may return values with lesser size; but not more) */
uint32_t describeBytesByLittleEndian(
  const size_t bytes, const char* description,
  const char* note, FILE* wave);

/* Describes a section of bytes which are characters */
void describeBytesByString(
  const size_t bytes, const char* description,
  const char* note, FILE* wave);

/* converts an array of little-endian bytes to uint32_t (although
 * it may return an unsigned interger which requires less space*/
uint32_t fromLittleEndian(const size_t bytes, const byte_t* buffer);




#define HEADER_INFO_HEADER
#endif

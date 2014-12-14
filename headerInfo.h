#ifndef HEADER_INFO_HEADER
#include <inttypes.h>
#include <stdio.h>

#define byte_t unsigned char

void scanBytes(byte_t* buffer, const size_t ammount, FILE* wave);

uint32_t describeBytesByLittleEndian(
  const size_t bytes, const char* description,
  const char* note, FILE* wave);

void describeBytesByString(
  const size_t bytes, const char* description,
  const char* note, FILE* wave);

/* little endian conversions */
uint32_t fromLittleEndian(const size_t bytes, const byte_t* buffer);

uint64_t litend64_ui(const byte_t* buffer);



#define HEADER_INFO_HEADER
#endif

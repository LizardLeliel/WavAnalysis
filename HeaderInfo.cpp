#include <inttypes.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

#include "HeaderInfo.hpp"

using namespace std;

WavHeader::WavHeader(const string& filename)
    : wavFile(filename, fstream::in | fstream::binary)
{
    scanCharacters(riffName, 4);

    if (strcmp(riffName, "RIFF") != 0)
    {
        riffName[0] = '\0';
        return;
    }

    fullChunkSize = (uint32_t) scanLittleEndian(4);
    scanCharacters(waveName, 4);

    scanCharacters(fmtName, 4);
    fmtSubSize    = (uint32_t) scanLittleEndian(4);
    audioFormat   = (uint16_t) scanLittleEndian(2);
    channels      = (uint16_t) scanLittleEndian(2);
    sampleRate    = (uint32_t) scanLittleEndian(4);
    byteRate      = (uint32_t) scanLittleEndian(4);
    blockAlign    = (uint16_t) scanLittleEndian(2);
    bitsPerSample = (uint16_t) scanLittleEndian(2);

    scanCharacters(dataName, 4);
    bytesOfMusic = (uint32_t) scanLittleEndian(4);
}

WavHeader::~WavHeader()
{

}

unsigned int WavHeader::scanLittleEndian(const size_t ammount)
{
    unsigned int returnVal = 0;
    char buffer[ammount];
//infile.read (buffer,size);
    wavFile.read(buffer, ammount);

    // Actually do the conversion
    for (int i = 0; i < ammount; ++i) 
    {
        returnVal |= (unsigned char)buffer[i] << (8*i);
    }

    return returnVal;
}

void WavHeader::scanCharacters(char* buffer, const size_t ammount)
{
    wavFile.read(buffer, ammount);
    buffer[ammount] = '\0';
}

bool WavHeader::valid()
{
    return riffName[0] != '\0';
}

void WavHeader::printHeaderContents(std::ostream& out)
{
    if (!valid())
    {
        out << "File is not a proper wav file" << endl;
        return;
    }

    out << "RIFF header name: " << riffName << endl;
    out << "File size in bytes minus 8: " <<  fullChunkSize << endl;
    out << "File type: " << waveName << endl;
    
    out << "Subchunk name: " << fmtName << endl;
    out << "Format subchunk size in bytes: " << fmtSubSize << endl;
    
    out << "Audio format: " << audioFormat;
    if (audioFormat == 1)
    {
        out << " (audio is uncompressed)";
    }
    out << endl;
    
    out << "Audio channels: " << channels;
    if (channels == 1) out << " (mono)";
    else if (channels == 2) out << " (stereo)";
    out << endl;

    out << "Sample Rate (samples per second): " << sampleRate
        << " (44100 is a common sample rate)" << endl;
    out << "Byte rate (sample rate * channels * bits per sample / 8): "
        << byteRate << endl;
    out << "Block align: (bytes per sample): " << blockAlign << endl;
    out << "Bits per Sample: " << bitsPerSample << endl;

    out << "Subchunk name: " << dataName << endl;
    out << "Ammount of samples in bytes: " << bytesOfMusic << endl;

}

void WavHeader::printHeaderContents()
{
    printHeaderContents(cout);
}

/*
// wavHeader definition - allocates memory 
struct wavHeaderStruct wavHeader;

uint32_t describeBytesByLittleEndian
(
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
*/















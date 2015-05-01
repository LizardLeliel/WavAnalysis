
#include <inttypes.h>
#include <iostream>

#include "SampleInfo.hpp"
#include "HeaderInfo.hpp"

using namespace std;

WavReader::WavReader(const string& filename)
    : WavHeader(filename)
{

}

void WavReader::printUntil(unsigned int ending)
{
    cout << "Works" << endl;
}



/*
void printOneSampleBytes() 
{
    uint16_t bits = wavHeader.bitsPerSample;
    //* Curiously enough, if the wav file is in 8 bits per sample, then
     //* the bytes are stored as usigned chars. If its 16 bits, then its a
     //* intregral type (2's complement), with the range equilivant of a short
     //*

    if (bits == 8) {
        byte_t buffer[bits/8];
        scanBytes(buffer, bits/8, wavHeader.wavFile);

        printf("One sample: %u (%02x)\n", buffer[0],  buffer[0]);
    }
    else if (bits == 16) {
        byte_t buffer[bits/8];
        scanBytes(buffer, bits/8, wavHeader.wavFile);
        int16_t sample = (int16_t)fromLittleEndian(bits/8, buffer);

        printf("One sample: %d (%02x%02x)\n", sample, buffer[0], buffer[1]);
    }


}

void fprintSecondOfSamples(FILE* output) 
{
    uint16_t bits = wavHeader.bitsPerSample;
    uint32_t sampleRate = wavHeader.sampleRate;
    //* TODO: update to print four samples a line 
    if (bits == 8) 
    {
        byte_t buffer[bits/8];
        int n;

        for (n=0; n < sampleRate; ++n) 
        {
            scanBytes(buffer, bits/8, wavHeader.wavFile);
            fprintf(output, "%05d: %03u, (%02x)\n", n, buffer[0], buffer[0]);
        }
    }
    else if (bits == 16) 
    {
    //* I'm trying to output four samples at a time here *
        byte_t buffer [bits/8*4];
        int n, m;

        fprintf(output,
          "Format: (sample #: value,) four times followed by (bytes)\n"
        );

        for (n=0; n < sampleRate; n+=4) 
        {
            scanBytes(buffer, bits/8*4, wavHeader.wavFile);
            int16_t sample[4];

            for (m=0; m < 4; ++m) 
            {
                sample[m] = (int16_t)fromLittleEndian(bits/8, buffer+m*2);
            }

            fprintf(
              output,
              "%05d:%6d,  %05d:%6d,  ",
              n+1, sample[0], n+2, sample[1]
            );
            fprintf(
              output,
              "%05d:%6d,  %05d:%6d ",
              n+3, sample[2], n+4, sample[3]
            );
            fprintf(
              output,
              "(%02x%02x %02x%02x %02x%02x %02x%02x)\n",
              buffer[0], buffer[1], buffer[2], buffer[3],
              buffer[4], buffer[5], buffer[6], buffer[7]
            );
        }
    }
}*/


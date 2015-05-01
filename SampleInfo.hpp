#ifndef SAMPLE_INFO_HEADER
#include <stdio.h>
#include <inttypes.h>
#include <string>

#include "HeaderInfo.hpp"

class WavReader : public WavHeader
{

  public:
    WavReader(const std::string& filename);
    void printUntil(unsigned int ending);
};

/*
//* Everything is done through the struct wavHeader *
//* Print a single sample's value *
void printOneSampleBytes();
//* Print a whole second of samples to output file*
void fprintSecondOfSamples(FILE* output);
*/

#define SAMPLE_INFO_HEADER
#endif



#include "HeaderInfo.hpp"
#include "SampleInfo.hpp"
//#include "Descriptions.hpp"
//#include "SamplePlay.hpp"

int main(int argc, char** argv) 
{
    WavReader header("SquareWav.wav");
    header.printHeaderContents();
    header.printUntil(1);
    return 0;
}

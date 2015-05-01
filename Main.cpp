

#include "HeaderInfo.hpp"
//#include "Descriptions.hpp"
//#include "SamplePlay.hpp"

int main(int argc, char** argv) 
{
    WavHeader header("SquareWav.wav");
    header.printHeaderContents();
    return 0;
}

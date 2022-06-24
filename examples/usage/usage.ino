// Example usage for apollo-lora-transmit library by Ian Pratt <ianjdpratt@gmail.com>.

#include "Apollo_LoRA_Transmit.h"

// Initialize objects from the lib
Apolloloratransmit apolloloratransmit;

void setup()
{
    // Call functions on initialized library objects that require hardware
    apolloloratransmit.begin();
}

void loop()
{
    // Use the library's initialized objects and functions
    apolloloratransmit.process();
}

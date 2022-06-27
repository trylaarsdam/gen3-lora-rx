// Example usage for apollo-lora-transmit library by Ian Pratt <ianjdpratt@gmail.com>.

#include "Apollo_LoRA.h"

// Initialize the object from the lib
Apollo_LoRA transmitter(&Serial1);

void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop()
{
    // transmit a string of data
    transmitter.transmit("Hello, world!");

    string recieved = "";
    while (recieved == "")
    {
        recieved = transmitter.recieve();
    }

    Serial.println(recieved);
}

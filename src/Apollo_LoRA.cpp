/* Apollo_LoRA library by Ian Pratt <ianjdpratt@gmail.com>
 */

#include "Particle.h"
#include "Apollo_LoRA.h"

using namespace std;

/**
 * Constructor.
 */
Apollo_LoRA::Apollo_LoRA()
{
    // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void Apollo_LoRA::transmit(string data)
{
    Serial.printlnf("sending `%s`...", data.c_str());
    Serial1.println(("setdata/" + data + "/").c_str());
    delay(100);
    Serial1.println("transmit//");

    // flush serial data
    while (Serial1.available() > 0)
    {
        Serial1.read();
    }
}

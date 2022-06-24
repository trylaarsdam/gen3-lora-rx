/* Apollo_LoRA_Transmit library by Ian Pratt <ianjdpratt@gmail.com>
 */

#include "Particle.h"
#include "Apollo_LoRA_Transmit.h"

using namespace std;

/**
 * Constructor.
 */
Apollo_LoRA_Transmit::Apollo_LoRA_Transmit()
{
    // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void Apollo_LoRA_Transmit::transmit(string data)
{
    Serial.printlnf("sending `%s`...", data.c_str());
    Serial1.println(("setdata/" + data + "/").c_str());
    delay(100);
    Serial1.println("transmit//");
}

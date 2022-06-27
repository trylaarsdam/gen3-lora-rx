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
 * Transmits data over LoRA.
 */
void Apollo_LoRA::transmit(string data)
{

    Serial1.println(("setdata/" + data + "/").c_str());
    delay(100);
    Serial1.println("transmit//");

    // flush serial data
    while (Serial1.available() > 0)
    {
        Serial1.read();
    }
}

/**
 * Receives data over LoRA. Returns null if there is no data.
 * This code was written by Arjun.
 * Returns NULL if there is no data.
 */
string Apollo_LoRA::recieve()
{

    if (Serial1.available() > 0)
    {
        std::string payload = "";
        while (Serial1.available() > 0)
        {
            payload += Serial1.read();
        }

        int sizePos = payload.find("Size") + 5;
        int size = atoi(payload.substr(sizePos, 2).c_str());

        payload = payload.substr(9 + payload.find("/"), size).c_str();

        return payload;
    }
    else
    {
        return NULL;
    }
}
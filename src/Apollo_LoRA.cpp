/* Apollo_LoRA library by Ian Pratt <ianjdpratt@gmail.com>
 */

#include "stdio.h"
#include "Particle.h"
#include "Apollo_LoRA.h"

using namespace std;

void flush_serial_buffer(USARTSerial *serial)
{
    while (serial->available() > 0)
    {
        serial->read();
    }
}

Apollo_LoRA::Apollo_LoRA(USARTSerial *chosenSerial = &Serial1)
{
    serial = chosenSerial;
    serial->begin(9600);
}

Apollo_LoRA::Apollo_LoRA(USARTSerial *chosenSerial = &Serial1, int codingrate = 1, int spreadingfactor = 12, int transmissionpower = 18)
{
    serial = chosenSerial;
    serial->begin(9600);
    codingRate(codingrate);
    spreadingFactor(spreadingfactor);
    transmissionPower(transmissionpower);
}

void Apollo_LoRA::codingRate(int codingRate)
{
    if (codingRate < 1 || codingRate > 4)
    {
        codingRate = 1;
    }

    char buffer[1];

    serial->print("codingrate/" + *itoa(codingRate, buffer, 10));
    serial->println("/");

    flush_serial_buffer(serial);
}

void Apollo_LoRA::spreadingFactor(int spreadingFactor)
{
    if (spreadingFactor < 7 || spreadingFactor > 12)
    {
        spreadingFactor = 12;
    }

    char buffer[1];

    serial->print("sf/" + *itoa(spreadingFactor, buffer, 10));
    serial->println("/");

    flush_serial_buffer(serial);
}

void Apollo_LoRA::transmissionPower(int transmissionPower)
{
    if (transmissionPower < 0 || transmissionPower > 24)
    {
        transmissionPower = 18;
    }

    char buffer[1];

    serial->print("txp/" + *itoa(transmissionPower, buffer, 10));
    serial->println("/");

    flush_serial_buffer(serial);
}

void Apollo_LoRA::transmit(string data)
{

    serial->println(("setdata/" + data + "/").c_str());
    delay(100);
    serial->println("transmit//");

    flush_serial_buffer(serial);
}

string Apollo_LoRA::recieve()
{

    if (serial->available() > 0)
    {
        std::string payload = "";
        while (serial->available() > 0)
        {
            payload += serial->read();
        }

        int sizePos = payload.find("Size") + 5;
        int size = atoi(payload.substr(sizePos, 2).c_str());

        payload = payload.substr(9 + payload.find("/"), size).c_str();

        return payload;
    }
    else
    {
        return "";
    }
}

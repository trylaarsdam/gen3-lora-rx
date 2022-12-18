/* Apollo_LoRA library by Ian Pratt <ianjdpratt@gmail.com>
 */

#include "stdio.h"
#include "Particle.h"
#include "gen3-lora-rx.h"

using namespace std;

void flush_serial_buffer(USARTSerial *serial)
{
	while (serial->available() > 0)
	{
		serial->read();
	}
}

int searchForString(char* fullString, char* searchString) {
	int i = 0;
	int j = 0;
	int k = 0;
	int found = 0;
	int notFound = -1;
	while (fullString[i] != '\0') {
		j = i;
		k = 0;
		while (searchString[k] != '\0' && fullString[j] == searchString[k]) {
			j++;
			k++;
		}
		if (k > 0 && searchString[k] == '\0') {
			found = 1;
			break;
		}
		i++;
	}
	if (found == 1) {
		return i;
	} else {
		return notFound;
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
	char payload[256] = {0};

	bool continueReading = true;
	bool potentialEndOfMessage = false;
	int len = 0; 

	while (continueReading)
	{
		if (serial->available() > 0)
		{
			char c = serial->read();
			if (c == '/')
			{
				potentialEndOfMessage = true;
			}
			else if(potentialEndOfMessage && c == ';')
			{
				continueReading = false;
			}
			else
			{
				potentialEndOfMessage = false;
			}

			payload[len] = c;
			len++;
		}
	}
	Serial.println("Payload: " + String(payload));
	uint8_t size_start = searchForString(payload, "/Size/") + 6;
	uint8_t size_end = searchForString(payload, "/RSSI/") - 1;
	char size[size_end - size_start + 2] = {0};
	for (int i = size_start; i < size_end + 1; i++)
	{
		size[i - size_start] = payload[size_start];
	}
	Serial.println("Size: " + String(size));


	// 	// // LoRaPacket packet = {};
	return "";
}

#pragma once

/* Apollo_LoRA library by Ian Pratt <ianjdpratt@gmail.com>
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

using namespace std;

// The main class for the Apollo_LoRA library. This class is used to communicate with the LoRA module.
class Apollo_LoRA
{
public:
  /**
   * Constructor
   * @param serial The serial port to use, a string. Defaults to Serial1.
   */
  Apollo_LoRA(USARTSerial *serial);

	struct LoRaPacket {
		uint8_t* data;
		uint8_t size;
		int rssi;
		uint8_t sf;
		uint8_t cr;
	};

  /**
   * Constructor
   * @param serial The serial port to use, a string. Defaults to Serial1.
   * @param codingrate Sets the coding rate. Defaults to 1 (4/5). See `codingRate` for more information.
   * @param spreadingfactor Sets the spreading factor. Defaults to 12. See `spreadingFactor` for more information.
   * @param transmissionpower Sets the transmit power in dB. Defaults to 18. See `transmissionPower` for more information.
   */
  Apollo_LoRA(USARTSerial *serial, int codingrate, int spreadingfactor, int transmissionpower);

  /**
   * Sets the coding rate. The four coding rates are enumerated as:
   * 1: 4/5
   * 2: 4/6
   * 3: 4/7
   * 4: 4/8
   * Defaults to 1 (4/5).
   * @param codingRate The coding rate to use, an int between 1-4.
   */
  void codingRate(int codingRate);

  /**
   * Sets the spreading factor. Defaults to 12.
   * @param spreadingFactor The spreading factor, an int between 7-12.
   */
  void spreadingFactor(int spreadingFactor);

  /**
   * Sets the transmit power in dB. This is separate from the low/high power switch on the external PA. Defaults to 18 (3/4 full power)
   * @param transmissionPower the transmissionPower, an int between 0-24.
   */
  void transmissionPower(int transmissionPower);

  /**
   * Transmits data over LoRA.
   * @param data The data to transmit, a string.
   */
  void transmit(string data);

  /**
   * This code was written by Arjun.
   * Receives data over LoRA.
   * @return The received data, a string. Empty string if no data is recieved at the time.
   */
  Apollo_LoRA::LoRaPacket recieve();

  USARTSerial *serial;
};
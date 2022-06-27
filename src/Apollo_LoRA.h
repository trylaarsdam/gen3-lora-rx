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
   * Receives data over LoRA. Returns null if there is no data.
   * @return The received data, a string. NULL if no data is recieved at the time.
   */
  string recieve();

  USARTSerial *serial;
};

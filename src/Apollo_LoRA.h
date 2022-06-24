#pragma once

/* Apollo_LoRA library by Ian Pratt <ianjdpratt@gmail.com>
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

using namespace std;

// This is your main class that users will import into their application
class Apollo_LoRA
{
public:
  /**
   * Constructor
   */
  Apollo_LoRA();

  /**
   * Transmits data over LoRA.
   */
  void transmit(string data);

  /**
   * Receives data over LoRA. Returns null if there is no data.
   */
  string recieve();
};

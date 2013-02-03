#include <stdint.h>
#include <avr/io.h>

#include "nma7361l.h"

void acc_set_sens(uint8_t sens)
{
  if (sens)
    PORTF |= 0x04;  // set g-sel (PORTF:2) high 6G        [0][0][0][0] [0][1][0][0]
  else
    PORTF &= 0xFB;  // set g-sel (PORTF:2) low 1.5G       [1][1][1][1] [1][0][1][1]
}


void acc_set_sleep(uint8_t sleep)
{
  if (sleep)
    PORTF |= 0x10;  // set sleep (PORTF:4) high sleep     [0][0][0][1] [0][0][0][0]
  else
    PORTF &= 0xEF;  // set sleep (PORTF:4) low awake      [1][1][1][0] [1][1][1][1]
}


void acc_set_selftest(uint8_t selftest)
{
  if (selftest)
    PORTF |= 0x02;  // set selftest (PORTF:1) high st     [0][0][0][0] [0][0][1][0]
  else
    PORTF &= 0xFD;  // set selftest (PORTF:1) low no st   [1][1][1][1] [1][1][0][1]
}


void acc_setup(uint8_t sens)
{
  // Pin stuff
  PORTF = 0;
  DDRF = 0x68;      // Set port F directions              [0][1][1][0] [1][0][0][0]
  DIDR0 = 0x07;     // Disable input circuits             [0][0][0][0] [0][1][1][1]
  PORTF |= 0x10;    // Sleep pin (PORTF:4) high           [0][0][0][1] [0][0][0][0]
  acc_set_sens(sens);

  // ADC Stuff
  
}


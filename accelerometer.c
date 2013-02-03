#include <avr/io.h>
#include <util/delay.h>

#include "nma7361l.h"
#include "print.h"
#include "usb_debug_only.h"

// Teensy 2.0: LED is active high
#define LED_ON		(PORTD |= (1<<6))
#define LED_OFF		(PORTD &= ~(1<<6))

#define LED_CONFIG	(DDRD |= (1<<6))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
int main(void)
{
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	LED_CONFIG;
	LED_OFF;

  acc_setup(0);

	// initialize the USB, but don't want for the host to
	// configure.  The first several messages sent will be
	// lost because the PC hasn't configured the USB yet,
	usb_init();

	while (1)
  {
    LED_OFF;
    _delay_ms(100);
    LED_ON;
    _delay_ms(100);
	}
}


/* use internal clock, at 1MHz */
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define DELAYTIME 2

uint8_t msg[] = {
	/*H*/ 127, 127, 8, 8, 127, 127, 
		0,
	/*A*/ 124, 126, 11, 11, 126, 124, 
		0,
	/*P*/ 127, 127, 9, 9, 15, 6, 
		0,
	/*P*/ 127, 127, 9, 9, 15, 6, 
		0,
	/*Y*/ 7, 15, 120, 120, 15, 7, 
		0,
		0,
		0,
	/*2*/ 98, 115, 81, 73, 79, 70, 
		0,
	/*0*/ 62, 127, 73, 69, 127, 62, 
		0,
	/*1*/ 64, 68, 127, 127, 64, 64, 
		0,
	/*6*/ 62, 127, 73, 73, 123, 50, 
};

/* The attiny44a has pins 6-13 (i.e. portA) connected to LEDs */

int main(void) {
  uint8_t i;

  DDRA = 0xff;  /* all output pins */

  while (1) {
    for (i = 0; i < sizeof(msg); i++) {
      PORTA = msg[i];
      _delay_ms(DELAYTIME);
    }

    PORTA = 0;                    /* blank for gap between repetitions */
    _delay_ms(5 * DELAYTIME);

  }
  return (0);
}

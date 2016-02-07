/*
 * ATtiny13 LED Nightlight Controller
 * File: nightlight.c
 */

#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    const int lightOffDelay = 20; // delay in seconds to light off
    int i;
 
    // PB4 - output to LED Control MOSFET
    // PB3 - input from motion detector
    
    // Set up Port B pin 4 mode to output
    DDRB = 1<<DDB0;

    while (1) {
 
      if (PINB & (1<<PB3)){ // Check Trigger from Detector
          
          PORTB &= ~(1<<PB0); //Turn on LEDs
          
          for(i=0;i<lightOffDelay;i++) _delay_ms (1000);
            
       }
       PORTB |= (1<<PB0); // Turn off LEDs
    }
    return 0;
}

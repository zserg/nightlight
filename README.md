## LED Night Light Controller

The Controller uses signal from a security motion detector to turn LED lamp on and to turn it off in around 20 seconds.

### Input signals:
* +26V - motion detected
* 0V   -  all quiet

### BOM:
* MCU Atmel ATtiny13
* DC/DC Converter (12V -> 5V)
* Resistors: 10K, 2.2K
* P-channels MOSFET: IRF4905L

### Schematic:
<img src="https://github.com/zserg/nightlight/blob/master/nightlight_schematic.jpg" alt="Drawing" style="width: 100px;"/>
### Code:
````c
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
````
### Board:
<img src="https://github.com/zserg/nightlight/blob/master/nightlight_boart.jpg" alt="Drawing" style="width: 100px;"/>





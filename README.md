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
![board](https://github.com/zserg/nightlight/nightlight_schematic.jpg)




 SPECTROSCOPY RECODER
 *  BY Mitch Shiles 
 *  Based on wiring and code found on these links
 *  LCD
 *  https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay
 *  
 *  
 *  Sketch uses 9122 bytes (28%) of program storage space. Maximum is 32256 bytes.
    Global variables use 1551 bytes (75%) of dynamic memory, leaving 497 bytes for local variables. Maximum is 2048 bytes.
    Low memory available, stability problems may occur.
 *  
 *  this sketch is intended to use with the MY DIY spectral reader
 *  the device includes 
 *  -- The spark fun triad spectroscopy sensor 
 *  -- A small 2x16 charicter liquid crystal display
 *  -- Spark Funs open log SD card logger
 *  -- A rotary encoder
 *  -- An Arduino Uno R3
 *  -- Spark funs Qwicc conector prototyping board
 *  -- and two momentary buttons/ switches
 *  -- a portable USB battery for charging 
 *  -- an indicator LED
 *  
 *THE CIRCUIT: Components
 *  For the LCD 
 * -- LCD RS pin to digital pin 12
 * -- LCD Enable pin to digital pin 11
 * -- LCD D4 pin to digital pin 5
 * -- LCD D5 pin to digital pin 4
 * -- LCD D6 pin to digital pin 3
 * -- LCD D7 pin to digital pin 2 change to pin 9
 * -- LCD R/W pin to ground
 * -- LCD VSS pin to ground
 * -- LCD VCC pin to 5V
 * -- 10K resistor:
 * -- ends to +5V and ground
 *    wiper to LCD VO pin (pin 3)
 * 
 *  For the Rotary Encoder 
 *    CLK(clock) to Pin 2
 *    DT (data)  to Pin 1
 *    SW(switch) to Pin 
 *    GND to GND
 *     +  to 5V
 *  For the Button and LED
 *    
 *    
 *  For the Open Log 
 *  
 *    RXI to Pin 8 TX
 *    TXI to Pin 6 RX
 *    GND to GND
 *    BLK to GND
 *    VCC to 3.3V
 * 
 * 
 * *THE CIRCUIT:  Arduino
 * 0> __ = 
 * 1< __ = Data Rotary Encoder
 * 2rupt = CLK Rotary encoder
 * 3~ __ = LCD D6
 * 4  __ = LCD D5
 * 5~ __ = LCD D4
 * 6~ __ = TXI Openlog
 * 7  __ = SW Rotary Encoder
 * 8  __ = RXI openlog
 * 9~ __ = LCD D7 change
 * 10~ _ = Trigger button 
 * 11~ _ = LCD Enable
 * 12 __ = LCD RS
 * 13 __ = LED button
 * 
 * A0 --qwicc connect
 * A1
 * A2
 * A3 
 * A4 --qwicc connect
 * A5 --qwicc connect
 * 
 * 
 * https://github.com/sparkfun/OpenLog/blob/master/firmware/Arduino_Examples/Example1_SoftwareLogging/Example1_SoftwareLogging.ino
 * 
 * 
 * 
 */

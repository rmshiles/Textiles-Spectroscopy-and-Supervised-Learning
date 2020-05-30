/* 
 *  
 *  SPECTROSCOPY RECODER
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
// include the library code:
//LCD library
#include <LiquidCrystal.h>
//Spectroscopy Sensor Library
#include "SparkFun_AS7265X.h" //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;
// wire library
#include <Wire.h>
// serial library
#include <SoftwareSerial.h>
// include Rotary Encoder Library
#include <RotaryEncoder.h>


//Initialize pins
// initialize the library with the numbers of the interface pins
//   LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
     //LiquidCrystal lcd(12, 11, 5, 8, 3, 9); // updatated LCD pins so that the Rotary encoder can have the interrupt on pin 2
      const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 9;
      LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Initialize pins for Open Log 
//  Connect RXI of OpenLog to pin 5 on Arduino
    SoftwareSerial OpenLog(6, 8); // 8 = Soft RX pin (not used), 6 = Soft TX pin
//  5 can be changed to any pin. See limitation section on https://www.arduino.cc/en/Reference/SoftwareSerial
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Initialize Rotary Encoder 
 // delete these 4 lines after testing rotary encoder library 
//#define encoder0PinA 2 // clock pin Rotary encoder must be an interupt pin 
//#define encoder0PinB 3 // regular input pin 
//#define encoder0Btn 4 same as select pin above 

// define the rotary encoder pins 
RotaryEncoder encoder(1, 2);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-==--=-==-=-

//initialize buttons and LEDs
int led_pin = 13;
//const int triggerPin =  ; //the pin the trigger is attached to 
const int selectPin = 7  ;// the pin attached to the SW for the rotary encoder
const int triggerPin = 10  ;// the pin attached to the SW for the rotary encoder

//const int cancelPin =   ;// the pin the 


static int pos = 1;
int newPos = 0;
int oldPos = 0;
int selected = 0;
int pos_holder = 0;

// define menu variables
int encoder0Pos = 0;
//int Select = 0;

int menuArray[] = {0,0};

int Menu_len = 0;
int Menu_num = 0;



//int submenuNum = 


//create an empty variable to store the material string in 
String material;
String color;
String color2;
int opacity = 0;
int record_count=0;
//create list of materials and material qualities
// create a list of menu strings
//int Main_Menu_Len = 5;
//const char PROGMEM  Menu_strings[5][10] = {"Take Reading","Material:   ","Color:      ","Opacity: ","OFF    "};
//char  Menu_strings[6][10] = {"Take Reading","Material:   ","Color:      ","Opacity: ","OFF    "};
//int Main_Menu_Len = 5;
//String  Menu_strings[6] = {"Take Reading","Material:   ","Color:      ","Opacity: ","OFF    "};

// create a list for the material submenu
//int material_menu_len = 7;
//const char PROGMEM  Materail_strings[7][7] = {"Plastic", "Textile", "Wood   ", "Metal  ", "Cer/Gla", "Food   ", "Bio   " };

//material lists
//int plastic_len = 11;
//String plastic_types[12] = {"PET1", "HDP2", "PVC3", "LDP4", "PP_5","PS_6","Oth7","PLA_","ABS_","PoCa","ACRY","" };

int textile_len= 15;
String textiles [16] = {"Cot","Wol","Sil","Pol","Nyl","Ray","Bam","Lin","Hem","Lea","Jut","Ela", "Acr","Ctl","Unk",""};
/*
int wood_len = 7;
const char PROGMEM  wood_types [7][3] = {"Map","Oak","Pop","Pin","Ced","Bas","Bam"};

int metal_len = 4;
const char PROGMEM  metal_types [4][5] = {"Alumi","Steel","Stain","Titan"};
*/
// Color Menu
int color_list_len=12;
String  colors_types[13] =  {"Non","Wht","Grn","Blk","Brn","Red","Org","Yel","Blu","Pur","Tan","Gry",""};

//int Opacity_len = 3;
//const char PROGMEM  Opacity_types[3][5] = {"Opaqu", "Semi_", "Clear"};

/// need to add pins for rotary encoder

void setup() {
  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(selectPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

// Begin serial connections   
Serial.begin(9600);

// begin oppen log connection 
OpenLog.begin(9600); //Open software serial port at 9600bps

// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.setCursor(0, 0);
lcd.print(F("Recoder ON"));
delay(1000);
lcd.setCursor(0, 0);
lcd.print("            ");
OpenLog.println(F("Material,Color,Opacity,A=410nm ,B=435nm,C=460nm,D=485nm,E=510nm,F=535nm,G=560nm,H=585nm,I=645nm,J=705nm,K=900nm,L=940nm,R=610nm,S=680nm,T=730nm,U=760nm,V=810nm,W860nm"));
if(sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
//sensor.begin();
//sensor.disableIndicator(); //Turn off the blue status LED



}
  /// take control readings from sensor control readings should either mimic  randomness or nothing



void loop() {

// get the reading from the encoder and the switches 

int trigger = digitalRead(triggerPin);
//if the trigger is ever pushed then stop everything else and take a recoding with the spectrometer 
while(trigger == LOW){
      delay(500);
      digitalWrite(13, LOW);
      Take_Reading();
      record_count +=1;
      trigger = HIGH;
      digitalWrite(13, HIGH);
  }

Menu();


}

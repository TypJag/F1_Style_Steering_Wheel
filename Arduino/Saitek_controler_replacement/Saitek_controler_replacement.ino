/*

  PicoGamepad

 

  Turn a Raspberry Pico 2040 into an HID gamepad

 

  Supports:

  128 Buttons

  8 Analog axes

  4 Hat switches

 

  created 28 June 2021

  by Jake Wilkinson (RealRobots)
  https://www.gitlab.com/realrobots/PicoGamepad

  Have also integrated a part of the code that reads a value from a external ADC using SPI

*/

 

#include <PicoGamepad.h>
#include <SPI.h>

PicoGamepad gamepad;

// 16 bit integer for holding input values

int val;

const int chipSelectPin = 8; 

void setup() { 

  //Serial.begin(115200);

  pinMode(chipSelectPin, OUTPUT);
 

  //pinMode(LED_BUILTIN, OUTPUT);

 

  // X Potentiometer on pin 26

  pinMode(26, INPUT);

  // Y Potentiometer on pin 27

  pinMode(27, INPUT);

  // Z Pot on pin 28

  pinMode(28, INPUT);

 

  // Button on pin

  pinMode(10, INPUT_PULLUP);

  pinMode(11, INPUT_PULLUP);

  pinMode(12, INPUT_PULLUP);

  pinMode(13, INPUT_PULLUP);

  pinMode(14, INPUT_PULLUP);

  pinMode(9, INPUT_PULLUP);

  pinMode(16, INPUT_PULLUP);

  pinMode(17, INPUT_PULLUP);

  pinMode(18, INPUT_PULLUP);

  pinMode(19, INPUT_PULLUP);

  pinMode(20, INPUT_PULLUP);

  pinMode(21, INPUT_PULLUP);

  SPI.begin();
}

 

void loop() {
  //Used for the SPI com
  int bytesToRead = 2;
  byte inByte = 0;
  unsigned int result = 0;
 

  // Get input value from Pico analog pin

  val = analogRead(26);

 

  // Map analog 0-1023 value from pin to max HID range -32767 - 32767

  val = map(val, 100, 952, -32767, 32767);

 

  // Send value to HID object

  gamepad.SetX(val);

 

  // Repeat with Y pin

  val = analogRead(27);

  val = map(val, 70, 954, -32767, 32767);

  gamepad.SetY(val);

  val = analogRead(28);

  val = map(val, 50, 904, -32767, 32767);

  gamepad.SetRx(val);
  
  //Sets chipSelectPin low to start the transfer from the ADC
  digitalWrite(chipSelectPin, LOW);


  //The ADC which is a ADC108S022 have 8 channels and can be controled by writing to specific registers. I'm only using the first channel
  //so no writing is needed. The ADC writes the value as 2 bytes but only using 10bits. The result gets an offset. In this case thats 
  //not a problem as the map function fixes that.

  // send a value of 0 to read the first byte returned:

  result = SPI.transfer(0x00);

  // decrement the number of bytes left to read:

  bytesToRead--;

  // if you still have another byte to read:

  if (bytesToRead > 0) {

    // shift the first byte left, then get the second byte:

    result = result << 8;

    inByte = SPI.transfer(0x00);

    // combine the byte you just got with the previous one:

    result = result | inByte;

    // decrement the number of bytes left to read:

    bytesToRead--;

  }
  


  // take the chip select high to de-select:

  digitalWrite(chipSelectPin, HIGH);

  val = map(result, 300, 3700, -32767, 32767);
  
  gamepad.SetRy(val);
  




 

//  gamepad.SetZ(val);

//  gamepad.SetRx(val);

//  gamepad.SetRy(val);

//  gamepad.SetRz(val);

//  gamepad.SetS0(val);

//  gamepad.SetS1(val);

 

  // Set button 0 of 128 by reading button on digital pin 28

  gamepad.SetButton(0, !digitalRead(10));

  gamepad.SetButton(1, !digitalRead(11));

  gamepad.SetButton(2, !digitalRead(12));

  gamepad.SetButton(3, !digitalRead(13));

  gamepad.SetButton(4, !digitalRead(14));

  gamepad.SetButton(5, !digitalRead(9));

  gamepad.SetButton(6, !digitalRead(16));

  gamepad.SetButton(7, !digitalRead(17));

  gamepad.SetButton(8, !digitalRead(18));

  gamepad.SetButton(9, !digitalRead(19));

  gamepad.SetButton(10, !digitalRead(20));

  gamepad.SetButton(11, !digitalRead(21));

  // Set hat direction, 4 hats available. direction is clockwise 0=N 1=NE 2=E 3=SE 4=S 5=SW 6=W 7=NW 8=CENTER

  // gamepad.SetHat(0, 8);

 

 

  // Send all inputs via HID

  // Nothing is send to your computer until this is called.

  gamepad.send_update();

 

  // Flash the LED just for fun

  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  //delay(100);

}

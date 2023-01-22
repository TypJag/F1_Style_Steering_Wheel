#include <Bounce.h>

Bounce button0 = Bounce(0,10);

const int led1 = 1;
const int led2 = 2;
const int led3 = 3;
const int ledPin = 4;

int buttonstate0;
int buttonstate1;
int buttoncheck0;


void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(led1, INPUT);
  pinMode(led2, INPUT);
  pinMode(led3, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button0.update();
  buttonstate1 = digitalRead(led1);

  if (button0.fallingEdge()) {
    buttonstate0 = 1;
  }
  if(buttonstate1 == HIGH && buttonstate0 == 1 && buttoncheck0 == 1); {
       Keyboard.set_key1(KEY_H);
       Keyboard.send_now();
       delay(20);
       Keyboard.set_key1(0);
       Keyboard.send_now();
       buttoncheck0 = 0;
  }
  if(buttonstate1 == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  if(buttonstate0 = 0) {
    buttoncheck0 = 1;
  } 
}

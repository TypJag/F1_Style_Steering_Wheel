#include <Bounce.h>

Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);

int buttonstate0;
int buttonstate1;
int buttoncheck1;


void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1.update();
  button0.update();
  

    if (button0.fallingEdge()) {
       buttonstate0 = 1;
    }

    if (button1.fallingEdge()) {
       buttonstate1 = 1;
    }

    if (buttonstate0==1 && buttonstate1==1 && buttoncheck1==1) {
       Keyboard.set_key1(KEY_H);
       Keyboard.send_now();
       delay(20);
       Keyboard.set_key1(0);
       Keyboard.send_now();
       buttoncheck1 = 0;
    }
    if (buttonstate0==0 && buttonstate1==0) {
       buttoncheck1 = 1;
    }

    if (button0.risingEdge()) {
      buttonstate0 = 0;
    }

    if (button1.risingEdge()) {
      buttonstate1 = 0;
    }
    if(button0.fallingEdge()) {
       Keyboard.set_key1(KEY_G);
       Keyboard.send_now();
       delay(20);
       Keyboard.set_key1(0);
       Keyboard.send_now();
       buttoncheck1 = 0;
    }
    
}

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce button11 = Bounce(11, 10);
Bounce button12 = Bounce(12, 10);
Bounce button16 = Bounce(16, 10);
Bounce button17 = Bounce(17, 10);
Bounce button18 = Bounce(18, 10);
Bounce button19 = Bounce(19, 10);
Bounce button20 = Bounce(20, 10);
Bounce button21 = Bounce(21, 10);
Bounce button22 = Bounce(22, 10);
Bounce button23 = Bounce(23, 10);



void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
}

void loop() {
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();

   if (button0.fallingEdge()) {
    Keyboard.println("0");
  }
  if (button1.fallingEdge()) {
    Keyboard.println("1");
  }
  if (button2.fallingEdge()) {
    Keyboard.println("2");
  }
  if (button3.fallingEdge()) {
    Keyboard.println("3");
  }
  if (button4.fallingEdge()) {
    Keyboard.println("4");
  }
  if (button5.fallingEdge()) {
    Keyboard.println("5");
  }
  if (button6.fallingEdge()) {
    Keyboard.println("6");
  }
  if (button7.fallingEdge()) {
    Keyboard.println("7");
  }
  if (button8.fallingEdge()) {
    Keyboard.println("8");
  }
  if (button9.fallingEdge()) {
    Keyboard.println("9");
  }
  if (button10.fallingEdge()) {
    Keyboard.println("+");
  }
  if (button11.fallingEdge()) {
    Keyboard.println("'");
  }
  if (button17.fallingEdge())(button16.fallingEdge() {
    Keyboard.println("/");
  }
}

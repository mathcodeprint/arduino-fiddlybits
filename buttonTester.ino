/*

  This code is simply for use to test wether or not a buttom you have wired up is working correctly.
  It is purposefully basic so that it is very easy to understand. It is explicit with each button so 
  any beginner will likely understand. I left out any for() loops or other normal coding for 
  this reason.
  
  The initial version only tests using the analog pins as thats all I needed at the time.
  
  The buttons are debounced so the serial output is only triggered once per press. 
  
  */


#include <Bounce2.h>

#define DEBOUNCE 10

Bounce button1 = Bounce(); // Assigned
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();
Bounce button6 = Bounce();

const int button1Pin = 14;     // the number of the pushbutton pin
const int button2Pin = 15;     // the number of the pushbutton pin
const int button3Pin = 16;     // the number of the pushbutton pin
const int button4Pin = 17;     // the number of the pushbutton pin
const int button5Pin = 18;     // the number of the pushbutton pin
const int button6Pin = 19;     // the number of the pushbutton pin

int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status
int button3State = 0;         // variable for reading the pushbutton status
int button4State = 0;         // variable for reading the pushbutton status
int button5State = 0;         // variable for reading the pushbutton status
int button6State = 0;         // variable for reading the pushbutton status

  
void setup() {

  Serial.begin(9600);

  // Initialize the pushbutton pins as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);

  button1.attach(button1Pin);
  button1.interval(DEBOUNCE); // interval in ms

  button2.attach(button2Pin);
  button1.interval(DEBOUNCE); // interval in ms

  button3.attach(button3Pin);
  button3.interval(DEBOUNCE); // interval in ms

  button4.attach(button4Pin);
  button4.interval(DEBOUNCE); // interval in ms

  button5.attach(button5Pin);
  button5.interval(DEBOUNCE); // interval in ms

  button6.attach(button6Pin);
  button6.interval(DEBOUNCE); // interval in ms
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Update each Bounce2 object with the current status of the Button
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();

  // If the button was pressed ( fell ) set the buttons
  // state to 1 ( aka HIGH )
  button1State = button1.fell();
  button2State = button2.fell();
  button3State = button3.fell();
  button4State = button4.fell();
  button5State = button5.fell(); 
  button6State = button6.fell(); 

  if ( button1State == HIGH)  Serial.println(" Button1 on Analog 0 ( Pin 14 ) Pressed -  " );
  if ( button2State == HIGH)  Serial.println(" Button2 on Analog 1 ( Pin 15 ) Pressed - L" );
  if ( button3State == HIGH)  Serial.println(" Button4 on Analog 2 ( Pin 16 ) Pressed - D" );
  if ( button4State == HIGH)  Serial.println(" Button4 on Analog 3 ( Pin 17 ) Pressed - U " );
  if ( button5State == HIGH)  Serial.println(" Button5 on Analog 4 ( Pin 18 ) Pressed - R " );
  if ( button6State == HIGH)  Serial.println(" Button6 on Analog 5 ( Pin 19 ) Pressed - S " );


}

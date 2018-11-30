#include <Bounce2.h>

#include <avr/sleep.h>

#define DEBOUNCE 10
#define LED_PIN 3


uint8_t externalFlag=1;
uint8_t enabledToggle=1;
uint8_t disableCounter=0;

// These indicate the size of the grid.
// the grid starts at 0 ( zero ) and goes to grid_max
// A 3x3 grid will have grid max(s) of 2,2 

const int grid_max_row = 2;
const int grid_max_col = 2;

const int col_leds[3] = {7,6,5};
const int g_row_leds[3] = {8,9,10};
const int r_row_leds[3] = {13,12,11};


// The following two arrays are for testing LEDs or
// playing a pattern at startup
// They are copied into the Pixel matrix at 
// the end of setup. They are not used anywhere else.
const int g_leds_on[3][3] = { {0,0,0},
                              {0,0,0},
                              {0,0,0} };                          

const int r_leds_on[3][3] = { {0,0,0},
                              {0,0,0},
                              {0,0,0} };      

Bounce button1 = Bounce(); //
Bounce button2 = Bounce(); // 
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();

//Button pins on analog , used as digital
// button1 "Left"
// button2 "Down
// button3 "Up"
// button4 "Right"
// button5 "Select"


const int button1Pin = 15;     // pushbutton pin for "Left"
const int button2Pin = 16;     // pushbutton pin for "Down"
const int button3Pin = 17;     // pushbutton pin for "Up"
const int button4Pin = 18;     // pushbutton pin for "Right"
const int button5Pin = 19;     // pushbutton pin for "Select"

int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status
int button3State = 0;         // variable for reading the pushbutton status
int button4State = 0;         // variable for reading the pushbutton status
int button5State = 0;         // variable for reading the pushbutton status

// Cursor position is from 0,0 to 2,2
int crsr_row = 0;
int crsr_col = 0;

char action = "";
char crsr = "";

int g_pixels[3][3];
int r_pixels[3][3];

//int g_preblinkState = g_pixels[thisCol][thisRow];
//int r_preblinkState = g_pixels[thisCol][thisRow];

long previousMillis = 0;        // will store last time LED was updated
long interval = 500;
long animationRate = 500;

String animation = "demo";



      int last_crsr_row = 0;
      int last_crsr_col = 0;
  
bool BLINK = LOW;

String current_turn = "RED";

String winningPlayer= "";

void setup() {
  
  Serial.begin(9600);


  //Set Led pin's in array (Rows and Colums) to output     
  pinMode( 5, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 7, OUTPUT );
  
  pinMode( 8, OUTPUT );
  pinMode( 9, OUTPUT );
  pinMode( 10, OUTPUT );

  pinMode( 11, OUTPUT );
  pinMode( 12, OUTPUT );
  pinMode( 13, OUTPUT );

  //Set the Colum to HIGH, to make sure all the LED's are off
  digitalWrite( 5, HIGH);
  digitalWrite( 6, HIGH);
  digitalWrite( 7, HIGH);
  
  // The pixel matrix is a representation of the state
  // of each LED or pixel. It does not directly control
  // wether the LED is ON or OFF. The refreshScreen
  // method checks the pixels array and turns the LED on
  // or off accordingly.

  // Initialize the pixel matrix:
    for (int row = 0; row < 3; row++) {   
      for (int col = 0; col < 3; col++) { 
        g_pixels[row][col] = LOW;
        r_pixels[row][col] = LOW;
    }
  }

  // Initialize the RED pixel ,matrix:
  // initialize the LED pin as an output: ( To indicate buttons presses )
  pinMode(LED_PIN, OUTPUT);
 
  // Initialize the pushbutton pins as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);

  // Attach each button pin to its buttons object
  // then assign the bounce interval
  // each button object is an instantiation of the
  // Bounce2 library

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

  // initialize the pixels array with a predefined pattern.
  // This is useful for making sure all the leds are working
  memcpy( g_pixels,g_leds_on, sizeof g_leds_on ); 
  memcpy( r_pixels,r_leds_on, sizeof r_leds_on ); 
  
}

void loop() {

  bool moved = 0;
  bool selected = 0;
  bool played = 0;
  String winner = "";

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    //toggle blink cylce
    if (BLINK == LOW)
      BLINK = HIGH;
    else
      BLINK = LOW;
  }

/*
  //if(currentMillis - previousMillis > animationRate) {
    previousMillis = currentMillis;

    //call for next frame of animation every ...
    if (animation != "" ) {
      animate ( animation );
    }

  }
*/
   
  crsr = check_buttons();
  
  if ( crsr ) {
    selected = move_cursor( crsr );
    //Serial.println ( "Was cursor moved: " + String ( moved ) );
  }

  if ( selected ) {
    played = check_turn() ;
    //Serial.println ( "Was a play made: " + String ( played ) );
  }

  if ( played ) {
    winner = check_win() ;
    
  }

  if ( winner != "" ) {
    win( winner) ;
    newgame();
    
  }

  
    
  refresh_screen();
  action = "";
  
}










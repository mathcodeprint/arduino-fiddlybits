char check_buttons() {

  // This piece of code checks each of the five buttons to see if any have been pressed.
  // It uses a library called Bounce2.h, the library can be installed via the library
  // manager in the Arduino IDE using Sketch -> Include Library -> Manage Library
  
  // The Bounce2 object does not know to look at the buttons pins unless it is told to do so.
  // When you call the update() method the Bounce2 ojbect will update itself with the state
  // of each respective button.

  // In this code the Bounce2 object is instatiated as button1, button2 ... button5
  
  // Update each Bounce2 object with the current status of the Button

// button1 "Left"
// button2 "Down
// button3 "Up"
// button4 "Right"
// button5 "Select"

  
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();

  // If the button was pressed ( fell ) set the buttons
  // state to 1 ( aka HIGH )
  button1State = button1.fell();
  button2State = button2.fell();
  button3State = button3.fell();
  button4State = button4.fell();
  button5State = button5.fell(); 


  // If the button was pressed blink the LED_PIN, to show
  // the button was in fact pressed.     
  // FIXME: currently this will instantly turn indicator led back off
  //        instead turn it on for a few cycles then have a timer turn it off. 
  //        so start the timer in the else of the ternary operator
  (button1State == HIGH) ? ( digitalWrite(LED_PIN, HIGH) ):( digitalWrite(LED_PIN, LOW) );
  (button2State == HIGH) ? ( digitalWrite(LED_PIN, HIGH) ):( digitalWrite(LED_PIN, LOW) );
  (button3State == HIGH) ? ( digitalWrite(LED_PIN, HIGH) ):( digitalWrite(LED_PIN, LOW) );
  (button4State == HIGH) ? ( digitalWrite(LED_PIN, HIGH) ):( digitalWrite(LED_PIN, LOW) );
  (button5State == HIGH) ? ( digitalWrite(LED_PIN, HIGH) ):( digitalWrite(LED_PIN, LOW) );

  // Based on the button that was pressed set the action
  // to be performed by move_cursor()  

  // Actions:
  // R - move one cell to the right
  // U - move one cell up
  // U - move one cell down
  // R - move one cell to the left
  // S - select the cell to be played
  
  // N - New game
  
  if ( button1State == HIGH)  action = 'L' ;
  if ( button2State == HIGH)  action = 'D' ;
  if ( button3State == HIGH)  action = 'U' ;
  if ( button4State == HIGH)  action = 'R' ;
  if ( button5State == HIGH)  action = 'S' ;

  //if ( ( button1State == HIGH) & ( button5State == HIGH) ) action = 'N';

  //if ( button1State == HIGH)  Serial.println(" Button1 Pressed - R " );
  //if ( button2State == HIGH)  Serial.println(" Button2 Pressed - U " );
  //if ( button3State == HIGH)  Serial.println(" Button3 Pressed - D " );
  //if ( button4State == HIGH)  Serial.println(" Button4 Pressed - L " );
  //if ( button5State == HIGH)  Serial.println(" Button5 Pressed - S " );

  return ( action );
  
} 



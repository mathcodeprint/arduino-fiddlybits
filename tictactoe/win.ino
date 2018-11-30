void win( String winner) {

// this directly handles the leds
// it might be better to let refresh do its
// job.

if ( winner == "GREEN" ){

    for( int y=0; y<3;y++ ){
      //int x = 1;
      for( int x=0; x<3; x++ ){
        //ON     
        digitalWrite( col_leds[x], LOW); 
        digitalWrite( g_row_leds[y], HIGH);
        delay(25);

        //OFF
        digitalWrite( col_leds[x], HIGH);
        digitalWrite( g_row_leds[y], LOW);
        delay(25);
      }
    }
     
  delay (25);

    for( int y=0; y<3;y++ ){
      for( int x=0; x<6; x++ ){

         //ON     
        digitalWrite( col_leds[y], LOW);    // turn the LED off (Both HIGH is Off )
        digitalWrite( g_row_leds[x], HIGH); // turn the LED off (or Both LOW is Off )
        delay(25);                          // wait for a second

        //OFF
        digitalWrite( col_leds[y], HIGH);
        digitalWrite( g_row_leds[x], LOW);
        delay(25);    
        
      }
          //  Serial.print( "\n" );   
    }
     
  delay (25);

} else if ( winner == "RED" ){

    for( int y=0; y<3;y++ ){
      //int x = 1;
      for( int x=0; x<3; x++ ){
        //ON     
        digitalWrite( col_leds[x], LOW); 
        digitalWrite( r_row_leds[y], HIGH);
        delay(25);

        //OFF
        digitalWrite( col_leds[x], HIGH);
        digitalWrite( r_row_leds[y], LOW);
        delay(25);
      }
    }
     
  delay (25);

    for( int y=0; y<3;y++ ){
      for( int x=0; x<6; x++ ){

         //ON     
        digitalWrite( col_leds[y], LOW);    // turn the LED off (Both HIGH is Off )
        digitalWrite( r_row_leds[x], HIGH); // turn the LED off (or Both LOW is Off )
        delay(25);                          // wait for a second

        //OFF
        digitalWrite( col_leds[y], HIGH);
        digitalWrite( r_row_leds[x], LOW);
        delay(25);    
        
      }
          //  Serial.print( "\n" );   
    }
     
  delay (25);


}


}


//set all pixels to zero. Clearing the screen
//move cursor to starting position.
void newgame(){
  for ( int x=0; x<=3;x++ ) {
    for ( int y=0; y<=3;y++ ) {
      g_pixels[x][y] = 0;
      r_pixels[x][y] = 0;      
    }
  }

  crsr_row = 0;
  crsr_col = 0;

}


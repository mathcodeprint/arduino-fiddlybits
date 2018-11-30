
int g_preblinkState;
int r_preblinkState;

int g_pixel;
int r_pixel; 

int blinkcount;

void refresh_screen() {

  //LIGHT Played Positions
  for (int thisRow = 0; thisRow < 3; thisRow++){   
    for (int thisCol = 0; thisCol < 3; thisCol++){
   
     g_pixel = g_pixels[thisRow][thisCol];
     r_pixel = r_pixels[thisRow][thisCol];

// If the cell being refreshed is at the current
// cursor position, blink it to indicate the 
// location of the cursor.
// Otherwise refresh it normally.    

      //Turn all LED off first, turn off last led lit
      //then turn on only the next LED in refresh

      //During refresh the LED is left OFF at the end of each
      //refresh cycle.  ( Row LOW, COl HIGH ) 

      //digitalWrite(col_leds[thisCol], HIGH);
      //digitalWrite(g_row_leds[thisRow], LOW);          
      //digitalWrite(r_row_leds[thisRow], LOW); 

      //Have to call do_blink before any of the pixels are turned on

      if (current_turn == "RED" ) do_blink( thisRow, thisCol, r_pixel);                  
      if (current_turn == "GREEN" ) do_blink( thisRow, thisCol, g_pixel);                  

            
      if (g_pixel == HIGH) {         
        digitalWrite(col_leds[thisCol], LOW);
        digitalWrite(g_row_leds[thisRow], HIGH);
        do_blink( thisRow, thisCol, g_pixel);                  
      }

      if (r_pixel == HIGH) {         
        digitalWrite(col_leds[thisCol], LOW);
        digitalWrite(r_row_leds[thisRow], HIGH);  
        do_blink( thisRow, thisCol, r_pixel);                                  
      }

      //Keep each one on long enought for it to get full bright
      //Anything higher than 2 introduces flickers ?
      delay(1);
      
      digitalWrite(col_leds[thisCol], HIGH);  
      digitalWrite(g_row_leds[thisRow], LOW);   
      digitalWrite(r_row_leds[thisRow], LOW);       


    }
  }
}

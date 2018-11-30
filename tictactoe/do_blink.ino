void do_blink(int row, int col, int pixel) {
   //need to deal with when the cursor leaves the postion
    //It will be either during the blink on or
    //during the blink off.

    //    During:
    //        Blink ON and Pixel OFF
    //        Blink ON and Pixel ON
    //        Blink OFF and Pixel OFF
    //        Blink OFF and Pixel ON
  if ( row == crsr_row & col == crsr_col ){

    if ( BLINK ){
      if ( current_turn == "GREEN" ){
        digitalWrite(g_row_leds[row], HIGH);    
        digitalWrite(col_leds[col], LOW);
      }

      if ( current_turn == "RED" ){
        digitalWrite(r_row_leds[row], HIGH);    
        digitalWrite(col_leds[col], LOW);
      }
    }

    if( !BLINK ){
      if ( current_turn == "GREEN" ){
        digitalWrite(g_row_leds[row], LOW);    
        digitalWrite(col_leds[col], HIGH);
      }
      if ( current_turn == "RED" ){
        digitalWrite(r_row_leds[row], LOW);    
        digitalWrite(col_leds[col], HIGH);
      }
    }
  }
}


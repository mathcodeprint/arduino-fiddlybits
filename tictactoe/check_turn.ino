bool check_turn (){
    bool valid;

     //Serial.println("Checking play");                                          

    if ( g_pixels[crsr_row][crsr_col] || r_pixels[crsr_row][crsr_col] ) {
      Serial.println ("CELL TAKEN");
      valid = 0;
    } else if ( current_turn == "RED") {
      Serial.print ("RED Turn taken: \t");
      r_pixels[crsr_row][crsr_col] = 1;
      print_pixel_values();
      current_turn = "GREEN";
      valid = 1;
    } else if (  current_turn == "GREEN") {
      Serial.print ("GREEN Turn taken: \t");
      g_pixels[crsr_row][crsr_col] = 1;
      print_pixel_values();
      current_turn = "RED";
      valid = 1;
    } else {
      Serial.println (  "Unexpected result");
    }
    return ( valid );
}




void print_pixel_values() {

  
  Serial.print ("COL:\t\t");

  for ( int y =0 ; y<3 ; y++ ){
    
    Serial.print ( col_leds[y] );
    Serial.print ( " (" );
    Serial.print (digitalRead( col_leds[y]) );
    Serial.print ( ")\t" );
  }

  Serial.print( "\n" );
  
  Serial.println( "------\t|\t\t=======\t=======\t=======" );
  
  for ( int i = 0 ; i<3 ; i++) {
     Serial.print("ROW G|R: " + String(  g_row_leds[i] ) + "\t|" + String(  r_row_leds[i] )  + " | \t") ;
      
    for ( int j = 0 ; j < 3 ; j++ ) {      
      Serial.print( String( g_pixels[i][j]) + "/" + String( r_pixels[i][j] ) + "\t" );      
    }
    Serial.println();      
  }
}

String check_win() {

  // There is probably a nice clean way to do this with bitwise AND
  // or matrix math. I just wanted something easy enough to 
  // understand by a novice programmer.
  

  String played = "";

  bool row_check = 0 ;

  bool red_win = false;
  bool grn_win = false;

  // Check Rows

  for ( int x =0; x <3 ; x++ ) {
    if ( r_pixels[x][0] & r_pixels[x][1] & r_pixels[x][2]) {
      winningPlayer = "RED Row Win";
      Serial.println( "RED ROW WIN" );
      red_win = true;
    return "RED";
    } else {
      Serial.println( "No red row win" );
    }
   
    if ( g_pixels[x][0] & g_pixels[x][1] & g_pixels[x][2]) {
      winningPlayer = "GREEN Rown Win";
      Serial.println( "GREEN ROW WIN" );      
      grn_win = true;
    return "GREEN";
    } else {
      Serial.println( "No green row win" );
    }

  }


  //Check for columnar win

  for ( int x =0; x <3 ; x++ ) {
    if ( r_pixels[0][x] & r_pixels[1][x] & r_pixels[2][x] ) {
      Serial.println( "RED COL WIN" );
      winningPlayer = "RED Col";
      red_win = true;      
      return "RED";
    }
   
    if ( g_pixels[0][x] & g_pixels[1][x] & g_pixels[2][x] ) {
      winningPlayer = "GREEN COL WIN";
      grn_win = true;      
      return "RED";
    }
  }

  //Check for diagonal win

  if (  r_pixels[0][0] & r_pixels[1][1] & r_pixels[2][2] ) {
    Serial.println ( "Red Diagonal" );
      red_win = true;      
    
    return "RED";
  }
  if (  r_pixels[0][2] & r_pixels[1][1] & r_pixels[2][0] ) {
    Serial.println ( "Red Diagonal" );
    red_win = true;      
    return "RED";
  }

  if (  g_pixels[0][0] & g_pixels[1][1] & g_pixels[2][2] ) {
    Serial.println ( "Green Diagonal" );
          grn_win = true;      

    return "GREEN";
  }
  if (  g_pixels[0][2] & g_pixels[1][1] & g_pixels[2][0] ) {
    Serial.println ( "Green Diagonal" );
              grn_win = true;      

    return "GREEN";
  }


  //Check Stalemate

  // If all pixels played but no winner
  // The no winner is determined by inference
  // 
  

  if( grn_win == false and red_win == false ){
  
       
  
  }
  
  return "";
  
}
 




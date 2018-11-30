boolean move_cursor( char thisCursor) {

  boolean selected = false;

  //Store last cursor before changing.
  //Only store it if it changes

    
  switch ( thisCursor ){

    case 'L':         
      last_crsr_col = crsr_col;
      last_crsr_row = crsr_row;

      // Left and right movement switches 
      // between colums
            
      if ( crsr_col > 0 ) {
        crsr_col--;
      } else if ( crsr_col == 0 ) {
        crsr_col = grid_max_col;
      }

      //Serial.println ( "L Selected" );
      //Serial.println ( "Cursor at \ty: " + String(crsr_col) + "\tx: " + String(crsr_row) + "\t Previous Cursor y" + last_crsr_col + "\tx: " + last_crsr_row  );
      break;
    
    case 'R':      
      last_crsr_row = crsr_row;
      last_crsr_col = crsr_col;

      if( crsr_col < grid_max_col ) {
        crsr_col++;
      } else if ( crsr_col == grid_max_col ) {
        crsr_col = 0; 
      }

      //Serial.println ( "R Selected" );

      break;
    
    // Up and down movement switchs between rows  
    case 'D':
      last_crsr_row = crsr_row;
      last_crsr_col = crsr_col;


      if ( crsr_row < grid_max_row ) {
        crsr_row++;
      } else if ( crsr_row == grid_max_row) {
        crsr_row = 0;
      }

      //Serial.println ( "D Selected" );

      break;
      
    case 'U':
      last_crsr_row = crsr_row;
      last_crsr_col = crsr_col;


      if( crsr_row >  0 ) {
        crsr_row--;
      } else if ( crsr_row == 0 ) {
        crsr_row = grid_max_row;
      }
    
      //Serial.println ( "U Selected" );
      
      break;

    case 'S':      
      selected = true;
      break;      
    default:
      selected = false;
      break;

      //;
  }



  //reset the action so this only happens once per press
  action = "";

  return ( selected );
}


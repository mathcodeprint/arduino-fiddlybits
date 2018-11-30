
  const int spinAnimation[8][3][3] = { 
                              { {1,0,0},
                                {0,1,0},
                                {0,0,1} },                             
                              { 
                                {0,1,0},
                                {0,1,0},
                                {0,1,0} },                                                         
                              { 
                                {0,0,1},
                                {0,1,0},
                                {1,0,0} },
                             { 
                                {0,0,0},
                                {1,1,1},
                                {0,0,0} },
                             { 
                                {1,0,0},
                                {0,1,0},
                                {0,0,1} },
                             { 
                                {0,1,0},
                                {0,1,0},
                                {0,1,0} },
                              { 
                                {0,0,1},
                                {0,1,0},
                                {1,0,0} },
                              { 
                                {0,0,0},
                                {1,1,1},
                                {0,0,0} } };



const int demoAnimation[8][3][3] = { { {1,0,0},
                              {0,1,0},
                              {0,0,1} },                             
                            { 
                              {0,0,1},
                              {0,1,0},
                              {1,0,0} },                                                         
                            { 
                              {1,1,1},
                              {0,0,0},
                              {0,0,0} },                             
                            { 
                              {0,0,0},
                              {1,1,1},
                              {0,0,0} },
                            { 
                              {0,0,0},
                              {0,0,0},
                              {1,1,1} },
                            { 
                              {1,0,0},
                              {1,0,0},
                              {1,0,0} },
                            { 
                              {0,1,0},
                              {0,1,0},
                              {0,1,0} },

                            { 
                              {0,0,0},
                              {0,0,0},
                              {0,0,0} },

                              
                              };

  
void demo(  ) {
  /*
  int gPlayed[3][3];
  int rPlayed[3][3];

  //backup current positions

  memcpy ( gPlayed,g_pixels, sizeof g_pixels );
  memcpy ( rPlayed,r_pixels, sizeof r_pixels );

  //zero out pixels

  memcpy ( g_pixels,g_leds_on, sizeof g_leds_on );
  memcpy ( r_pixels,r_leds_on, sizeof r_leds_on );

  
    // loop through animation array call refresh each time.
  
    memcpy( r_pixels,demoAnimation[], sizeof demoAnimation[] ); 
    print_pixel_values();
    refresh_screen();
    delay(1000);

    memcpy( g_pixels,demoAnimation[], sizeof demoAnimation[] ); 
    print_pixel_values();
    refresh_screen();
    delay(1000);

   //increment counter
    

   //zero out pixels

   memcpy ( g_pixels,g_leds_on, sizeof g_leds_on );
   memcpy ( r_pixels,r_leds_on, sizeof r_leds_on );

   //restore current positions
   memcpy ( g_pixels,gPlayed, sizeof gPlayed );
   memcpy ( r_pixels,rPlayed, sizeof rPlayed );

    */
  }

void spin(){
}

void wipe(){
}

void alternate() {
  
  //memcopy red pixels 
  //memcopy green pixels
  //turn red on adn green off
  //delay
  //turn green on and red off
  //edlay
  //loop 3 or 4 times.
  
  }



void animate( String animationtype ) {

  //call demo it should run one frame for each call
  //when no more frames it should clear the animation variable.
 //demo();
 
}



 


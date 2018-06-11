// set stuff up
#include <Tle493d_w2b6.h>
Tle493d_w2b6 mag3DSensor = Tle493d_w2b6();
 
void setup() {
 
  // more setup
  mag3DSensor.begin();
 
  mag3DSensor.enableTemp();
  
  pinMode(LED_BUILTIN, OUTPUT);
 
}
 
void loop() {
  
  // get sensor info
  mag3DSensor.updateData();
 
   //check if there's a magnet 
   if (abs(mag3DSensor.getX()) > 1.0 || abs(mag3DSensor.getY()) > 1.0 || abs(mag3DSensor.getZ()) > 1.0 ) {
     
    //turn on the light
    digitalWrite(LED_BUILTIN, HIGH);
  
  } else {
     
    //turn off the light
    digitalWrite(LED_BUILTIN, LOW);
   
  }
  // don't spam, kids
  delay(50);
 
}

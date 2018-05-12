int incomingByte = 0;   // for incoming serial data
int data = 0;

void setup() {
        Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
        pinMode(12, OUTPUT);
}

// main section
void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                data = 1;

                if (incomingByte == 48) { // if it recevies a 0
                  digitalWrite(12, LOW); //turn off the magnet
                  Serial.print("0");
                  delay(100);
                }else if (incomingByte == 49) { //if it recieves a 1
                  digitalWrite(12, HIGH); //turn on the magnet
                  Serial.print("1");
                  delay(100);
                }else{
                  Serial.print("?");
                }
        //clean things up        
        }else{
          if (data == 1){
            digitalWrite(12, LOW);
            Serial.println("");
            data = 0;
          }
        }
}

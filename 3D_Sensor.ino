#include <Tle493d_w2b6.h>

Tle493d_w2b6 Tle493dMagnetic3DSensor = Tle493d_w2b6(Tle493d_w2b6::LOWPOWERMODE);
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Tle493dMagnetic3DSensor.begin();
  //The highest adjustable range is used for all three directions, i.e., within half of the total value range INT is disabled 
  Tle493dMagnetic3DSensor.setWakeUpThreshold(1,-1,1,-1,1,-1);

  //The update rate is set to 3 (fastest is 0 and slowest is 7)
  Tle493dMagnetic3DSensor.setUpdateRate(3);
  pinMode(14, OUTPUT);
}

void loop() {
  Tle493dMagnetic3DSensor.updateData();

  Serial.print(Tle493dMagnetic3DSensor.getX());
  Serial.print(" ; ");
  Serial.print(Tle493dMagnetic3DSensor.getY());
  Serial.print(" ; ");
  Serial.println(Tle493dMagnetic3DSensor.getZ());

  if (Tle493dMagnetic3DSensor.getX() > -1.0) {
    digitalWrite(14, HIGH);
  } else {
    digitalWrite(14, LOW);
  }
  delay(500);
}

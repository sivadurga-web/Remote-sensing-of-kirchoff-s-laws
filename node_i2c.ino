#include <Wire.h>

void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("10");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */
int j=0;
 Wire.requestFrom(8, 5); /* request & read data of size 13 from slave */
 while(Wire.available()){
    char c = Wire.read();j++;
  Serial.print(c);
 }
 Serial.println(j);
 delay(1000);
}

#include <Servo.h>
#define SERVO_PIN 9
Servo servo;
int pos = 0; // angle

void setup() {
  printf("servo ready");
  servo.attach(SERVO_PIN);

}

void loop() {
  // for(pos= 0; pos <= 180; pos +=1) {
  //   servo.write(pos);
  //   delay(15);
  // }

  // for(pos =180; pos >= 0; pos -= 1) {
  //   servo.write(pos);
  //   delay(15);
  // }
  servo.write(0);
  delay(500);

  servo.write(30);
  delay(500);
  servo.write(60);
  delay(500);
  servo.write(90);
  delay(500);
  servo.write(120);
  delay(500);
  servo.write(160);
  delay(500);
  servo.write(180);
  delay(500);

  servo.write(160);
  delay(500);
  servo.write(120);
  delay(500);
  servo.write(90);
  delay(500);
  servo.write(60);
  delay(500);
  servo.write(30);
  delay(500);
  servo.write(0);
  delay(500);
}

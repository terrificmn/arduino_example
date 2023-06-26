#define LED_PIN 13

// Led는 다리가 긴 부분이 + 임, +에에 220짜리 저항을 연결해주고 
// +5v에 +선을 연결
// - 는 7번등의 핀에 연결
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  digitalWrite(LED_PIN, HIGH);
  delay(2000);

  digitalWrite(LED_PIN, LOW);
  delay(2000);

}

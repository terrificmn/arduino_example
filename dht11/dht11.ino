int DHT11_PIN = 7;

unsigned char dat[5];

unsigned char readDht() {
  unsigned char data;
  for(int i=0; i<8; i++) {
    if(digitalRead(DHT11_PIN) == LOW) {
      while(digitalRead(DHT11_PIN) == LOW);
      delayMicroseconds(30);

      if(digitalRead(DHT11_PIN) == HIGH) {
        data = (1 << (7-i));
      }
      while(digitalRead(DHT11_PIN) == HIGH);
    }
  }
  return data;
}

void startToRead() {
  digitalWrite(DHT11_PIN, LOW);
  delay(20);

  digitalWrite(DHT11_PIN, HIGH);
  delayMicroseconds(40);

  pinMode(DHT11_PIN, INPUT);
  while(digitalRead(DHT11_PIN) == HIGH);

  delayMicroseconds(80);
  if(digitalRead(DHT11_PIN) == LOW);
  delayMicroseconds(80);

  for(int i=0; i <4; i++) {
    dat[i] = readDht();
  }

  pinMode(DHT11_PIN, OUTPUT);
  digitalWrite(DHT11_PIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(DHT11_PIN, OUTPUT);

}

void loop() {
  Serial.print("start to read");
  startToRead();
  Serial.print("humdity: ");
  Serial.print(dat[0], DEC);
  Serial.print('.');
  Serial.print(dat[1], DEC);
  Serial.print("%,   ");
  Serial.print("temperature: ");
  Serial.print(dat[2], DEC);
  Serial.print('.');
  Serial.print(dat[3], DEC);
  Serial.println('C');
  delay(2000);
}

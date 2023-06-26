/// GND, R,G,B 핀들로 구성이 되어 있는 led
#define BLUE 26  //6  // 기판에 적혀있는 BGR로 각각 적혀 있는 핀을 연결해서 셋팅, 순서는 상관없으나 BGR로 셋팅
#define GREEN 27  //5
#define RED 14  //3


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

}

void loop() {
  int red_value;
  int green_value;
  int blue_value;

  red_value = 255;
  green_value = 0;
  blue_value = 0;

  for(int i =0; i< 255; i++) {
    red_value -= 1;
    green_value += 1;
    analogWrite(RED, red_value);
    analogWrite(GREEN, green_value);
    delay(10);
  }

  red_value = 0;
  green_value = 255;
  blue_value = 0;
  for(int i=0; i < 255; i++) {
    green_value -= 1;
    blue_value += 1;
    analogWrite(GREEN, green_value);
    analogWrite(BLUE, blue_value);
    delay(10);
  }

  red_value = 0;
  green_value = 0;
  blue_value = 255;
  for(int i=0; i<255; i++) {
    blue_value -= 1;
    red_value +=1;
    analogWrite(BLUE, blue_value);
    analogWrite(RED, red_value);
    delay(10);
  }



}

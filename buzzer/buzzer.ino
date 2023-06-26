#define BUZZER 7 // BUZZER를 사용할 핀 define, +는 5v, 나머지는 7pin에 연결

// 주파수로 사용할 톤 정의 각 노트는 hz로 정의
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_ES5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047

int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

int duration = 500;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // buzzer사용은 tone()함수 호출로 사용
  for(int note=0; note < 8; note++) {
    tone(BUZZER, melody[note], duration);
    delay(1000);
  }

  for(int note=7; note >= 0; note--) {
    tone(BUZZER, melody[note], duration);
    delay(1000);
  }

  delay(1000);
}

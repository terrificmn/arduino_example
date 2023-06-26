// 에러는 없지만 fail.. 회로 사진에 맞춰서 연결을 잘 했으나 안됨.. 따로 트러블 슈팅 안함

// #define ANODE_TYPE
int num_array[10][7] = {
                        { 1, 1, 1, 1, 1, 1, 0 },  // 0
                        { 0, 1, 1, 0, 0, 0, 0 }, // 1
                        { 1, 1, 0, 1, 1, 0, 1 }, //2
                        { 1, 1, 1, 1, 0, 0, 1 }, //3
                        { 0, 1, 1, 0, 0, 1, 1 }, //4
                        { 1, 0, 1, 1, 0, 1, 1 }, // 5
                        { 1, 0, 1, 1, 1, 1, 1 }, // 6
                        { 1, 1, 1, 0 ,0, 0, 0 }, //7
                        { 1, 1, 1, 1, 1, 1, 1 }, //8
                        { 1, 1, 1, 0, 0, 1, 1 }
                      };

void numWrite(int);

void setup() {
  pinMode(2, OUTPUT); //a
  pinMode(3, OUTPUT); //b
  pinMode(4, OUTPUT); //c
  pinMode(5, OUTPUT); //d
  pinMode(6, OUTPUT); //e
  pinMode(7, OUTPUT); //f
  pinMode(8, OUTPUT); //b

  for(int j=2; j <= 8; j++) {
    digitalWrite(j, HIGH);
  }
}

void loop() {
  for(int counter=10; counter > 0; --counter) {
    delay(1000);
    numWrite(counter-1);
  }
  delay(1000);
}

void numWrite(int number) {
  int pin=2;
  for(int j=0; j < 7; j++) {
    // #ifdef ANODE_TYPE
    // digitalWrite(pin, !num_array[number][j]);
    // #else
    // digitalWrite(pin, num_array[number][j]);
    // #endif
    digitalWrite(pin, num_array[number][j]);
    pin++;
  }
}


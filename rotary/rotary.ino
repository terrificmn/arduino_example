#define INPUT_CLK 4
#define INPUT_DT 5

// led
#define LED_CW 8
#define LED_CCW 9

int counter = 0;   // it will be up and down
int current_state_clk;
int previous_state_clk;

String enc_dir = ""; 

void setup() {
  // set encoder pins as inputs
  pinMode(INPUT_CLK, INPUT);
  pinMode(INPUT_DT, INPUT);

  // set LED pins as outputs
  pinMode(LED_CW, OUTPUT);
  pinMode(LED_CCW, OUTPUT);

  // Setup Serial monitor
  Serial.begin(9600);

  // read the initial state of INPUT_CLK
  //assign to previous_state_clk variable
  // 현재 INPUT_CLK를 읽어서 previous_state_clk 설정
  previous_state_clk = digitalRead(INPUT_CLK);

}

void loop() {
  // read the current state of INPUT_CLK
  current_state_clk = digitalRead(INPUT_CLK);

  // setup에서 처음 설정했던 previous_sttae_clk 값 또는 loop에서 계속 그 전 상태와 변경 확인
  if(current_state_clk != previous_state_clk) {
    // INPUT_DT is different than the INPUT_CLK state 
    // then the encoder is rotating counterclockwise
    if(digitalRead(INPUT_DT) != current_state_clk) {
      counter--;
      enc_dir = "CCW";
      digitalWrite(LED_CW, LOW);
      digitalWrite(LED_CCW, HIGH);
    } else {
      counter++;
      enc_dir = "CW";
      digitalWrite(LED_CW, HIGH);
      digitalWrite(LED_CCW, LOW);
    }

    Serial.print("Direction: ");
    Serial.print(enc_dir);
    Serial.print(", value: ");
    Serial.println(counter);
  }

  // update previous_state_clk with the current state
  previous_state_clk = current_state_clk;

}

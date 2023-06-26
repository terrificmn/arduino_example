#include <Arduino.h>
// Include Wire library for I2C
#include <Wire.h>
#include <DHT.h>  // Adafruit_Sensors library (설치되어있음)

// Include new Liquid Crystal library for I2C (다운로드 받아야 한다)
// library 에서 Liquid crystal  로 검색하면 제작자 F Malpartida 로 받는다  
#include <LiquidCrystal_I2C.h>

// 요렇게 하는 것은 예전 버전 
// Define LCD pinout
// const int en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

// // define I2C address - 위에서 address 확인 (주석된 코드)
const int i2c_addr = 0x27;

#define DHT_PIN 7
#define DHT_TYPE DHT22 
// // or DHT11 로 지정

float hum;
float temp;

LiquidCrystal_I2C lcd(i2c_addr, 16, 2);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    // // set display type as 16 char, 2 rows
    // // lcd.begin(16, 2);  /// 예전 버전
    lcd.init();                      // initialize the lcd 

    dht.begin();

    // // Print a message to the LCD.
    lcd.backlight();  // backlight를 안키면 거의 안보임 

    // // // // print on first row
    lcd.setCursor(0, 0);
    lcd.print("Now starting.. ");

    lcd.setCursor(0,1);
    lcd.print("");

}


void loop() {
    delay(2000);  // for dht sensor can stablize

    hum = dht.readHumidity();
    temp = dht.readTemperature();

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" c");

    lcd.setCursor(0, 1);
    lcd.print("Humid: ");
    lcd.print(hum);
    lcd.print(" %");
    
}
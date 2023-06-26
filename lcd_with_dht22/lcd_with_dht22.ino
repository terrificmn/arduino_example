#include <Arduino.h>
// Include Wire library for I2C
#include <Wire.h>
#include <DHT.h>  // Adafruit_Sensors library (설치되어있음)

// Include new Liquid Crystal library for I2C (다운로드 받아야 한다)
// library 에서 Liquid crystal  로 검색하면 제작자 F Malpartida 로 받는다  
#include <LiquidCrystal_I2C.h>

// // define I2C address - lcd의 address 확인하는 코드 dht11 에서 확인하기
const int i2c_addr = 0x27;

#define DHT_PIN 7
#define DHT_TYPE DHT22 

float hum;
float temp;

// I2C 연결된 보드이면 SDA, SCL 만 연결해준다 
LiquidCrystal_I2C lcd(i2c_addr, 16, 2);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    lcd.init();   // initialize the lcd 

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
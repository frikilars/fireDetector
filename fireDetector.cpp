#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin konfigurasi
#define DHTPIN 2              
#define DHTTYPE DHT22         
#define LED_PIN 3             
#define BUZZER_PIN 4          
#define MQ2_PIN A0            
#define RELAY_PIN 5           
#define FLAME_PIN 6           

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(MQ2_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);

  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.backlight(); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Alarm Kebakaran");
  delay(1000);
}

void loop() {
  float suhu = dht.readTemperature();
  int mq2Value = analogRead(MQ2_PIN);       
  int flameDetected = digitalRead(FLAME_PIN); // LOW = api terdeteksi

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" *C | MQ-2: ");
  Serial.print(mq2Value);
  Serial.print(" | Flame: ");
  Serial.println(flameDetected == LOW ? "API TERDETEKSI" : "AMAN");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("S:");
  lcd.print(suhu, 1);
  lcd.print((char)223); // simbol derajat
  lcd.print("C G:");
  lcd.print(mq2Value);

  lcd.setCursor(0, 1);
  lcd.print(flameDetected == LOW ? "API TERDETEKSI" : "AMAN");

  if (suhu >= 60.0 || mq2Value >= 400 || flameDetected == LOW) {
    tone(BUZZER_PIN, 1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH); 
    delay(300);

    tone(BUZZER_PIN, 1500);
    digitalWrite(LED_PIN, LOW);
    delay(300);
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW); 
  }

  delay(300);
}

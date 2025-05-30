#define BLYNK_TEMPLATE_ID "YOURTEMPPLATEID"
#define BLYNK_TEMPLATE_NAME "YOURTEMPLATENAME"
#define BLYNK_AUTH_TOKEN "YOURAUTHTOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// WiFi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Sensor pin configuration
#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_PIN 13
#define BUZZER_PIN 12
#define MQ2_PIN 34
#define RELAY_PIN 14
#define FLAME_PIN 27

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void bacaSensor() {
  float temperature = dht.readTemperature();
  int mq2Value = analogRead(MQ2_PIN);
  int flameDetected = digitalRead(FLAME_PIN);

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" *C | MQ-2: ");
  Serial.print(mq2Value);
  Serial.print(" | Flame: ");
  Serial.println(flameDetected == HIGH ? "API TERDETEKSI" : "AMAN");

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, mq2Value);
  Blynk.virtualWrite(V2, flameDetected == HIGH ? 1 : 0);

  if (temperature > 60 || mq2Value > 400 || flameDetected == HIGH) {
    tone(BUZZER_PIN, 1000);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(FLAME_PIN, INPUT);

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, bacaSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}


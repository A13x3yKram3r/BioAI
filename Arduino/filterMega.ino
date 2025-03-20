#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN A3     // Пин для DHT22
#define DHTTYPE DHT22

SoftwareSerial esp(10,11);

DHT dht(DHTPIN, DHTTYPE);
// Пины для аналоговых датчиков
int sensorPins[] = {A0, A1, A2};

void setup() {
  Serial.begin(9600);  // Начинаем серийный монитор для передачи данных
  dht.begin();
}

void loop() {
  // Чтение значений с датчиков
  int sensorValues[3];
  for (int i = 0; i < 3; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
  
  // Чтение значения температуры и влажности с DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Формируем строку с данными
  String data = String(sensorValues[0]) + " " + String(sensorValues[1]) + " " + String(sensorValues[2]) + " " + String(sensorValues[3]) + " " + String(temperature) + " " + String(humidity);
  
  // Отправляем строку на NodeMCU (ESP8266)
  esp.println("S" + data);
  
  delay(2000);  // Задержка 2 секунды
}

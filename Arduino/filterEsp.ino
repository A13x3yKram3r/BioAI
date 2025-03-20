#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "1234567891488";
const char* password = "MSIHS";
const char* serverName = "http://sehriyospace.uz/bioai/bioFilter/index.php";  // Адрес вашего сервера

void setup() {
  Serial.begin(9600);  // Начинаем серийный монитор
  WiFi.begin(ssid, password);
  
  // Ждем подключения к WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');  // Чтение строки данных с Arduino
    sendDataToServer(data);  // Отправка данных на сервер
  }
  
  delay(2000);  // Задержка 2 секунды
}

void sendDataToServer(String data) {
  HTTPClient http;
  
  // Открываем соединение с сервером
  http.begin(serverName);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Формируем данные для отправки
  String httpRequestData = "data=" + data;
  
  // Отправляем POST-запрос
  int httpResponseCode = http.POST(httpRequestData);
  
  if (httpResponseCode > 0) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Error in sending data");
  }
  
  http.end();  // Закрытие соединения
}
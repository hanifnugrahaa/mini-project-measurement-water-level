#include <NewPing.h>
#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <time.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define trigPin 2
#define echoPin 4
#define maxDistance 400
#define Wifi_SSID ""
#define Wifi_Password ""
#define API_Key ""
#define Database_URL ""

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

bool signUp = false;
unsigned long previousMillis = 0;
const long interval = 1000;

NewPing sonar(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);

  WiFi.begin(Wifi_SSID, Wifi_Password);
  Serial.println("Menghubungkan ke WiFi...");
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Gagal terhubung dengan WiFi..");
    Serial.print("Status WiFi : ");
    Serial.println(WiFi.status());
  }
  Serial.print("Terhubung dengan WiFi : ");
  Serial.println(WiFi.localIP());
  Serial.println("");

  // Konfigurasi ke waktu real dengan NTP
  configTime(7 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.print("Melakukan sinkronisasi waktu");
  while(time(nullptr) < 100000){
    Serial.println("Menunggu sinkronisasi waktu");
  }
  Serial.println("Waktu telah berhasil disinkronisasi");

  // Konfigurasi dengan Firebase
  config.api_key = API_Key;
  config.database_url = Database_URL;
  
  Serial.println("Program pengukuran ketinggian air dimulai...");
  Serial.println("============================================");
  delay(1000);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
      int ketinggian = sonar.ping_cm();
      Serial.print("Ketinggian air terdeteksi : ");
      Serial.print(ketinggian);
      Serial.println(" cm");
  }

}
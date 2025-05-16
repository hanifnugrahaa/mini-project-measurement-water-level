#include <NewPing.h>

#define trigPin 2
#define echoPin 4
#define maxDistance 400

NewPing sonar(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  Serial.println("Program pengukuran ketinggian air dimulai...");
  Serial.println("============================================");
  delay(1000);
}

void loop() {
  int ketinggian = sonar.ping_cm();
  Serial.print("Ketinggian air terdeteksi : ");
  Serial.print(ketinggian);
  Serial.println(" cm");
  delay(1000);
}

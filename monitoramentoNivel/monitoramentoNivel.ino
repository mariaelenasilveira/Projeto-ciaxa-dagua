
#include <NewPing.h>

#define TRIGGER_PIN1  10 
#define ECHO_PIN1     9
#define TRIGGER_PIN2  12 
#define ECHO_PIN2     11  
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define saidaBomba1 7
#define saidaBomba2 8

int sensor1;
int sensor2;

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(800);                     

////////////// Sensor 1 ////////////////
  Serial.print("Sensor1: ");
  sensor1 = sonar1.ping_cm();
  Serial.print(sonar1.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

////////////// Bomba 1 ////////////////
  if (sensor1 > 120) {
    digitalWrite(saidaBomba1, HIGH);
  } else if (sensor1 < 10) {
    analogWrite(saidaBomba1, LOW);
  }

////////////// Sensor 2 ////////////////
  Serial.print("Sensor2: ");
  sensor2 = sonar2.ping_cm();
  Serial.print(sonar2.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

////////////// Bomba 2 ////////////////
  if (sensor2 > 120) {
    digitalWrite(saidaBomba2, HIGH);
  } else if (sensor2 < 10) {
    analogWrite(saidaBomba2, LOW);
  }
}

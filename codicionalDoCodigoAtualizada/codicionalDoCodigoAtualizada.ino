
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
int cont= 0;
int soma1= 0;
int soma2 = 0;

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(300);                     
  cont = cont + 1;
    
////////////// leitura Sensor 1 ////////////////
  sensor1 = sonar1.ping_cm();
  soma1 = soma1 + sensor1;
  Serial.print("Sensor1: ");
  Serial.print(sonar1.ping_cm()); 
  Serial.println("cm");

////////////// leitor Sensor 2 ////////////////
  sensor2 = sonar2.ping_cm();
  soma2 = soma2 + sensor2;
  Serial.print("Sensor2: ");
  Serial.print(sonar2.ping_cm()); 
  Serial.println("cm");

//A cada 70 leituras, faz uma média para controlar o acionamento das bombas
  if (cont == 70){
    controle();
    cont = 0;
    soma1 = 0;
    soma2 = 0;
  }
}

void controle(){
  int valorSensor1 = soma1/10;
  int valorSensor2 = soma2/10;

  ////////////// Bomba 1 ////////////////
  if (valorSensor1 > 120) {
    digitalWrite(saidaBomba1, HIGH);
  } else if (sensor1 < 20) {
    digitalWrite(saidaBomba1, LOW);
  }

  ////////////// Bomba 2 ////////////////
  if (valorSensor2 > 120) {
    digitalWrite(saidaBomba2, HIGH);
  } else if (sensor2 < 20) {
    digitalWrite(saidaBomba2, LOW);
  }
}

/* codigo de teste inicial simples, simulando a entrada do sensor (potenciometro) e o acionamento automatico da bomba (led) */

#define entradaSensor1 0   // Define o pino analógico em que o potenciômetro(sensor1) vai ser conectado 
#define saidaBomba1 9   // Define o pino que terá um LED e um resistência ligada ao terra 

int valorSensor1 = 0; //Variável que armazena o valor da leitura do sensor1
bool flagBomba = false; // se a bomba esta ligada

void setup() {  
  Serial.begin(9600);
  pinMode(saidaBomba1,OUTPUT); // Configura o pino do LED(bomba1)como saída 

} 

void loop() {   

  valorSensor1 =  analogRead(entradaSensor1); //leitura sensor1
  valorSensor1 = map(valPot,0,1023,0,255); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255 
  Serial.println(valPot);

// Supondo que a entrada do potenciometro 0 seja caixa dagua cheia e 255 seja o nivel da boia mais baixa, ao atingir 254 a bomba liga e ao atingir novamente 1 ela desliga  
  if (valorSensor1 > 254) {
    analogWrite(saidaBomba1, HIGH);
    flagBomba = true;
  } else if (valorSensor1 < 1) {
    analogWrite(saidaBomba1, LOW);
    flagBomba = false;
  }

}
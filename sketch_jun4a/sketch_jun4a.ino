// Desenvolvido por Tiago Barros em 04/06/2025
// Este codigo foi testado em um Arduino Nano com um motor de passo de cinco fios modelo 24BYJ, usando o CI uln2003
// O número de passos por volta (para o 24BYJ) geralmente é 512 passos
// O motor de passo foi testado em velocidades de 3 a 10 ms

// Define os pinos de controle do motor de passo
const byte pin1 = 8; // Pino IN1 do ci
const byte pin2 = 9; // Pino IN2 do ci
const byte pin3 = 10; // Pino IN3 do ci
const byte pin4 = 11; // Pino IN4 do ci

// Função para girar o motor de passo
void girar(int passos, bool sentidoHorario, byte velocidade) {
  // sentido horário
  if(sentidoHorario == true){
    for (int i = 0; i < passos; i++) {
      digitalWrite(pin4, LOW);
      digitalWrite(pin1, HIGH);
      delay(velocidade);

      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      delay(velocidade);

      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      delay(velocidade);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      delay(velocidade);
    }
    // sentido anti-horário
  } else{
    for (int i = 0; i < passos; i++) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin4, HIGH);
      delay(velocidade);

      digitalWrite(pin4, LOW);
      digitalWrite(pin3, HIGH);
      delay(velocidade);

      digitalWrite(pin3, LOW);
      digitalWrite(pin2, HIGH);
      delay(velocidade);

      digitalWrite(pin2, LOW);
      digitalWrite(pin1, HIGH);
      delay(velocidade);
    }
  }
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  // Gira o motor uma volta no sentido horário
  girar(512,true,5);
  delay(3000);
  
  // Gira o motor uma volta no sentido anti-horário
  girar(512,false,5);
  delay(3000);
}

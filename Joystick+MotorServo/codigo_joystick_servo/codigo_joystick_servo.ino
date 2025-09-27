#include <Servo.h>

Servo meuServo;

const int servoPin = 12;
const int vrxPin = A1;
const int vryPin = A2; // opcional se não usar
const int swPin = 6;   // botão do joystick

void setup() {
  meuServo.attach(servoPin);
  pinMode(swPin, INPUT_PULLUP); // botão do joystick
  Serial.begin(9600);           // para debug
}

void loop() {
  int xValor = analogRead(vrxPin);   // lê o eixo X
  int yValor = analogRead(vryPin);   // lê o eixo Y (opcional poque o motor só vai da esquerda pra direita não de cima pra baixo, mas vou ensinar com ele )
  int resetBotao = digitalRead(swPin); // lê o botão. (ele só serve pra resetar o motor pro meio caso aconteça alguma coisa)

  // "converte" os valores do joystick e do mmotor servo pra funcionar. O eixo X de 0-1023 para 0-180°
  int pos = map(xValor, 0, 1023, 0, 180);
  meuServo.write(pos);

  // isso faz o botão "resetar" Exemplo: botão reseta posição para 90°
  if(resetBotao == LOW){
    meuServo.write(90);
  }

  // Debug (não precisa mas é bom colocar)
  Serial.print("X: "); Serial.print(xValor);
  Serial.print("  Y: "); Serial.print(yValor);
  Serial.print("  Botao: "); Serial.println(resetBotao);

  delay(20); // suaviza o movimento do motor
}

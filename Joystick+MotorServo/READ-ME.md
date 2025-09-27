# 🎮 Controle de Motor Servo com Joystick – Arduino Uno

## 📖 Sobre o projeto

Este projeto mostra como usar o **joystick analógico** para controlar um **motor servo** no Arduino Uno.  

O objetivo é ensinar como:  

- Entender e conectar os pinos do motor servo  
- Conectar e usar o joystick analógico  
- Configurar o Arduino para ler o joystick e mover o servo  
- Criar controle manual do servo usando o joystick  

---

## 🖥️ Materiais Necessários

- [Arduino Uno](https://encrypted-tbn2.gstatic.com/shopping?q=tbn:ANd9GcQRtwcF6C-kSV1O7pvOqQzuZjnJYvJAI6pvpYJUXpu050zmPYME4gpI78LpH_1cSyKKRJPEt1LvOhMUNU7OPSAXMlHVzhC4Vf6gACKyJOUabMSls_ayqGljEA) 
- [Motor Servo](https://www.robocore.net/produtos/servo-motor-9g)  
- [Joystick Analógico](https://www.filipeflop.com/produto/modulo-joystick-arduino/)  
- [Fios Jumper](https://m.media-amazon.com/images/I/615DxcdICQL.jpg)  
- [Protoboard](https://cdn.awsli.com.br/300x300/468/468162/produto/19414386ea97456c0c.jpg) (opcional)  

---

## 🔌 Conexões no Arduino e no motor (veja a foto para ajudar a entender)

### 🟢 Motor Servo
Fios
- 🟤 Marrom/Preto → GND  
- 🔴 Vermelho → 5V  
- 🟡 Amarelo → D12 (porta Digital)

### 🎮 Joystick
- VRx → A1 (Eixo X ou esquerda/direita)  
- VRy → A2 (Eixo Y (cima\baixo), opcional, não vai usar)  
- SW → D6 (Botão)  
- VCC → 5V  
- GND → GND  

---


> 💡 O joystick envia valores analógicos que são convertidos pelo Arduino em movimento do servo.

---

## ⚡ Código completo do projeto

```cpp
#include <Servo.h>

Servo meuServo;   // Cria o servo
int eixoX;        // Variável para eixo X
int posicao;      // Variável para a posição do servo

void setup() {
  meuServo.attach(12);          // Conecta o servo ao D12 do arduino
  pinMode(6, INPUT_PULLUP);     // Configura o botão do joystick (ele só serva pra resetar)
}

void loop() {
  eixoX = analogRead(A1);                       // Lê valor do eixo X (0 a 1023)
  posicao = map(eixoX, 0, 1023, 0, 180);       // Converte para ângulo do servo
  meuServo.write(posicao);                      // Move o servo
  delay(15);                                    // Pequeno atraso para estabilidade
}



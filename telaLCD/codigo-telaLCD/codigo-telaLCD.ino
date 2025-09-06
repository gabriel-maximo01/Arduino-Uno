#include <LiquidCrystal.h>

// LCD: RS=12, E=11, D4=5, D5=4, D6=3, D7=2  (portas do arduino)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);     // inicia a tela-LCD
  Serial.begin(9600);   // inicia uma comunicação serial
  lcd.print("Digite no PC");
}

void loop() {
  if (Serial.available()) {        // vê se tem algo digitado
    String texto = Serial.readString();  // lê o que a gente  escreve
    lcd.clear();                   // limpa tela
    lcd.print(texto);              // mostra na telinha o meu texto
  }
}

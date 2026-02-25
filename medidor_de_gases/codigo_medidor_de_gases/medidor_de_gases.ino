const int pinoCO = A0;
const int pinoNH3 = A1;
const int pinoNO2 = A2;

const int amostras = 10;

int lerMedia(int pino){
  long soma = 0;
  for(int i = 0; i < amostras; i++){
    soma += analogRead(pino);
    delay(10);
  }
  return soma / amostras;
}

void setup(){
  Serial.begin(9600);
  Serial.print("Iniciando sensor:");
  delay(5000);
}

void loop() {
  int valorCO = lerMedia(pinoCO);
  int valorNH3 = lerMedia(pinoNH3);
  int valorNO2 = lerMedia(pinoNO2);

  Serial.print("CO:");
  Serial.print(valorCO);

  Serial.print("|NH3:");
  Serial.print(valorNH3);

  Serial.print("|NO2:");
  Serial.println(valorNO2);

  delay(1000);
}
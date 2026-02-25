# Projeto Arduino: Medidor de Gases (CO, NH3 e NO2)

## 📖 Sobre o projeto

Este projeto mostra como usar um **sensor multigás (CO, NH3 e NO2)** com o **Arduino Uno**, exibindo os valores lidos no **Monitor Serial** da Arduino IDE.  

O objetivo é mostrar de forma clara como:  

- Entender e conectar os pinos do sensor  
- Fazer leituras analógicas com o Arduino  
- Trabalhar com média de amostras estabilidade  
- Visualizar dados em tempo real pelo Monitor Serial  

> ⚠️ Esse projeto mostra **valores brutos do ADC (0 a 1023)**, não são ppm, então se for para testes reais você pode testa-lo antes em um ambiente coom ppm conhecido e fazer a média de valores.

---

## 🖥️ O que vai precisar

- Arduino Uno  
- Sensor multigás (modelo com saídas separadas CO, NH3 e NO2)  
- Fios Jumper  
- Cabo USB para conectar o Arduino ao computador  

---

## 🔌 Conexões no o Arduino Uno

| Sensor | Conecta no Arduino |
|---------|-------------------|
| GND     | GND               |
| 5V      | 5V                |
| CO      | A0                |
| NH3     | A1                |
| NO2     | A2                |

---

## 💻 Usando o Monitor Serial

Como o sensor não possui tela, utilizamos o **Monitor Serial da Arduino IDE** para visualizar os dados.

### Como abre o Monitor Serial?

1. Conecte o Arduino ao computador
2. Abra a Arduino IDE  
3. Clique no ícone de lupa 🔍  
4. Defina a velocidade (baud rate) como **9600** (caso não esteja. você pode só verificar o canto direito da tela) 
5. Aguarde alguns segundos para o sensor estabilizar  

Os valores aparecerão atualizados automaticamente a cada segundo.

---

## 📊 Como funciona a leitura

O Arduino utiliza a função:
```
analogRead()
```

Ela converte a tensão recebida (0V a 5V) em um valor entre:
```
0 até 1023
```

Valores baixos indicam baixa concentração de gás.  
Valores mais altos indicam maior presença do gás.

Para melhorar a estabilidade da leitura, o código utiliza média de **10 amostras** antes de exibir o valor final (pode ser mudado no código).

---

## ⚡ Código completo do projeto

```cpp
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
  Serial.print("Iniciando sensor...");
  delay(5000);
}

void loop() {
  int valorCO = lerMedia(pinoCO);
  int valorNH3 = lerMedia(pinoNH3);
  int valorNO2 = lerMedia(pinoNO2);

  Serial.print("CO:");
  Serial.print(valorCO);

  Serial.print(" | NH3:");
  Serial.print(valorNH3);

  Serial.print(" | NO2:");
  Serial.println(valorNO2);

  delay(1000);
}
```

---

## 📌 Observação importante

Sensores de gás precisam de tempo de aquecimento para fazer leituras mais estáveis.  
É bom aguardar alguns minutos depois de ligar o sistema antes de considerar os valores.

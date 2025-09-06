# Projeto Arduino: LCD 16x2 com Monitor Serial

## 📖 Sobre o projeto

Este projeto mostra como usar um **display LCD 16x2** com o **Arduino Uno**, digitando direto do computador fazer com que ele apareça diretamente na tela LCD.  

O objetivo é ensinar, de forma prática e clara como:  

- Entender e conectar os pinos do LCD 16x2  
- Configurar o Arduino para mostrar mensagens  
- Usar o **Monitor Serial** como teclado virtual  
- Fazer o projeto rodar sem precisar de teclado físico  

---

## 🖥️ O que você vai precisar

- Arduino Uno  
- [Display LCD 16x2](https://www.usinainfo.com.br/1019423-thickbox_default/display-lcd-16x2-com-fundo-azul.jpg) (HD44780 compatível)  
- [Fios Jumper](https://m.media-amazon.com/images/I/615DxcdICQL.jpg) (mais ou menos 14 a 20) 
- [Cabo USB](https://images.tcdn.com.br/img/img_prod/650361/cabo_usb_tipo_a_b_compativel_com_arduino_uno_mega_777_1_01acf1be159e877ae9414e694908e1ad.png) para conectar o Arduino ao computador  
- [Potenciômetro](https://www.huinfinito.com.br/439-large_default/potenciometro-linear-100k-cursor-metal.jpg) de 10k (opcional, para ajuste de contraste)  

> **Obs.:** O projeto também funciona sem o potenciômetro, ligando o pino de contraste (V0) diretamente no GND.  

---

## 🔌 Entendendo o LCD 16x2

O LCD 16x2 possui **16 pinos**, com funções específicas:

| Pino | Nome  | Função |
|------|-------|--------|
| 1    | VSS   | Terra (GND) |
| 2    | VDD   | +5V |
| 3    | V0    | Ajuste de contraste (ligar em GND se não usar potenciômetro) |
| 4    | RS    | Seleção comando/dados |
| 5    | RW    | Escolha escrita/leitura (geralmente GND) |
| 6    | E     | Habilita escrita no LCD |
| 7-10 | D0-D3 | Dados (não usados no modo 4 bits) |
| 11-14| D4-D7 | Dados (usados no modo 4 bits) |
| 15   | A     | Ânodo do LED de backlight (+5V com resistor de 220Ω se necessário) |
| 16   | K     | Cátodo do LED de backlight (GND) |

---

## 🧩 Conexões com o Arduino Uno (modo 4 bits)

| LCD | Conecta em Arduino | Observação |
|-----|------------------|------------|
| VSS | GND              | Terra |
| VDD | 5V               | Alimentação |
| V0  | GND              | Contraste (ou usar potenciômetro 10k) |
| RS  | 12               | Porta 12 |
| RW  | GND              | Só escrita |
| E   | 11               | Porta 11 |
| D4  | 5                | Porta 5 |
| D5  | 4                | Porta 4 |
| D6  | 3                | Porta 3 |
| D7  | 2                | Porta 2 |
| A   | 5V (+resistor 220Ω se necessário) | Backlight positivo |
| K   | GND              | Backlight negativo |

> **Dica:** Se seu módulo LCD já tiver resistor para o backlight, pode ligar A direto no 5V.

---

## 💻 Usando o Monitor Serial como “teclado virtual”

Como o LCD não tem botões, vamos usar o **Monitor Serial da Arduino IDE** para digitar o texto que vai aparecer na telinha.

### Abrindo o Monitor Serial
1. Conecte o Arduino no computador via USB  
2. Abra a **Arduino IDE**  
3. Clique em **Ferramentas > Monitor Serial** ou no ícone de lupa 🔍  
4. Defina a velocidade (**baud rate**) como **9600** (igual ao código)  
5. Digite qualquer texto na caixa e clique em **Enviar**  

O Arduino vai receber esse texto e mostrar no LCD (a tela).

> **Dica:** Se for a última versão é só clicar na lupa no canto superior direito depois de escrever o código e digitar na caixa de texto que aparece embaixo.

---

## ⚡ Código completo do projeto

```cpp
#include <LiquidCrystal.h>

// Inicializa o LCD: RS=12, E=11, D4=5, D5=4, D6=3, D7=2 (tem que trocar se vc colocar em outras)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);     // configura o LCD/telinha (16 colunas, 2 linhas)
  Serial.begin(9600);   // inicia comunicação Serial
  lcd.print("Digite no PC"); // essa é a primeira mensagem que vai aparecer
  lcd.setCursor(0,1);        // Coloca o cursor na segunda linha (é um risquinho preto que vai aparecer depois da palavra)
}

void loop() {
  if (Serial.available()) {         // vê se tem algo digitado no Monitor Serial
    String texto = Serial.readString(); // lê o texto
    lcd.clear();                    // limpa a tela
    lcd.print(texto);               // mostra na telinha
  }
}

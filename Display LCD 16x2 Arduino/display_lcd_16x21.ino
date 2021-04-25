
// Projeto: Display LCD 16x2 com a mensagem Enxurrada de Bits
// Autor: Ronaldo Mendonça Zica

// Link no tinkercad: https://www.tinkercad.com/things/6YtrPDr6Gz8

// Biblioteca que irá facilitar o uso do display
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
String frase = "CEFET";

void setup()
{
  // Define o número de colunas e linhas do LCD - 16 e 2 respectivamente
  lcd.begin(16, 2);
}
 
void loop()
{
  // Limpa o display
  lcd.clear();
  // Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  // Envia a string para o LCD
  lcd.print("ENXURRADA DE ");
  lcd.setCursor(6, 1);
  lcd.print("BITS");
  delay(500);
   
  // Deslocamento para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }
   
  // Deslocamento para a direita
  for (int posicao = 0; posicao < 4; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }
}

// Referência bibliográfica:

// ADILSON THOMSEN. Controlando um LCD 16x2 com Arduino - FilipeFlop. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/>. Acesso em: 25 Apr. 2021.


// Projeto: Display LCD e teclado matricial
// Autor: Ronaldo Mendonça Zica

// Link do projeto no tinkercad: https://www.tinkercad.com/things/3M3NDCWFX2g

//-------------------------------------------------------------------------------------
// Defines:
//-------------------------------------------------------------------------------------

#define saida1tec 4
#define saida2tec 5
#define saida3tec 6
#define saida4tec 7

#define entrada1tec 10
#define entrada2tec 11
#define entrada3tec 12
#define entrada4tec 13

#define offsetTeclas 3

#define quantidadePixels 19
#define pinoPixels A0

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Includes:
//-------------------------------------------------------------------------------------

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// Variáveis globais:
//-------------------------------------------------------------------------------------

LiquidCrystal lcd(9, 8, 3, 2, 1, 0);			// Cria o display 16x2 e define seus pinos
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(quantidadePixels, A0, NEO_GRB + NEO_KHZ800);

//-------------------------------------------------------------------------------------
// Criando o tipo de variável "tecla":

typedef enum
{
   um, dois, tres, quatro, cinco, seis, sete, oito, nove, zero, A, B, C, D, asterisco, hashtag
} tecla;

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Função acendePixels:
// 		Parâmetros: x - linha, y - coluna
//		Tipo da função: Tecla
//		Retorno: TeclaAux
//		Objetivo: Recebe qual linha e qual coluna foram pressionadas e atribui a uma variável do tipo tecla.
//-------------------------------------------------------------------------------------

void acendePixels(int red, int green, int blue)
{
  for(int cont = 0; cont < quantidadePixels; cont ++)
  {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(cont, pixels.Color(red, green, blue));

      pixels.show();

      delay(50);
    }
}

//-------------------------------------------------------------------------------------
// Função defineTecla:
// 		Parâmetros: x - linha, y - coluna
//		Tipo da função: Tecla
//		Retorno: TeclaAux
//		Objetivo: Recebe qual linha e qual coluna foram pressionadas e atribui a uma variável do tipo tecla.
//-------------------------------------------------------------------------------------

tecla defineTecla(int x, int y);				// Cabeçalho

tecla defineTecla(int x, int y)
{
  tecla TeclaAux;
  
  if(x == 1)
  {
    if(y == 1)
    	TeclaAux = um;
    else if(y == 2)
    	TeclaAux = dois;
    else if(y == 3)
    	TeclaAux = tres;
    else if(y == 4)
    	TeclaAux = A;
  }
  
  else if(x == 2)
  {
    if(y == 1)
    	TeclaAux = quatro;
    else if(y == 2)
    	TeclaAux = cinco;
    else if(y == 3)
    	TeclaAux = seis;
    else if(y == 4)
    	TeclaAux = B;
  }
  
  else if(x == 3)
  {
    if(y == 1)
    	TeclaAux = sete;
    else if(y == 2)
    	TeclaAux = oito;
    else if(y == 3)
    	TeclaAux = nove;
    else if(y == 4)
    	TeclaAux = C;
  }
  
  else if(x == 4)
  {
    if(y == 1)
    	TeclaAux = asterisco;
    else if(y == 2)
    	TeclaAux = zero;
    else if(y == 3)
    	TeclaAux = hashtag;
    else if(y == 4)
    	TeclaAux = D;
  }
  
  return TeclaAux;
}

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Função imprime_linha_coluna:
// 		Parâmetros: x - linha, y - coluna
//		Tipo da função: Void
//		Retorno: Nenhum
//		Objetivo: Recebe qual linha e qual coluna foram pressionadas e imprime no monitor serial a tecla.
//-------------------------------------------------------------------------------------

void imprime_linha_coluna(int x, int y)
{
       lcd.clear();										//Limpa a tela
  	   lcd.setCursor(0, 0);								//Posiciona o cursor na coluna 0, linha 0;
  	   lcd.print("Tecla:");
       lcd.setCursor(15, 0);							//Posiciona o cursor na coluna 15, linha 1;
  
  	   tecla Tecla = defineTecla(x, y);
  
  	   switch(Tecla)
       {
         case zero:
         	lcd.print("0");
         	acendePixels(0,0,0);
         	break;
         case um:
         	lcd.print("1");
         	acendePixels(255,0,0);
         	break;
         case dois:
         	lcd.print("2");
         	acendePixels(0,255,0);
         	break;
         case tres:
         	lcd.print("3");
         	acendePixels(0,0,255);
         	break;
         case quatro:
         	lcd.print("4");
         	acendePixels(255,255,0);
         	break;
         case cinco:
         	lcd.print("5");
         	acendePixels(0,255,255);
         	break;
         case seis:
         	lcd.print("6");
         	acendePixels(255,0,255);
         	break;
         case sete:
         	lcd.print("7");
         	acendePixels(128,128,128);
         	break;
         case oito:
         	lcd.print("8");
         	acendePixels(0,128,255);
         	break;
         case nove:
         	lcd.print("9");
         	acendePixels(200,200,200);
         	break;
         case asterisco:
         	lcd.print("*");
         	break;
         case hashtag:
         	lcd.print("#");
         	break;
         case A:
         	lcd.print("A");
         	break;
         case B:
         	lcd.print("B");
         	break;
         case C:
         	lcd.print("C");
         	break;
         case D:
         	lcd.print("D");
         	break;
       }
       
       delay(10);
}

//-------------------------------------------------------------------------------------
// Função setup:
// 		Parâmetros: Nenhum
//		Tipo da função: Void
//		Retorno: Nenhum
//		Objetivo: Configura os pinos do arduino e a comunicação serial.
//-------------------------------------------------------------------------------------

void setup()
{
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(saida1tec, OUTPUT);
  pinMode(saida2tec, OUTPUT);
  pinMode(saida3tec, OUTPUT);
  pinMode(saida4tec, OUTPUT);
   
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(entrada1tec, INPUT);
  pinMode(entrada2tec, INPUT);
  pinMode(entrada3tec, INPUT);
  pinMode(entrada4tec, INPUT);
  
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print(" ENXURRADA DE ");
  lcd.setCursor(1, 1);
  lcd.print("     BITS    ");
  
  pixels.begin();
  acendePixels(0,0,0);
}

//-------------------------------------------------------------------------------------
 
//-------------------------------------------------------------------------------------
// Função loop:
// 		Parâmetros: Nenhum
//		Tipo da função: Void
//		Retorno: Nenhum
//		Objetivo: Executa infinitamente essa função para continuar verificando se algum botão foi pressionado.
//-------------------------------------------------------------------------------------

void loop()
{
  	int contador;
  
    for (int contador = saida1tec; contador <= saida4tec; contador ++)
    {
      //Alterna o estado dos pinos das linhas
      digitalWrite(saida1tec, LOW);
      digitalWrite(saida2tec, LOW);
      digitalWrite(saida3tec, LOW);
      digitalWrite(saida4tec, LOW);
      digitalWrite(contador, HIGH);

      //Verifica se alguma tecla da coluna 1 foi pressionada
      if (digitalRead(entrada1tec) == HIGH)
      {
        imprime_linha_coluna(contador - offsetTeclas, 1);
        while(digitalRead(entrada1tec) == HIGH){}
      }

      //Verifica se alguma tecla da coluna 2 foi pressionada    
      if (digitalRead(entrada2tec) == HIGH)
      {
        imprime_linha_coluna(contador - offsetTeclas, 2);
        while(digitalRead(entrada2tec) == HIGH){}
      }

      //Verifica se alguma tecla da coluna 3 foi pressionada
      if (digitalRead(entrada3tec) == HIGH)
      {
        imprime_linha_coluna(contador - offsetTeclas, 3);
        while(digitalRead(entrada3tec) == HIGH){}
      }

      //Verifica se alguma tecla da coluna 4 foi pressionada
      if (digitalRead(entrada4tec) == HIGH)
      {
        imprime_linha_coluna(contador - offsetTeclas, 4);
        while(digitalRead(entrada4tec) == HIGH){} 
      }
   	}
  
   delay(5);
}

//-------------------------------------------------------------------------------------
/*
	Referências bibliográficas:
	
    Adafruit NeoPixel Library: Arduino Library for driving Adafruit NeoPixel addressable LEDs,. Github.io. Disponível em: <https://adafruit.github.io/Adafruit_NeoPixel/html/index.html>. Acesso em: 25 Apr. 2021.

	BURGESS, Phillip. Adafruit NeoPixel Überguide. Adafruit Learning System. Disponível em: <https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use>. Acesso em: 25 Apr. 2021.

	ADILSON THOMSEN. Controlando um LCD 16x2 com Arduino - FilipeFlop. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/>. Acesso em: 25 Apr. 2021.

	ADILSON THOMSEN. Como usar o Teclado Matricial 4×4 com Arduino. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/>. Acesso em: 25 Apr. 2021.

*/
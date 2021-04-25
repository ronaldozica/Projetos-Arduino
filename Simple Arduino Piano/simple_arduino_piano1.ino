
// Projeto: Display LCD e teclado matricial
// Autor: Ronaldo Mendonça Zica

// Link do projeto no tinkercad: https://www.tinkercad.com/things/9DZjq5wer6z

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

#define pinoBuzzer A0


// IMPORTANTE: BIBLIOTECA PITCHES.H:
// Essa biblioteca não foi desenvolvida por mim, como não consegui importar para o tinkercad, inseri o código da biblioteca:
// Esse código foi desenvolvido pelo Mike Putnam e pode ser acessado em seu github - https://gist.github.com/mikeputnam
// Início do código:
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
// Fim da biblioteca pitches.h

#define REST 0				
// Rest - Sem som

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Includes:
//-------------------------------------------------------------------------------------

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// Variáveis globais:
//-------------------------------------------------------------------------------------

LiquidCrystal lcd(9, 8, 3, 2, 1, 0);			// Cria o display 16x2 e define seus pinos
//-------------------------------------------------------------------------------------
// Criando o tipo de variável "tecla":

typedef enum
{
   um, dois, tres, quatro, cinco, seis, sete, oito, nove, zero, A, B, C, D, asterisco, hashtag
} tecla;

//-------------------------------------------------------------------------------------

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
  	   lcd.print("Ultima nota:");    
  	   lcd.setCursor(6, 1);								//Posiciona o cursor na coluna 1, linha 0;
  	
  	   tecla Tecla = defineTecla(x, y);
  
  	   switch(Tecla)
       {
         case zero:
         	lcd.print("A#4");
         	tone(pinoBuzzer, NOTE_AS4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case um:
         	lcd.print("C4");
       		tone(pinoBuzzer, NOTE_C4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case dois:
         	lcd.print("D4");
       		tone(pinoBuzzer, NOTE_D4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case tres:
         	lcd.print("E4");
       		tone(pinoBuzzer, NOTE_E4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case quatro:
         	lcd.print("F4");
       		tone(pinoBuzzer, NOTE_F4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case cinco:
         	lcd.print("G4");
         	tone(pinoBuzzer, NOTE_G4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case seis:
         	lcd.print("A4");
         	tone(pinoBuzzer, NOTE_A4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case sete:
         	lcd.print("B4");
         	tone(pinoBuzzer, NOTE_B4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case oito:
         	lcd.print("C#4");
         	tone(pinoBuzzer, NOTE_CS4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case nove:
         	lcd.print("D#4");
         	tone(pinoBuzzer, NOTE_DS4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case asterisco:
         	lcd.print("F#4");
         	tone(pinoBuzzer, NOTE_FS4);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case hashtag:
         	lcd.print("C5");
			tone(pinoBuzzer, NOTE_C5);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case A:
         	lcd.print("D5");
         	tone(pinoBuzzer, NOTE_D5);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case B:
         	lcd.print("F5");
         	tone(pinoBuzzer, NOTE_F5);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case C:
         	lcd.print("G5");
         	tone(pinoBuzzer, NOTE_G5);
            delay(200);
            noTone(pinoBuzzer);
         	break;
         case D:
         	lcd.print("A5");
         	tone(pinoBuzzer, NOTE_A5);
            delay(200);
            noTone(pinoBuzzer);
         	break;
       }
       
       delay(5);
  
  	   //lcd.clear();										//Limpa a tela
  	   //lcd.setCursor(0, 0);								//Posiciona o cursor na coluna 0, linha 0;
  	   //lcd.print("Esperando tecla");
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
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("PIANO ENXURRADA");
  lcd.setCursor(4, 1);
  lcd.print("DE BITS");
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
    
    Biblioteca "pitches.h":
    262588213843476. pitches.h. Gist. Disponível em: <https://gist.github.com/mikeputnam/2820675>. Acesso em: 24 Apr. 2021.
    
    Arduino Tutorial : Mini Piano. Arduino Project Hub. Disponível em: <https://create.arduino.cc/projecthub/rahulkhanna/arduino-tutorial-mini-piano-08f8b8>. Acesso em: 25 Apr. 2021.
    
    ADILSON THOMSEN. Controlando um LCD 16x2 com Arduino - FilipeFlop. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/>. Acesso em: 25 Apr. 2021.

	ADILSON THOMSEN. Como usar o Teclado Matricial 4×4 com Arduino. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/>. Acesso em: 25 Apr. 2021.

*/
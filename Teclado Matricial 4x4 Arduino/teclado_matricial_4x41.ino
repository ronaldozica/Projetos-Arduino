
// Projeto: Display LCD 16x2 com a mensagem Enxurrada de Bits
// Autor: Ronaldo Mendonça Zica

// Link no Tinkercad: https://www.tinkercad.com/things/juKT456x5T5
 
#define TECLADO1OUT 3
#define TECLADO2OUT 4
#define TECLADO3OUT 5
#define TECLADO4OUT 6

#define TECLADO1IN 8
#define TECLADO2IN 9
#define TECLADO3IN 10
#define TECLADO4IN 11

void setup()
{
  //Pinos ligados aos pinos 3, 4, 5 e 6 do teclado - Linhas
  pinMode(TECLADO1OUT, OUTPUT);
  pinMode(TECLADO2OUT, OUTPUT);
  pinMode(TECLADO3OUT, OUTPUT);
  pinMode(TECLADO4OUT, OUTPUT);
   
  //Pinos ligados aos pinos 8, 9, 10 e 11 do teclado - Colunas
  pinMode(TECLADO1IN, INPUT);
  pinMode(TECLADO2IN, INPUT);
  pinMode(TECLADO3IN, INPUT);
  pinMode(TECLADO4IN, INPUT);
   
  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}
 
void loop()
{
    for (int ti = 3; ti<7; ti ++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(TECLADO1OUT, LOW);
    digitalWrite(TECLADO2OUT, LOW);
    digitalWrite(TECLADO3OUT, LOW);
    digitalWrite(TECLADO4OUT, LOW);
    digitalWrite(ti, HIGH);
    
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(TECLADO1IN) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(TECLADO1IN) == HIGH){}
    }
 
    //Verifica se alguma tecla da coluna 2 foi pressionada    
    if (digitalRead(TECLADO2IN) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(TECLADO2IN) == HIGH){};
    }
     
    //Verifica se alguma tecla da coluna 3 foi pressionada
    if (digitalRead(TECLADO3IN) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(TECLADO3IN) == HIGH){}
    }
     
    //Verifica se alguma tecla da coluna 4 foi pressionada
    if (digitalRead(TECLADO4IN) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(TECLADO4IN) == HIGH){} 
    }
   }
   delay(10);
}

void imprime_linha_coluna(int x, int y)
{
       Serial.print("Linha : ");
       Serial.print(x);
       Serial.print(" x Coluna : ");
       Serial.print(y);
       delay(10);
       Serial.println();
}

// Referência bibliográfica:

//	ADILSON THOMSEN. Como usar o Teclado Matricial 4×4 com Arduino. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/>. Acesso em: 25 Apr. 2021.

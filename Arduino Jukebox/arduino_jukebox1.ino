
// Projeto: Display LCD e teclado matricial
// Autor: Ronaldo Mendonça Zica

// Link do projeto no tinkercad: https://www.tinkercad.com/things/8aCkwdKNUvV

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

#define quantidadeNotas 12
#define quantidadeNotasComeAsYouAre 14
#define quantidadeNotasSmokeOnTheWater 12

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

const int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

/*
const int notesComeAsYouAre[] = { NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_DS4,
                                  NOTE_D4, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_A4, NOTE_D4, NOTE_DS4
                                };
*/

/*
const int notesSmokeOnTheWater[] = { NOTE_D3, NOTE_F3, NOTE_GS3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_GS3,
                                  	 NOTE_D3, NOTE_F3, NOTE_GS3, NOTE_F2, NOTE_D2
								   };
*/
const int notesHappyBirthday[] = { NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4,NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, 
                                  NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4,
                                  NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
                                  NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
								 };
//************************************************************************************
// Trecho de código do "GeneralSpud" - Link nas referências bibliográficas:
const int melodyTakeOnMe[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

const int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};

const int songLength = sizeof(melodyTakeOnMe)/sizeof(melodyTakeOnMe[0]);
//Fim do trecho de código do "GeneralSpud"
//************************************************************************************

//************************************************************************************
// Trecho de código do "Robson Couto" - Link nas referências bibliográficas:
	const int tempoHarryPotter = 144;

	const int melodyHarryPotter[] = {


    // Hedwig's theme fromn the Harry Potter Movies
    // Socre from https://musescore.com/user/3811306/scores/4906610

    REST, 2, NOTE_D4, 4,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_C5, -2, 
    NOTE_A4, -2,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4,
    NOTE_D4, -1, 
    NOTE_D4, 4,

    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_B4, 4,
    NOTE_G4, -1,
    NOTE_AS4, 4,

    NOTE_D5, 2, NOTE_AS4, 4,//18
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_DS5, 2, NOTE_D5, 4,
    NOTE_CS5, 2, NOTE_A4, 4,
    NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_D4, 4,
    NOTE_D5, -1, 
    REST,4, NOTE_AS4,4,  

    NOTE_D5, 2, NOTE_AS4, 4,//26
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_AS4, 4,
    NOTE_G4, -1, 

  	};

	int notesHarryPotter = sizeof(melodyHarryPotter) / sizeof(melodyHarryPotter[0]) / 2;

    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenoteHarryPotter = (60000 * 4) / tempoHarryPotter;

    int divider = 0, noteDuration = 0;

	//************************************************************************************
	// Zelda start
	///*
	const int tempoZelda = 88;	

	const int melodyZelda[] = {

    //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=169

    NOTE_AS4,-2,  NOTE_F4,8,  NOTE_F4,8,  NOTE_AS4,8,//1
    NOTE_GS4,16,  NOTE_FS4,16,  NOTE_GS4,-2,
    NOTE_AS4,-2,  NOTE_FS4,8,  NOTE_FS4,8,  NOTE_AS4,8,
    NOTE_A4,16,  NOTE_G4,16,  NOTE_A4,-2,
    REST,1, 

    NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//7
    NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
    NOTE_AS5,-2,  NOTE_AS5,8,  NOTE_AS5,8,  NOTE_GS5,8,  NOTE_FS5,16,
    NOTE_GS5,-8,  NOTE_FS5,16,  NOTE_F5,2,  NOTE_F5,4, 

    NOTE_DS5,-8, NOTE_F5,16, NOTE_FS5,2, NOTE_F5,8, NOTE_DS5,8, //11
    NOTE_CS5,-8, NOTE_DS5,16, NOTE_F5,2, NOTE_DS5,8, NOTE_CS5,8,
    NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8, 
    NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8,

    NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//15
    NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
    NOTE_AS5,-2, NOTE_CS6,4,
    NOTE_C6,4, NOTE_A5,2, NOTE_F5,4,
    NOTE_FS5,-2, NOTE_AS5,4,
    NOTE_A5,4, NOTE_F5,2, NOTE_F5,4,

    NOTE_FS5,-2, NOTE_AS5,4,
    NOTE_A5,4, NOTE_F5,2, NOTE_D5,4,
    NOTE_DS5,-2, NOTE_FS5,4,
    NOTE_F5,4, NOTE_CS5,2, NOTE_AS4,4,
    NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8, 
    NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8

  	};

	int notesZelda = sizeof(melodyZelda)/sizeof(melodyZelda[0])/2; 

  	// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
  	int wholenoteZelda = (60000 * 4) / tempoZelda;
	//*/
	//************************************************************************************
	// Cantina start

	const int tempoCantina = 140;

	int melodyCantina[] = {
  
    // Cantina Band - Star wars 
    // Score available at https://musescore.com/user/6795541/scores/1606876
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8, 
    NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
    NOTE_G4,4,  NOTE_E4,-2, 
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

    NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
    NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
    NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
    NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
    NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
    NOTE_G4,-4, NOTE_E4,-2,
    NOTE_E4, 2, NOTE_G4,2,
    NOTE_B4, 2, NOTE_D5,2,

    NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4, 
  	};

	int notesCantina = sizeof(melodyCantina) / sizeof(melodyCantina[0]) / 2;

    // this calculates the duration of a whole note in ms
    int wholenoteCantina = (60000 * 2) / tempoCantina;

	//************************************************************************************
	// Imperial March start

	int tempoVader = 120;

	int melodyVader[] = {
  
    // Dart Vader theme (Imperial March) - Star wars 
    // Score available at https://musescore.com/user/202909/scores/1141521
    // The tenor saxophone part was used

    NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
    NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
    NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
    NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,

    NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
    NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

    NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
    NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

    NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
    NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

    NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
      
  	};

	int notesVader = sizeof(melodyVader) / sizeof(melodyVader[0]) / 2;

    // this calculates the duration of a whole note in ms
    int wholenoteVader = (60000 * 4) / tempoVader;

	//************************************************************************************
	// Pacman start

	int tempoPacman = 105;

	int melodyPacman[] = {

    // Pacman
    // Score available at https://musescore.com/user/85429/scores/107109
    NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
    NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
    NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

    NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
    NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
    NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
  	};

	int notesPacman = sizeof(melodyPacman) / sizeof(melodyPacman[0]) / 2;

    // this calculates the duration of a whole note in ms
    int wholenotePacman = (60000 * 4) / tempoPacman;

	//************************************************************************************

// Fim do trecho de código do Robson
//************************************************************************************

//-------------------------------------------------------------------------------------
// Criando o tipo de variável "tecla":

typedef enum
{
   um, dois, tres, quatro, cinco, seis, sete, oito, nove, zero, A, B, C, D, asterisco, hashtag
} tecla;

//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Função tocaBuzzer:
// 		Parâmetros: teclaPressionada
//		Tipo da função: void
//		Retorno: -
//		Objetivo: Recebe qual tecla foi pressionada e toca a música dessa tecla
//-------------------------------------------------------------------------------------

void tocaBuzzer(tecla teclaPressionada);		// Cabeçalho

void tocaBuzzer(tecla teclaPressionada)
{
  int contadorFrequencias;
  switch(teclaPressionada)
   {
     case zero:
        for(contadorFrequencias = 0; contadorFrequencias < quantidadeNotas; contadorFrequencias ++)
        {
            tone(pinoBuzzer, tones[contadorFrequencias]);
            delay(500);
        }
        noTone(pinoBuzzer);
        break;
    
     case um:
    	// Decidi adicionar 2 repetições para a música Take on Me
    	for(int repeticoesTakeOnMe = 0; repeticoesTakeOnMe < 2; repeticoesTakeOnMe ++)
        {
          //************************************************************************************
          // Trecho de código do "GeneralSpud" - Link nas referências bibliográficas:
          // Obs: foram feitas pequenas modificações para adaptar ao contexto do código.
          for (int thisNote = 0; thisNote < songLength; thisNote++)
          {
            int duration = 1000/ durations[thisNote];
            tone(pinoBuzzer, melodyTakeOnMe[thisNote], duration);
            int pause = duration * 1.3;
            delay(pause);
            noTone(8);
          }
          //Fim do trecho de código do "GeneralSpud"
          //************************************************************************************
        }
        break;
    
     case dois:
    	//************************************************************************************
    	// Trecho de código do "Robson Couto" - Disponível em https://github.com/robsoncouto/arduino-songs/blob/master/harrypotter/harrypotter.ino
        for (int thisNote = 0; thisNote < notesHarryPotter * 2; thisNote = thisNote + 2) {
          // calculates the duration of each note
          divider = melodyHarryPotter[thisNote + 1];
          if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenoteHarryPotter) / divider;
          } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenoteHarryPotter) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
          }

          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(pinoBuzzer, melodyHarryPotter[thisNote], noteDuration*0.9);

          // Wait for the specief duration before playing the next note.
          delay(noteDuration);

          // stop the waveform generation before the next note.
          noTone(pinoBuzzer);
        }
    	// Fim do trecho de código do Robson
    	//************************************************************************************
        break;
    
     case tres:
    	  ///*
    	  //************************************************************************************
    	  // Trecho de código do "Robson Couto" - Disponível em https://github.com/robsoncouto/arduino-songs/blob/master/zeldatheme/zeldatheme.ino
          for (int thisNote = 0; thisNote < notesZelda * 2; thisNote = thisNote + 2) {

          // calculates the duration of each note
          divider = melodyZelda[thisNote + 1];
          if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenoteZelda) / divider;
          } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenoteZelda) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
          }

          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(pinoBuzzer, melodyZelda[thisNote], noteDuration*0.9);

          // Wait for the specief duration before playing the next note.
          delay(noteDuration);

          // stop the waveform generation before the next note.
          noTone(pinoBuzzer);
        }
    	// Fim do trecho de código do Robson
    	//************************************************************************************
        //*/
        break;
    
     case quatro:
    	//************************************************************************************
    	// Trecho de código do "Robson Couto" - Disponível em https://github.com/robsoncouto/arduino-songs/blob/master/cantinaband/cantinaband.ino
        for (int thisNote = 0; thisNote < notesCantina * 2; thisNote = thisNote + 2) {
          // calculates the duration of each note
          divider = melodyCantina[thisNote + 1];
          if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenoteCantina) / divider;
          } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenoteCantina) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
          }

          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(pinoBuzzer, melodyCantina[thisNote], noteDuration*0.9);

          // Wait for the specief duration before playing the next note.
          delay(noteDuration);

          // stop the waveform generation before the next note.
          noTone(pinoBuzzer);
        }
    	// Fim do trecho de código do Robson
    	//************************************************************************************
        break;
    
     case cinco:
    	//************************************************************************************
    	// Trecho de código do "Robson Couto" - Disponível em https://github.com/robsoncouto/arduino-songs/blob/master/imperialmarch/imperialmarch.ino
        for (int thisNote = 0; thisNote < notesVader * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = melodyVader[thisNote + 1];
        if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenoteVader) / divider;
        } else if (divider < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (wholenoteVader) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(pinoBuzzer, melodyVader[thisNote], noteDuration*0.9);

        // Wait for the specief duration before playing the next note.
        delay(noteDuration);

        // stop the waveform generation before the next note.
        noTone(pinoBuzzer);
      }
   		// Fim do trecho de código do Robson
    	//************************************************************************************
        break;
    
     case seis:
        for (int thisNote = 0; thisNote < notesPacman * 2; thisNote = thisNote + 2) {
          // calculates the duration of each note
          divider = melodyPacman[thisNote + 1];
          if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenotePacman) / divider;
          } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenotePacman) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
          }

          // we only play the note for 90% of the duration, leaving 10% as a pause
          tone(pinoBuzzer, melodyPacman[thisNote], noteDuration * 0.9);

          // Wait for the specief duration before playing the next note.
          delay(noteDuration);

          // stop the waveform generation before the next note.
          noTone(pinoBuzzer);
  		}
        break;
    
     case sete:
    
    	// Para tocar Come as you are, basta descomentar esse código e a declaração do vetor notesSmokeOnTheWater[]
    	// OBS: Pode causar bugs no sistema, cuidado!
    	
    	/*	
    	for(int contadorRepeticoes = 0; contadorRepeticoes < 3; contadorRepeticoes ++)
        {
          for(contadorFrequencias = 0; contadorFrequencias < quantidadeNotasComeAsYouAre; contadorFrequencias ++)
          {
              tone(pinoBuzzer, notesComeAsYouAre[contadorFrequencias]);
              delay(300);
              noTone(pinoBuzzer);
              delay(75);
          }
          //noTone(pinoBuzzer);
          delay(50);
        }
    
        break;
    	*/
    
     case oito:
    
    	lcd.clear();
    	lcd.setCursor(3,0);
    	lcd.print("Memoria");
    	lcd.setCursor(2,1);
    	lcd.print("Indisponivel");
    	delay(1000);
    
    	// Para tocar Smoke on the water, basta descomentar esse código e a declaração do vetor notesSmokeOnTheWater[]
    	// OBS: Pode causar bugs no sistema, cuidado!
    
    	/*	
    	for(int contadorRepeticoes = 0; contadorRepeticoes < 2; contadorRepeticoes ++)
        {
          for(contadorFrequencias = 0; contadorFrequencias < quantidadeNotasSmokeOnTheWater; contadorFrequencias ++)
          {
              tone(pinoBuzzer, notesSmokeOnTheWater[contadorFrequencias]);
              delay(400);
              noTone(pinoBuzzer);
              delay(200);

              if( (contadorFrequencias == 2) || (contadorFrequencias == 6) )
                delay(300);
          }
          //noTone(pinoBuzzer);
          delay(500);
        }
        delay(500);
        */
    
        break;
    
     case nove:
        for(contadorFrequencias = 0; contadorFrequencias < 25; contadorFrequencias ++)
        {
            tone(pinoBuzzer, notesHappyBirthday[contadorFrequencias]);
            delay(400);
            noTone(pinoBuzzer);
            delay(100);
          	
          	 if( (contadorFrequencias == 5) || (contadorFrequencias == 12) )
                delay(400);
        }
        //noTone(pinoBuzzer);
        break;
    
     default:
    	lcd.clear();
    	lcd.setCursor(3,0);
    	lcd.print("Memoria");
    	lcd.setCursor(2,1);
    	lcd.print("Indisponivel");
    	delay(1000);
    	break;
   }
}

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
  	   lcd.print("Aguarde, tocando");    
  	   lcd.setCursor(0, 1);								//Posiciona o cursor na coluna 1, linha 0;
  	
  	   tecla Tecla = defineTecla(x, y);
  
  	   switch(Tecla)
       {
         case zero:	
       		lcd.print("Escala simples"); 
         	tocaBuzzer(Tecla);
         	break;
         case um:
       		lcd.print("Take On Me"); 
         	tocaBuzzer(Tecla);
         	break;
         case dois:
       		lcd.print("Harry Potter"); 
         	tocaBuzzer(Tecla);
         	break;
         case tres:
       		lcd.print("Zelda Theme"); 
         	tocaBuzzer(Tecla);
         	break;
         case quatro:
       		lcd.print("Cantina Band"); 
         	tocaBuzzer(Tecla);
         	break;
         case cinco:
         	lcd.print("Imperial March");
         	tocaBuzzer(Tecla);
         	break;
         case seis:
         	lcd.print("Pacman Theme");
         	tocaBuzzer(Tecla);
         	break;
         case sete:
         	lcd.print("Come as you are");
         	tocaBuzzer(Tecla);
         	break;
         case oito:
         	lcd.print("Smoke on t water");
         	tocaBuzzer(Tecla);
         	break;
         case nove:
         	lcd.print("Happy Birthday");
         	tocaBuzzer(Tecla);
         	break;
         case asterisco:
         	lcd.print("*");
         	tocaBuzzer(Tecla);
         	break;
         case hashtag:
			lcd.print("#");
         	tocaBuzzer(Tecla);
         	break;
         case A:
         	lcd.print("A");
         	tocaBuzzer(Tecla);
         	break;
         case B:
         	lcd.print("B");
         	tocaBuzzer(Tecla);
         	break;
         case C:
         	lcd.print("C");
         	tocaBuzzer(Tecla);
         	break;
         case D:
         	lcd.print("D");
         	tocaBuzzer(Tecla);
         	break;
       }
       
       delay(10);
  
  	   lcd.clear();										//Limpa a tela
  	   lcd.setCursor(0, 0);								//Posiciona o cursor na coluna 0, linha 0;
  	   lcd.print("Esperando tecla");
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
  lcd.print("JUKEBOX ENXURRA-");
  lcd.setCursor(3, 1);
  lcd.print("DA DE BITS");
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
    
    0 - Scale:
    MONK, Simon. Arduino Lesson 10. Making Sounds. Adafruit Learning System. Disponível em: <https://learn.adafruit.com/adafruit-arduino-lesson-10-making-sounds/playing-a-scale>. Acesso em: 24 Apr. 2021.

	1 - Take on me:
    Passive Buzzer Song: “Take on Me” By A-Ha! Arduino Project Hub. Disponível em: <https://create.arduino.cc/projecthub/GeneralSpud/passive-buzzer-song-take-on-me-by-a-ha-0f04a8>. Acesso em: 24 Apr. 2021.

	2 - Harry Potter:
    ROBSONCOUTO. robsoncouto/arduino-songs. GitHub. Disponível em: <https://github.com/robsoncouto/arduino-songs>. Acesso em: 24 Apr. 2021.

	3 - Zelda Theme:
    ROBSONCOUTO. robsoncouto/arduino-songs. GitHub. Disponível em: <https://github.com/robsoncouto/arduino-songs>. Acesso em: 24 Apr. 2021.

	4 - Cantina Band:
	ROBSONCOUTO. robsoncouto/arduino-songs. GitHub. Disponível em: <https://github.com/robsoncouto/arduino-songs>. Acesso em: 24 Apr. 2021.

	5 - Imperial March:
    ROBSONCOUTO. robsoncouto/arduino-songs. GitHub. Disponível em: <https://github.com/robsoncouto/arduino-songs>. Acesso em: 24 Apr. 2021.
    
    6 - Pacman:
    ROBSONCOUTO. robsoncouto/arduino-songs. GitHub. Disponível em: <https://github.com/robsoncouto/arduino-songs>. Acesso em: 24 Apr. 2021.
    
    Easy guitar riffs:
    https://beginnerguitarhq.com/easy-guitar-riffs
  
	ADILSON THOMSEN. Controlando um LCD 16x2 com Arduino - FilipeFlop. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/>. Acesso em: 25 Apr. 2021.

	ADILSON THOMSEN. Como usar o Teclado Matricial 4×4 com Arduino. FilipeFlop. Disponível em: <https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/>. Acesso em: 25 Apr. 2021.

*/
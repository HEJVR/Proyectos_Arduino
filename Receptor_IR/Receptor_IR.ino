
#include <IRremote.h>		// importa libreria IRremote

#define Boton1 0xFC03BF00
#define Boton2 0xFF00BF00
#define Boton3 0xFE01BF00
#define Boton4 0xFD02BF00
#define Boton5 0xFB04BF00
#define Boton6 0xFA05BF00
#define Boton7 0xF906BF00

#define Boton8 0xF807BF00

#define Leds1 2
#define Leds2 4
#define Leds3 6
#define Leds4 8
#define Leds5 10

int T = 200;

int SensorIR = 11;    		// pin del sensor IR 
 
void setup() { 

  Serial.begin(9600);     				// inicializa comunicacion serie a 9600 bps
  IrReceiver.begin(SensorIR, DISABLE_LED_FEEDBACK);    	// inicializa recepcion de datos

  pinMode(Leds1, OUTPUT);
  pinMode(Leds2, OUTPUT);
  pinMode(Leds3, OUTPUT);
  pinMode(Leds4, OUTPUT);
  pinMode(Leds5, OUTPUT);

} 

void loop() { 
  if (IrReceiver.decode()) {   				// si existen datos ya decodificados
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // imprime valor en hexadecimal en monitor
    IrReceiver.resume();      				// resume la adquisicion de datos

    if (IrReceiver.decodedIRData.decodedRawData == Boton1){
      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton2){

      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);
      digitalWrite(Leds1, !digitalRead(Leds1));

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton3){

      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);
      digitalWrite(Leds2, !digitalRead(Leds2));

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton4){

      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);
      digitalWrite(Leds3, !digitalRead(Leds3));

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton5){

      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);
      digitalWrite(Leds4, !digitalRead(Leds4));

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton6){

      digitalWrite(Leds1, LOW);
      digitalWrite(Leds2, LOW);
      digitalWrite(Leds3, LOW);
      digitalWrite(Leds4, LOW);
      digitalWrite(Leds5, LOW);
      digitalWrite(Leds5, !digitalRead(Leds5));

    }

    if (IrReceiver.decodedIRData.decodedRawData == Boton7){

      digitalWrite(Leds1, HIGH);
      digitalWrite(Leds2, HIGH);
      digitalWrite(Leds3, HIGH);
      digitalWrite(Leds4, HIGH);
      digitalWrite(Leds5, HIGH);

    }
  }
  delay (100);        					// breve demora de 100 ms.
}
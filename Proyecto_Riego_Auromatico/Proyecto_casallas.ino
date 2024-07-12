//Librerias que requierre el programa
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo1;

//sensores de nivel de agua 
#define Sen1 2
#define Sen2 0
//leds que indican el nivel de agua 
#define Led1 14
#define Led2 12
#define Led3 13
//bosser que indica el llenado del tanque 
#define Bosser 16

//se definen las caracteristica de la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//variables del texto de la pantalla LCD
String Text = "Nivel de agua";
String Nivel1 = "100%";
String Nivel2 = "20% - 80%";
String Nivel3 = "0% - 20%";
String Adver = "Iniciando llenado";
String Llenando = "LLenando...";
String LlenadoL = "LLenado listo ;)";

//caracteristicas y rango de accion del servo motor 
int PinServo = 14;
int PulsorMin = 500;
int PulsorMax = 2600;

//angulo de cerrado y apertura de la llave de paso de agua 
int Open = 30;
int Close = 190;

//otras variables segundarias
int Var = 1;
int T1 = 500;
int T2 = 1000;
int T3 = 5000;
int TT = 2000;




void setup() {
  // put your setup code here, to run once:

  //definicion de entrada o salida de cada pin 
  pinMode(Sen1, OUTPUT);  //sensor 
  pinMode(Sen2, OUTPUT);  //sensor 
  pinMode(Led1, OUTPUT);  //Led 
  pinMode(Led2, OUTPUT);  //Led 
  pinMode(Led3, OUTPUT);  //Led
  pinMode(Bosser, OUTPUT);  //Bosser 

  //Niveles e inicacion del servo motor 
  servo1.attach(PinServo, PulsorMin, PulsorMax);

  //Inicializacion del panle LCD
  lcd.init();
  lcd.backlight();

  //Velocidad del monitor serial 
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run reatedly:

  //servo1.write(Open);
  //delay(2000);
  //servo1.write(Close);
  //delay(5000);

  if(digitalRead(Sen1)==1  &&  digitalRead(Sen2)==1){
    if(Var==1){

      Serial.println("Nivel de agua " + Nivel1); //imprime texto en el monitor serial 

      servo1.write(Close);
      delay(TT);

      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);

      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print(Text);
      lcd.setCursor(6,1);
      lcd.print(Nivel1);
      delay(T1);
    

    }
  }


  if(digitalRead(Sen1)==1  &&  digitalRead(Sen2)==0){
    if(Var==1){

      Serial.println("Nivel de agua " + Nivel2); //imprime texto en el monitor serial 

      servo1.write(Close);
      delay(TT);

      digitalWrite(Led1, LOW);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);

      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print(Text);
      lcd.setCursor(4,1);
      lcd.print(Nivel2);
      delay(T1);
    

    }
  }


  if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
    if(Var==1){
      Serial.println("Nivel de agua " + Nivel3); //imprime texto en el monitor serial 

      servo1.write(Close);
      delay(TT);      

      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, HIGH);

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(Text);
        lcd.setCursor(4,1);
        lcd.print(Nivel3);

        servo1.write(Close);
        delay(T3);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(7,1);
      lcd.print("5");
      delay(T2);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(7,1);
      lcd.print("4");
      delay(T2);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(7,1);
      lcd.print("3");
      delay(T2);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(7,1);
      lcd.print("2");
      delay(T2);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(7,1);
      lcd.print("1");
      delay(T2);
      }

      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(Adver);
      lcd.setCursor(3,1);
      lcd.print("Espere...");
      delay(T2);
      }


      if(digitalRead(Sen1)==0  &&  digitalRead(Sen2)==0){
      Var = 2;

      lcd.clear();
      lcd.setCursor(2,1);
      lcd.print(Llenando);

      servo1.write(Open);
      delay(TT);
      }
    }
  }


  if(Var==2){
    servo1.write(Open);
    delay(TT);

    lcd.clear();
    lcd.setCursor(2,1);
    lcd.print(Llenando);

    digitalWrite(Bosser, HIGH);
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    delay(T2);
    digitalWrite(Bosser, LOW);
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    delay(T2);
      
    if(digitalRead(Sen1)==1  &&  digitalRead(Sen2)==1){
      digitalWrite(Bosser, HIGH);
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      delay(T1);
      digitalWrite(Bosser, LOW);
      digitalWrite(Led1, LOW);
      delay(T1);
      digitalWrite(Bosser, HIGH);
      digitalWrite(Led1, HIGH);
      delay(T1);
      digitalWrite(Bosser, LOW);
      digitalWrite(Led1, LOW);
      delay(T1);
      digitalWrite(Bosser, HIGH);
      digitalWrite(Led1, HIGH);
      delay(T1);
      digitalWrite(Bosser, LOW);
      digitalWrite(Led1, LOW);
      delay(T1);
      digitalWrite(Bosser, HIGH);
      digitalWrite(Led1, HIGH);
      delay(T3);
      digitalWrite(Bosser, LOW);
      digitalWrite(Led1, LOW);

      servo1.write(Close);
      delay(TT);    

      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(LlenadoL);

      Var = 1;

      servo1.write(Close);
      delay(TT);
    }
  }
}

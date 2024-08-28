#define Boton 13
#define R D5
#define G D6
#define B D7

int RC = 0;
int GC = 0;
int BC = 0;

int Max;
int MinRGB = 0;
int MitRGB = 127;
int MaxRGB = 255;
int x = 17;

int Mic;
int Mode = 1;
int T = 20;
int Pot;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Boton, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  Mic = (analogRead(A0) - 15);
  Max = analogRead(A0);
  Serial.println(Mic);

  if (Pot = 2){

  if ((Mic >= (Max/6)*0) && (Mic < (Max/6)*1)){
    RC = MaxRGB;
    RC = MaxRGB;
    RC = MaxRGB - Mic * (1.5 * 1);
  }

  if ((Mic >= (Max/6)*1) && (Mic < (Max/6)*2)){
    RC = MaxRGB - Mic * (1.5 * 2);
    RC = MaxRGB;
    RC = MinRGB;
  }

  if ((Mic >= (Max/6)*2) && (Mic < (Max/6)*3)){
    RC = MinRGB;
    RC = MaxRGB;
    RC = Mic * (1.5 * 3);
  }

  if ((Mic >= (Max/6)*3) && (Mic < (Max/6)*4)){
    RC = MinRGB;
    RC = Mic * (1.5 * 3);
    RC = MaxRGB;
  }

  if ((Mic >= (Max/6)*4) && (Mic < (Max/6)*5)){
    RC = MaxRGB - Mic * (1.5 * 5);
    RC = MinRGB;
    RC = MaxRGB;
  }

  if ((Mic >= (Max/6)*5) && (Mic < (Max/6)*6)){
    RC = MaxRGB;
    RC = MinRGB;
    RC = MaxRGB - Mic * (1.5 * 6);
  }

  analogWrite(R, RC);
  analogWrite(G, GC);
  analogWrite(B, BC);
  
  }

  analogWrite(B, 255);

  delay(T);

}

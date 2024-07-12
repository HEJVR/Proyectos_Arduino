#define Sen 5
#define Led 4

void setup() {
  // put your setup code here, to run once:
  pinMode(Sen, INPUT);
  pinMode(Led, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(digitalRead(Sen));
  
  //if(digitalRead(Sen) = HIGH){
  //  digitalWrite(Led, HIGH);
  //}
  
  //else{
  //  digitalWrite(Led, LOW);
  //}


}

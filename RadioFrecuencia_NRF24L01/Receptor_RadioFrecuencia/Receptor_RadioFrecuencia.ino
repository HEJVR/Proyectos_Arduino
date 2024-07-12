#include <SPI.h>
#include <RF24.h>

#define Led D4

int Luz;

RF24 radio(D0, D1);                       // Configura los pines CE y CSN
const byte direccionEmisor[6] = "00001";  // Dirección del emisor

struct Datos {
  byte fuente;
  float valor;
  int Num;
};

void setup() {
  radio.begin();
  radio.openReadingPipe(1, direccionEmisor);
  radio.setPALevel(RF24_PA_HIGH);  // Puedes ajustar la potencia de entrada si es necesario
  radio.startListening();

  pinMode(Led, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (radio.available()) {
    Datos datos;
    radio.read(&datos, sizeof(datos));

    // Enviar una respuesta al emisor
    char respuesta[] = "Mensaje recibido en el receptor.";
    radio.stopListening();
    radio.write(&respuesta, sizeof(respuesta));
    radio.startListening();

    // Procesa los datos recibidos según la fuente
    switch (datos.fuente) {
      case 1:  // Temperatura
        Serial.println(String(datos.valor) + " + " + String(datos.Num));

        Luz = datos.valor;

        if (Luz == 1.00) {
          digitalWrite(Led, LOW);

        }

        else {
          digitalWrite(Led, HIGH);
        }


        // Realiza cualquier acción adicional según la fuente
        break;
        // Puedes agregar más casos para otras fuentes aquí
    }
  }
}

#include <SPI.h>
#include <RF24.h>

#define Bot D8

RF24 radio(D0, D1);                          // Configura los pines CE y CSN
const byte direccionReceptor[6] = "00001";  // Dirección del receptor

struct Datos {
  byte fuente;  // Identificador de la fuente de la señal (por ejemplo, 1 para temperatura, 2 para LED, 3 para otro)
  float valor;  // Valor de la señal
  int Num;
};

void setup() {
  radio.begin();
  radio.openWritingPipe(direccionReceptor);
  radio.setPALevel(RF24_PA_HIGH);  // Puedes ajustar la potencia de salida si es necesario entre LOW o HIGH dependiendo del rango y el consumo de enegia
  
  pinMode(Bot, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  Datos datos;

  // Simulamos datos de diferentes fuentes
  datos.fuente = 1;                    // Fuente 1: Temperatura
  datos.valor = digitalRead(Bot);  // Obtener el valor de temperatura
  datos.Num = 22;

  // Envía los datos al receptor
  radio.write(&datos, sizeof(datos));

  // Espera una respuesta del receptor
  char respuesta[33] = "";
  if (radio.available()) {
    radio.read(&respuesta, sizeof(respuesta));
    Serial.println("Respuesta del receptor: " + String(respuesta));
  }

  //delay(500);  // Puedes ajustar la frecuencia de envío de datos
}

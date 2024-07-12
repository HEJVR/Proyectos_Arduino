#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

#define Led D4

// Singleton instance of the radio driver
RH_NRF24 driver(D2, D3);
// RH_NRF24 driver(8, 7);   // For RFM73 on Anarduino Mini

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup() {

  pinMode(Led, OUTPUT);

  Serial.begin(9600);
  
  if (!manager.init()){
    Serial.println("init failed"); // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  }
}

uint8_t data[] = "And hello back to you";
// Dont put this on the stack:
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];

void loop(){
  if (manager.available()){

    // Wait for a message addressed to us from the client
    uint8_t len = sizeof(buf);
    uint8_t from;

    if (manager.recvfromAck(buf, &len, &from)){

      Serial.print("got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
      digitalWrite(Led, HIGH);

      // Send a reply back to the originator client
      if (!manager.sendtoWait(data, sizeof(data), from)){
        Serial.println("sendtoWait failed");
      }
    }
  }

  else{
    digitalWrite(Led, LOW);
  }
}


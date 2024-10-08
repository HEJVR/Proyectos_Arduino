#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Singleton instance of the radio driver
RH_NRF24 driver(D2, D4);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

void setup() {
  
  Serial.begin(9600);
  if (!manager.init()){
    Serial.println("init failed");
  }// Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm

}

uint8_t data[] = "Hello World!";
// Dont put this on the stack:
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];

void loop(){

  Serial.println("Sending to nrf24_reliable_datagram_server");
    
  // Send a message to manager_server
  if (manager.sendtoWait(data, sizeof(data), SERVER_ADDRESS)){

    uint8_t len = sizeof(buf);
    uint8_t from;   

    if (manager.recvfromAckTimeout(buf, &len, 2000, &from)){

      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);

      //Serial.print();
    }

    else{
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }

  }
  else{
    Serial.println("sendtoWait failed");
  }

  delay(500);

}


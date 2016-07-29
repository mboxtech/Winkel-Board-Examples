#include <SPI.h>  
#include "RF24.h"
#include <printf.h>

RF24 radio (7, 8);

struct package
{
  int id=1,id1=0;
  float temperature = 18.3,temperature1 = 0.0;
  char  text[100] = "Text to be transmitted",text1[100] ="empty";
};

//struct package1
//{
//  int id=0;
//  float temperature = 0.0;
//  char  text[100] ="empty";
//};

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

typedef struct package Package;
Package data;

//typedef struct package1 Package1;
//Package1 data1;

bool radioNumber = 0, role = 0,got = 0;

void setup()
{
  Serial.begin(115200);
  printf_begin();
//  delay(1000);
  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  Serial.println(" ");
  radio.begin();
  radio.setAutoAck(1);                    // Ensure autoACK is enabled so rec sends ack packet to let you know it got the transmit packet payload
  radio.enableAckPayload();               // Allow optional ack payloads
  radio.setRetries(5,15);    
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_2MBPS ) ; 
  

  if(radioNumber){
    radio.openWritingPipe(pipes[0]);
    radio.openReadingPipe(1, pipes[1]);
    Serial.println("_____Set As Transmitter_____");
  }else{
    radio.openWritingPipe(pipes[1]); 
    radio.openReadingPipe(1, pipes[0]);
    radio.startListening();
    Serial.println("_____Set As Receiver_____");
  }
  
//  radio.printDetails();
}

void loop() {
  if (role == 0)  {
    // Rx
    delay(1000);
      if ( radio.available()){
        
          while (radio.available())
          {
            got = 1;
            radio.read( &data, sizeof(data) );
          }
          if(got==1){
              Serial.print("\nPackage:");
              Serial.print(data.id);
              Serial.print("\n");
              Serial.println(data.temperature);
              Serial.println(data.text);
              got = 0;
          }else{
              Serial.print("\nPackage:");
              Serial.print(data.id1);
              Serial.print("\n");
              Serial.println(data.temperature1);
              Serial.println(data.text1);
              got = 0;            
          }
        } 
  }

  if (role == 1)  {
    // Tx
    radio.write(&data, sizeof(data)); 
    
      Serial.print("\nPackage:");
      Serial.print(data.id);
      Serial.print("\n");
      Serial.println(data.temperature);
      Serial.println(data.text);
      data.id = data.id + 1;
      data.temperature = data.temperature+0.1;
      delay(1000);
    
  }

  if (Serial.available()){
    char c = toupper(Serial.read());
    if ( c == 'T' && role == 0 ){   
      Serial.println(" ");   
      Serial.println(F("*** CHANGING TO TRANSMIT ROLE -- PRESS 'R' TO SWITCH BACK"));
      role = 1;                  // Become the primary transmitter (ping out)
        radio.powerDown();
        delay(10);
        radio.powerUp();
        radio.openWritingPipe(pipes[0]);
        radio.openReadingPipe(1, pipes[1]);
        radio.stopListening();
        //radio.printDetails();
        Serial.println(" ");
        Serial.println("_____It's now working as Transmitter_____");
    
   }else if ( c == 'R' && role == 1 ){
    Serial.println(" ");
      Serial.println(F("*** CHANGING TO RECEIVE ROLE -- PRESS 'T' TO SWITCH BACK"));      
       role = 0;                // Become the primary receiver (pong back)
       radio.powerDown();
       delay(10);
       radio.powerUp();
       radio.openWritingPipe(pipes[1]);
       radio.openReadingPipe(1, pipes[0]);
       radio.startListening();
       //radio.printDetails();
       Serial.println(" ");
       Serial.println("_____It's now working as Receiver_____");       
    }
  }

}

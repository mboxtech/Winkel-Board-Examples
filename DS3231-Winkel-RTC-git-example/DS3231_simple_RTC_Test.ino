

#include <Wire.h>
#include <DS3231.h> //You need this library and can download from above link or use the forked library at https://github.com/mboxtech/Arduino-DS3231

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  
}

void setClck(){
// Function for setting DS3231 on winkel board
  int yr,mnth,hrs,mins,sec,day;
   Serial.println("Enter year for ex: 2016");
  while(Serial.available() == 0){
   
     
  }
  yr = Serial.parseInt();
  Serial.println("Enter month 0-12 ");
  while(Serial.available() == 0){
    
     
  }
  mnth = Serial.parseInt();
   Serial.println("Enter day 1-31");
  while(Serial.available() == 0){
   
     
  }
  day = Serial.parseInt();
  Serial.println("Enter hrs 0-23");
  while(Serial.available() == 0){
    
     
  }
  hrs = Serial.parseInt();
  Serial.println("Enter mins 0-59");
  while(Serial.available() == 0){
    
     
  }
  mins = Serial.parseInt();
  Serial.println("Enter sec 0-59");
  while(Serial.available() == 0){
    
     
  }
  sec = Serial.parseInt();
  clock.setDateTime(yr,mnth,day,hrs,mins,sec);
}


void loop()
{
  //Open console and press 'a' to set the date and time.
  if(Serial.available()){
    
    char ser = Serial.read();
    if(ser == 'a'){
      setClck();
    }
  }
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);
}

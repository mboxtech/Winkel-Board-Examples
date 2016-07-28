# OTA Programming

The above example shows how ESP-12E on the winkel board enables OTA programming. When you buy winkel board, the above sketch comes loaded so you can immediately start programming the ESP-21E WiFi module.

## Requirements
- Arduino IDE 1.6.7 and later. Recommended 1.6.9
- Python 2.7.x

## Say Good Buy to programmers.

## How to use.
* When winkel board is powered on, ESP1-12E will go into WiFi AP Mode. It uses popular WiFiManager library to do so.
* This is because you can configure the onboard WiFi Module to connect to your Router's SSID and Password.
* Scan wireless network using your computer, mobile or tablet and connect to "AutoConnectAP" usin password "password"
* After your device is connected to it, open browser in that device and go to `http://192.168.4.1`
* You will see a configuration page where you can configure WiFi as per your router.
* After enter your router's SSID & password, ESP-12E will reset and automatically connect to your router.

## Drawbacks
* You will not be able to open console in Arduino IDE. if serial monitoring is your thing, then OTA programming might irritate you.
	- **Solution** : You can write a short snippet on microcontroller to read ESP-12E's serial and display it when you open the microcontroller's serial. That way you can perform serial monitoring. All controllers on Winkel have 2 nd more UART's which allows initiate 2 or more serials
	example : 
	```java			
			  Serial.begin(115200);
			  Serial1.begin(115200); //ESP-12E's serial can be captured here
			  if(Serial1.available()){
			  	char capture = Serial1.read();
			  	Serial.print(capture);
			  }
			  ```
# OTA Programming

The above example shows how ESP-12E on the winkel board enables OTA programming. When you buy winkel board, the above sketch comes loaded so you can immediately start programming the ESP-21E WiFi module.

# Table of contents
* Requirements
* Configuration
* How to program

## Requirements
- Arduino IDE 1.6.7 and later. Recommended 1.6.9
- Python 2.7.x

## Say Good Buy to programmers.

## Configuration
* When winkel board is powered on, ESP1-12E will go into WiFi AP Mode. It uses popular WiFiManager library to do so.
* This is because you can configure the onboard WiFi Module to connect to your Router's SSID and Password.
* Scan wireless network using your computer, mobile or tablet and connect to "AutoConnectAP" usin password "password"
* After your device is connected to it, open browser in that device and go to `http://192.168.4.1`
* You will see a configuration page where you can configure WiFi as per your router.
* After enter your router's SSID & password, ESP-12E will reset and automatically connect to your router.

## How to upload a program
* You will not be able to perfom uploads until you have configured the WiFi module to connect to your local network.
* After successfull configuration the onboard ESP-12E should obtain an IP address. You can verify this by going to your routers page or you can download an app called "Fing" and scan your network to see if the ESP-12E has got an IP.
* Now open your Arduino IDE and go to `Tools -> Ports`
* Here you will see "winkelota at <ip_of_ESP>" under `Network Ports`.
* Select that and hit upload.
* **Remember : The above sketch is necessarry for OTA to work everytime. There is a section `/*your code goes here*/` in the sketch where you are suppossed to insert your code. And required initialisation can be done in setup().**

## Drawbacks
* You will not be able to open console in Arduino IDE over network port. If serial monitoring is your thing, then OTA programming might irritate you.
	- **Solution** : You can write a short snippet on microcontroller to read ESP-12E's serial and display it when you open the microcontroller's serial over it's COM port. That way you can perform serial monitoring. All controllers on Winkel have 2 nd more UART's which allows initiate 2 or more serials
	example : 
	```java			
			  Serial.begin(115200);
			  Serial1.begin(115200); //ESP-12E's serial can be captured here
			  if(Serial1.available()){
			  	char capture = Serial1.read();
			  	Serial.print(capture);
			  }
	```		  
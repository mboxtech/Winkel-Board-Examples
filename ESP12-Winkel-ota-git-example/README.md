#OTA Programming

The above example shows how ESP-12E on the winkel board enables OTA programming. When you buy winkel board, the above sketch comes loaded so you can immediately start programming the ESP-21E WiFi module.

## Requirements
- Arduino IDE 1.6.7 and later. Recommended 1.6.9
- Python 2.7.x

## Say Good Buy to programmers.

## How to use.
- When winkel board is powered on, ESP1-12E will go into WiFi AP Mode. It uses popular WiFiManager library to do so.
- This is because you can configure the onboard WiFi Module to connect to your Router's SSID and Password.
- Scan wireless network using your computer, mobile or tablet and connect to "AutoConnectAP" usin password "password"
- After your device is connected to it, open browser in that device and go to <code>http://192.168.4.1<code>
- You will see a configuration page where you can configure WiFi as per your router.
- After enter your routers' SSID password, ESP-21 will reset and automatically connect to your router.


<h1 align="center">🐬 FlipWifi 📶</h1>
<h2 align="center">❗ Archived - Not Done ❗</h2>

![License](https://img.shields.io/badge/license-Apache%202.0-blue)

This repository contains firmware for ESP and the accompanying application for Flipper Zero, enabling Flipper to connect to WiFi via ESP.

## 💻 Features

- Connect Flipper Zero to WiFi network using ESP module.
- Simplify app development that requires Internet.
- Perform HTTP/S requests, including POST and GET requests, effortlessly.
- **Upcoming features (In development):**
    - Update latest FW for flipper without the need for a PC or phone - Monentum & Official Firmware [Status: 🔴].
    - Automatic connection to known WiFi networks [Status: 🟠].
    - Download AssetsPacks [Status: 🔴].
    - Flash ESP with our compatibile FW [Status: 🟠].
    - Support for ESP12 and ESP8266

## 🎛️ Usage

- **Flash the firmware** onto the ESP module. [Download](https://github.com/Butwm/FlipperZero-Wifi-App/releases)
- **Connect ESP to Flipper:**

    <table style="width:100%; background-color: #f2f2f2;">
      <tr>
        <th>Flipper Zero</th>
        <th>ESP</th>
      </tr>
      <tr>
        <td>TX</td>
        <td>RX</td>
      </tr>
      <tr>
        <td>RX</td>
        <td>TX</td>
      </tr>
      <tr>
        <td>3v3</td>
        <td>3v3</td>
      </tr>
        <tr>
        <td>GND</td>
        <td>GND</td>
      </tr>
    </table>

- **Download latest app** and upload it on Flipper. [Download](https://github.com/Butwm/FlipperZero-Wifi-App/releases)
- **Open app and connect to WiFi!**

## ✅ Compatibility 

<table style="width:100%; background-color: #f2f2f2;">
  <tr>
    <th></th>
    <th>ESP12</th>
    <th>ESP32</th>
    <th>ESP8266</th>
  </tr>
  <tr>
    <td>Supported</td>
    <td>❌</td>
    <td>❌</td>
    <td>❌</td>
  </tr>
  <tr>
    <td>Tested</td>
    <td>❌</td>
    <td>✅</td>
    <td>❌</td>
  </tr>
</table>

## 💻 Apps Compatibile with FlipWifi

- Weather App by [Vollukas](https://github.com/vollukas)

## Contributors

- [Butwm](https://www.github.com/Butwm)

Feel free to contribute to this project by submitting pull requests or opening issues.

## 🛠️ For Developers

Are you looking to develop an application or game for Flipper that requires Internet connectivity?

Commands and what they do:

 - Help: Displays available commands and their usage.

    ```
    $ help
    
    $  make-getrequest:[url] - sends a GET request to the specified URL
       make-postrequest:[url]:[data to send] - sends a POST request to the specified URL with the provided data
       scanap - Scan for Access Points around you
       connect:ssid:password - connects to a WiFi network with the specified SSID and password
       disconnect - disconnects from the current WiFi network
    ```

- Make GET Request: Initiates a GET request to the specified URL
    ```
    $ make-getrequest:https://google.com/
    
    $ <HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
      <TITLE>301 Moved</TITLE></HEAD><BODY>
      <H1>301 Moved</H1>
      The document has moved
      <A HREF="https://www.google.com/">here</A>.
      </BODY></HTML>
    ```
- Make POST Request: Sends a POST request to the specified URL with provided data.
    1. you can put all data into one url
       ```
        $ make-postrequest:https://reqres.in/api/users?id=2&name=Janet
        $ {"id":"2","name":"Janet","createdAt":"2024-02-26T14:31:55.710Z"}
       ```
    2. or you can split the URL [url]:[data]
       ```
       $ make-postrequest:https://reqres.in/api/users:id=2&name=Janet
       $ {"make-postrequest:https://reqres.in/api/users:id":"2","name":"Janet","id":"396","createdAt":"2024-02-27T17:16:13.865Z"}
       ```
 - Connect to Wifi Network: Establish a connection to a Wi-Fi network.
    1. connect to wifi with password
       ```
       $ connect:[SSID]:[PASSWORD]
       $ Connecting
         Connected to the WiFi
         Local ESP IP: xxx.xxx.xxx.xxx
        ```
    2. connect to wifi without password
       ```
       $ connect:[SSID]
       $ Connecting
         Connected to the WiFi
         Local ESP IP: xxx.xxx.xxx.xxx
       ```
- Disconnect from Wifi Network: Terminate the connection to the current Wi-Fi network.
     ```
     $ disconnect
     $ Wifi disconnected
     ```
- Scan Access Points: Scan for available Access Points.
  ```
  $ scanap
  $ Scanning...
    Scan complete
    29 networks found
    [0] xxxxx (-52)
    [1] xxxxxx (-54)
    [2] xxxxx (-55)
    [3] xxxxxxxxx (-60)
    [4] xxxxx (-68)
    [5] xxxxx (-72)
    [6] xxxxx (-73)
    [7] xxxxx (-74)
    [8] xxxxxx (-76)
  ```

- Automatically Connect to Wifi Network (Work in Progress): Automatically reconnect to a previously known Wi-Fi network.
     
This project is licensed under the [Apache License v2.0](https://github.com/Butwm/FlipperZero-Wifi-App/blob/main/LICENSE).

<h1 align="center">🚀 FlipperZero WiFi 📶</h1>

![License](https://img.shields.io/badge/license-Apache%202.0-blue)

This repository contains firmware for ESP and the accompanying application for Flipper Zero, enabling Flipper to connect to WiFi via ESP.

## Features

- Connect Flipper Zero to WiFi network using ESP module.
- Simplify app development that requires Internet.
- Perform HTTP/S requests, including POST and GET requests, effortlessly.
- **Upcoming features (In development):**
    - Update Flipper firmware without the need for a PC or phone.
    - Automatic connection to known WiFi networks.

## Usage

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
    </table>

- **Download latest app** and upload it on Flipper. [Download](https://github.com/Butwm/FlipperZero-Wifi-App/releases)
- **Open app and connect to WiFi!**

## Compatibility 

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

## Contributors

- [Butwm](https://www.github.com/Butwm)

Feel free to contribute to this project by submitting pull requests or opening issues.

This project is licensed under the [Apache License v2.0](https://github.com/Butwm/FlipperZero-Wifi-App/blob/main/LICENSE).

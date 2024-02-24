#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password = "";
const char* requestURL = "https://guthib.com";

bool wifiConnected = false;
bool autoConnectEnabled = false;

HTTPClient client; 

void setup() {
    Serial.begin(115200);
    delay(1000);

    WiFi.disconnect(true);
}

void loop() {
    if (Serial.available() > 0) {
        String inputString = Serial.readStringUntil('\n');
        inputString.trim();

          if (inputString.startsWith("connect:")) {
              int colonIndex = inputString.indexOf(':');
              String newSSID = inputString.substring(colonIndex + 1, inputString.indexOf(':', colonIndex + 1));
              String newPassword = inputString.substring(inputString.indexOf(':', colonIndex + 1) + 1);

              ssid = newSSID.c_str(); 
              password = newPassword.c_str(); 

            if (!wifiConnected) {
                WiFi.mode(WIFI_STA);
                WiFi.begin(ssid, password);
                Serial.println("\nConnecting");

                while (WiFi.status() != WL_CONNECTED) {
                    Serial.print(".");
                    delay(100);
                }

                Serial.println("\nConnected to the WiFi network");
                Serial.print("Local ESP32 IP: ");
                Serial.println(WiFi.localIP());

                wifiConnected = true;
            } else {
                Serial.println("Already connected to WiFi");
            }
        } else if (inputString == "disconnect") {
            if (wifiConnected) {
                WiFi.disconnect(true);
                wifiConnected = false;
                Serial.println("Wifi disconnected");
            } else {
                Serial.println("Not connected to WiFi");
            }
        } else if (inputString == "enable-autoconnect") {
            autoConnectEnabled = true;
            Serial.println("Auto-connect enabled");
        } else if (inputString == "disable-autoconnect") {
            autoConnectEnabled = false;
            Serial.println("Auto-connect disabled");
        } else if (inputString.startsWith("makerequest:")) {
            String urlParameter = inputString.substring(12);
            if (urlParameter.startsWith("http://") || urlParameter.startsWith("https://")) {
                requestURL = urlParameter.c_str();
            } else {
                String tempURL = "https://" + urlParameter;
                requestURL = tempURL.c_str();
            }

            client.begin(requestURL);
            int responseCode = client.GET();
            if(responseCode > 0) {
              Serial.println(client.getString());
            }
        } else if (inputString == "help") {
          Serial.println("makerequest: + url/domain for http/s request, connect:ssid:password for wifi connect, disconnect for disconnect");
        }
    }

    if (autoConnectEnabled && !wifiConnected) {
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);
        Serial.println("\nConnecting automatically");

        while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(100);
        }

        Serial.println("\nConnected to the WiFi network");
        Serial.print("Local ESP32 IP: ");
        Serial.println(WiFi.localIP());

        wifiConnected = true;
    }
}

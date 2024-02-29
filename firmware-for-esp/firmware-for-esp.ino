#include <WiFi.h>
#include <HTTPClient.h>
#include <iostream>
#include <string>
#include <ArduinoJson.h>

const char* ssid = "";
const char* password = "";
const char* getrequestURL = "https://guthib.com";
const char* postrequestURL = "https://reqres.in/api/users";
const char* postrequestData = "id=2&name=Janet";

char addthisChar = '?';

bool wifiConnected = false;

HTTPClient client; 


//Serial Console
void setup() {
    Serial.begin(115200);
    delay(1000);

    WiFi.disconnect(true);
}

void loop() {
    // Check if there is incoming serial data
    if (Serial.available() > 0) {
        // Read the incoming data until a newline character is received
        String inputString = Serial.readStringUntil('\n');
        inputString.trim();

        // Check for various commands in the input string
        if (inputString.startsWith("connect:")) {
            // Extract SSID and password from the input string
            int colonIndex = inputString.indexOf(':');
            String newSSID = inputString.substring(colonIndex + 1, inputString.indexOf(':', colonIndex + 1));
            String newPassword = inputString.substring(inputString.indexOf(':', colonIndex + 1) + 1);

            // Update the SSID and password
            ssid = newSSID.c_str();
            password = newPassword.c_str();

            // Connect to WiFi if not already connected
            if (!wifiConnected) {
            connectToWifi();
            } else {
                Serial.println("Already connected to WiFi");
            }

        } else if (inputString == "disconnect") {
            // Disconnect from WiFi
            disconnectFromWifi();

        } else if (inputString.startsWith("make-getrequest:")) {
            // Handle get request
            handleGetRequest(inputString.substring(16));

        } else if (inputString.startsWith("make-postrequest:")) {
            // Handle post request
            handlePostRequest(inputString);

        } else if (inputString == "help") {
            // Print help message
            Serial.printf("make-getrequest:[url] - sends a GET request to the specified URL\nmake-postrequest:[url]:[data to send] - sends a POST request to the specified URL with the provided data\nscanap - Scan for Access Points around you\nconnect:ssid:password - connects to a WiFi network with the specified SSID and password\ndisconnect - disconnects from the current WiFi network");

        } else if(inputString == "scanap") {
            // Scan Acess Points
            ScanAP();
        } else {
            Serial.println("This command dont exist or you are not connected to Wifi");
        }
    }
}

void connectToWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP IP: ");
    Serial.println(WiFi.localIP());
    wifiConnected = true;
}

void disconnectFromWifi() {
    if (wifiConnected) {
        WiFi.disconnect(true);
        wifiConnected = false;
        Serial.println("Wifi disconnected");
    } else {
        Serial.println("Not connected to WiFi");
    }
}

void handleGetRequest(String urlParameter) {

    std::string getrequestURLverify = urlParameter.c_str();

    if (getrequestURLverify.empty()) {
        Serial.println("It won't work without a URL");
    } else {

        if (urlParameter.startsWith("http://") || urlParameter.startsWith("https://")) {
            getrequestURL = urlParameter.c_str();
        } else {
            String tempURL = "https://" + urlParameter;
            getrequestURL = tempURL.c_str();
        }

        client.begin(getrequestURL);
        int getresponseCode = client.GET();
        if (getresponseCode > 0) {
          DynamicJsonDocument doc(1024);
          deserializeJson(doc, client.getString());
          
          Serial.println(doc["data"]["email"].as<String>());

        }
    }
}
void handlePostRequest(String inputString) {
    int urlStartIndex = inputString.indexOf("://");
    int colonIndex = inputString.indexOf(':');
    int ampersandIndex = inputString.indexOf('&');
    String urlpostParameter = inputString.substring(colonIndex + 1, inputString.indexOf('?', colonIndex + 1));
    String postData = inputString.substring(inputString.indexOf('?', colonIndex + 1) + 1);

    postrequestURL = urlpostParameter.c_str(); 
    postrequestData = postData.c_str(); 

    std::string postrequestURLverify = postrequestURL;
    std::string postrequestDataverify = postrequestData;

    if (postrequestURLverify.empty()) {
        Serial.println("It won't work without a URL");
    } else {

        if (postrequestURLverify.back() != addthisChar) {

            postrequestURLverify.push_back(addthisChar);

            postrequestURL = postrequestURLverify.c_str();
            }


        client.begin(postrequestURL);
        client.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
        int postresponseCode = client.POST(postrequestData);
        if (postresponseCode > 0) {
            Serial.println(client.getString());
        } else if (postresponseCode == 118) {
            Serial.println("You are not connected to Wifi or Host is unreachable");
        } else {
            Serial.print("Error sending POST request Error: ");
            Serial.println(postresponseCode);
        }
    }
}

void ScanAP() {
    
    //scan
    Serial.println("Scanning...");

    int n = WiFi.scanNetworks();
    Serial.println("Scan complete");

    if (n == 0) {
        Serial.println("No networks found try again");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
        // Name of AP and strange of signal
        Serial.print("[");
        Serial.print(i);
        Serial.print("]");
        Serial.print(" ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.println(")");
        }
    }
}
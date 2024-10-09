/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */

#include <WiFiS3.h>
#include <MQTTClient.h>
#include <R4HttpClient.h>

// WiFi credentials
const char* ssid = "ITFORGE_UFO";  // Your SSID
const char* password = "";         // No password for open networks

// Server details (replace with your target server)
const char* serverUrl = "https://portal.it.kmitl.ac.th/internal/dologin.php";
const int serverPort = 4081;

// Create an instance of WiFiSSLClient (for HTTPS, use WiFiClientSecure)
WiFiSSLClient client;

// Create an instance of R4HttpClient
R4HttpClient http;

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";  // CHANGE TO MQTT BROKER'S ADDRESS
const int MQTT_PORT = 1883;                               // CHANGE IT AS YOU DESIRE
const char MQTT_CLIENT_ID[] = "arduino-uno-r4-client";    // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                          // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                          // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "phycom";    // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "phycom";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  connectToWiFi();

  // Login Kerio
  http.begin(client, serverUrl, serverPort);
  login_kerio();

  connectToMQTT();
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
}

void login_kerio() {
  String payload = "kerio_username=iot&kerio_password=iot";  // Your POST data
  int responseCode = http.POST(payload);

  if (responseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(responseCode);
    String responseBody = http.getBody();
    Serial.println(responseBody);
  } else {
    Serial.print("Error making POST request: ");
    Serial.println(responseCode);  // Print the actual error code
  }
  http.close();  // Close the connection
}

// Function to connect to your WiFi network
void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Since there’s no password, pass only the SSID
  WiFi.begin(ssid);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi network");

  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void connectToMQTT() {
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
  mqtt.onMessage(messageHandler);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {
  // Check if there's data available to read from the Serial Monitor
  if (Serial.available() > 0) {
    // Read the input from the Serial Monitor as a string
    String val_str = Serial.readStringUntil('\n');

    // Convert the string to a char array for MQTT publishing
    char messageBuffer[10];
    val_str.toCharArray(messageBuffer, 10);

    // Publish the message to the MQTT topic
    mqtt.publish(PUBLISH_TOPIC, messageBuffer);

    // Print debug information to the Serial Monitor in one line
    Serial.println("Arduino UNO R4 - sent to MQTT: topic: " + String(PUBLISH_TOPIC) + " | payload: " + String(messageBuffer));
  }
}

void messageHandler(String& topic, String& payload) {
  Serial.println("Arduino UNO R4 - received from MQTT: topic: " + topic + " | payload: " + payload);

  // You can process the incoming data , then control something
  /*
  process something
  */
}

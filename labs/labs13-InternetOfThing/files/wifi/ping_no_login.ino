#include <WiFi.h>
#include <Ping.h>

// Your Wi-Fi credentials
const char* ssid = "ITFORGE_UFO";          // Replace with your Wi-Fi SSID
const char* password = "";  // Replace with your Wi-Fi password

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Ping google.com
  pingGoogle();
}

void loop() {
  // You can add more code here if needed
}

void pingGoogle() {
  Serial.print("Pinging google.com... ");

  // Ping google.com
  IPAddress ip;
  if (Ping.ping("google.com", ip)) {
    Serial.println("Success!");
    Serial.print("IP Address: ");
    Serial.println(ip);
  } else {
    Serial.println("Failed!");
  }
}

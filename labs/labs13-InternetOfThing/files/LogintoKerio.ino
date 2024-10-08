#include <WiFiS3.h>
#include <R4HttpClient.h>

// WiFi credentials
const char* ssid = "ITFORGE_UFO";  // Your SSID
const char* password = "";         // No password for open networks

// Server details (replace with your target server)
const char* serverUrl = "https://portal.it.kmitl.ac.th/internal/dologin.php";  // Your target URL
const int serverPort = 4081;                                                         // Port for the target URL (use 443 for HTTPS)

// Create an instance of WiFiSSLClient (for HTTPS, use WiFiClientSecure)
WiFiSSLClient client;

// Create an instance of R4HttpClient
R4HttpClient http;

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  connectToWiFi();

  // Initialize the R4HttpClient with the client and server details
  http.begin(client, serverUrl, serverPort);
}

void loop() {
  // Example POST request
  String payload = "kerio_username=maxhub+peer+tutor2&kerio_password=";  // Your POST data
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
  delay(5000);   // Wait for 5 seconds before next request
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
#include <WiFiS3.h>
#include <R4HttpClient.h>
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
uint32_t frame_off[3] = { 0, 0, 0 };
uint32_t frame_on[3] = { 0x0E011011, 0x01F01001, 0x800F0000 };

// WiFi credentials
const char* ssid = "ITFORGE_UFO";  // Your SSID
const char* password = "";         // No password for open networks

// Server details (replace with your target server)
const char* serverUrl = "https://portal.it.kmitl.ac.th/internal/dologin.php";  // Your target URL
const int serverPort = 4081;                                                   // Port for the target URL (use 443 for HTTPS)

// Create an instance of WiFiSSLClient (for HTTPS, use WiFiClientSecure)
WiFiSSLClient client;

// Create an instance of R4HttpClient
R4HttpClient http;

int led = LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  connectToWiFi();

  // Initialize the R4HttpClient with the client and server details
  http.begin(client, serverUrl, serverPort);
  login_kerio();

  server.begin();

  matrix.begin();
}

void loop() {
  WiFiClient client = server.available();  // listen for incoming clients

  if (client) {                    // if you get a client,
    Serial.println("new client");  // print a message out the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected()) {   // loop while the client's connected
      if (client.available()) {    // if there's bytes to read from the client,
        char c = client.read();    // read a byte, then
        Serial.write(c);           // print it out to the serial monitor
        if (c == '\n') {           // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<style>body{font-family:'Tahoma',sans-serif;}</style><body background='https://www.it.kmitl.ac.th/~pattarachai/PIC/BG/stone.gif'><p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p><p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p><div align='right'><img src='https://www.it.kmitl.ac.th/~pattarachai/PIC/ICON/emailspin.gif' alt='[MAIL]' border='0'><br>arduino<img src='https://www.it.kmitl.ac.th/~pattarachai/PIC/ICON/at_sign.gif'>it.kmitl.ac.th<br>Any problem with downloading, feel free to contact me.</div></body>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);  // GET /H turns the LED on
          matrix.loadFrame(frame_on);
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);  // GET /L turns the LED off
          matrix.loadFrame(frame_off);
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
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

void login_kerio() {
  // Example POST request
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
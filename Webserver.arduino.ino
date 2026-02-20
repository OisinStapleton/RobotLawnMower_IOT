#include <WiFi.h>
#include <WebServer.h>

// 🔹 CHANGE THESE TO YOUR WIFI DETAILS
const char* ssid = "OisinHotspot";
const char* password = "Oisin449";

// Create webserver on port 80
WebServer server(80);

// Dummy sensor function
float getDistance() {
  return 22.5;   // Replace later with real sensor value
}

// HTML parts
String homePagePart1 = R"=====( 
<!DOCTYPE html>
<html>
<head>
<title>ESP32 WebServer</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body { background-color: green; text-align: center; font-family: Arial; }
table { margin-left:auto; margin-right:auto; }
th, td { font-size: 25px; padding: 8px; border-bottom: 1px solid #ddd; }
</style>
</head>
<body>
<h1>Robot Lawnmower Website</h1>
<p>Live Distance Reading</p>

<table>
<tr>
<th>Sensor</th>
<th>Value</th>
<th>Unit</th>
</tr>

<tr>
<td>Distance</td>
<td>
)=====";

String homePagePart2 = R"=====( 
</td>
<td>cm</td>
</tr>
</table>
</body>
</html>
)=====";

// Handle root webpage
void handleRoot() {
  String message = homePagePart1 + String(getDistance()) + homePagePart2;
  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start webserver
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}

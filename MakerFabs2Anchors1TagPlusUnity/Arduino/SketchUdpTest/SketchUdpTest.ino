#include <WiFi.h>
#include  <WiFiUdp.h>
const char *ssid = "blackcrow_01";
const char *password = "8001017170";

const char* udpAddress = "192.168.50.224";  // Replace with your Unity  server IP
const int udpPort = 8080;

WiFiUDP udp;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    delay(1000);
    WiFi.begin(ssid, password);
    Serial.println("Connected to WiFi");
    delay(1000);
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Adress:");
    Serial.println(WiFi.macAddress());


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  if (WiFi.status() == WL_CONNECTED)
  {

    String payload = "{hola que tal}";
    udp.beginPacket(udpAddress, udpPort);
    udp.print(payload);
    udp.endPacket();
    Serial.println("Enviando");
  }
  else
  {
    Serial.println("WiFi not connected");
  }

}

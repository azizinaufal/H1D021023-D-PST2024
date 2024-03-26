#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266Wifi.h>

// const char *ap_ssid = "Internet Cepat Buat Apa";
// const char *ap_password = "qwedsazxc";

const char *sta_ssid = "Internet cepat buat apa";
const char *sta_password = "321qwedsa";

AsyncWebServer server(80);
String webpage;

int led1 = D6;
int led2 = D7;
int led3 = LED_BUILTIN;

int myFunction(int, int);

void setup()
{

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  delay(10);

  // setting mode access point
  // Serial.println("Configuring access point...");
  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ap_ssid, ap_password);
  // Serial.print("Wifi: ");
  // Serial.println(ap_ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  // setting mode station
  Serial.print("Connecting to ");
  Serial.println(sta_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid, sta_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Isi dari Webpage -------------------------------------------------------
  webpage += "<h1> Web Control ESP8266</h1>";
  webpage += "<p>LED 1: ";
  webpage += "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 2: ";
  webpage += "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 3: ";
  webpage += "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", webpage); });

  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led1, HIGH);
    request->send(200, "text/html", webpage); });

  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led2, HIGH);
    request->send(200, "text/html", webpage); });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led3, LOW);
    request->send(200, "text/html", webpage); });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led1, LOW);
    request->send(200, "text/html", webpage); });

  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led2, LOW);
    request->send(200, "text/html", webpage); });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    digitalWrite(led3, HIGH);
    request->send(200, "text/html", webpage); });

  server.begin();
}

void loop()
{
}

int myFunction(int x, int y)
{
  return x + y;
}
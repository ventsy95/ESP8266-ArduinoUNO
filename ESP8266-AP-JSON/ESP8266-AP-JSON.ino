/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h> 
/* Set these to your desired credentials. */
const char *ssid = "ESP8266";
const char *password = "p";
String command;
ESP8266WebServer server(80);
WiFiClient client = server.client();

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot(){
  String html ="<!DOCTYPE html> <html> </html>";
  server.send(200, "text/html", html);
  Serial.println("OK");
}
void moveLeft() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "LEFT";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void moveRight() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "RIGHT";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void moveForward() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "FORWARD";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void moveBack() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "BACK";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void wave() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "WAVE";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void duck() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "DUCK";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void ledOn() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "LEDON";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void ledOff() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "LEDOFF";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void goToStart() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  command = "6";
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += command;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  Serial.println(command);
}

void setup() {
  delay(500);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/left", moveLeft);
  server.on("/right", moveRight);
  server.on("/forward", moveForward);
  server.on("/back", moveBack);
  server.on("/duck", duck);
  server.on("/wave", wave);
  server.on("/ledOn", ledOn);
  server.on("/ledOff", ledOff);
  server.on("/goToStart", goToStart);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  if(!client){
    //delay(500);
    Serial.println("NO CLIENT");
    goToStart();
  }else{
    Serial.println("CLIENT CONNECTED");
  }
  //delay(1);
}

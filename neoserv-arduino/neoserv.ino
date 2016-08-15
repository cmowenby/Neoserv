#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>

#define PATTERN "pattern"
#define COLOR "color"
#define TEMPO "tempo"
#define MULTIPLIER "multiplier"

#define BUFFSIZE 64

BridgeServer server;
String patternStr;
String colorStr;
String tempoStr;
String multiplierStr;

void setup() {
  Serial.begin(9600);
  
  // Setting up the diagnostics LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Bridge.begin();
  digitalWrite(13, HIGH);
  server.listenOnLocalhost();
  server.begin();

  Bridge.put("status", "up");
}

void loop() {
  // put your main code here, to run repeatedly:
  BridgeClient client = server.accept();

  char inputBuffer[BUFFSIZE];

  // Getting pattern
  Bridge.get(PATTERN, inputBuffer, BUFFSIZE);
  patternStr = String(inputBuffer);

  // Getting color
  Bridge.get(COLOR, inputBuffer, BUFFSIZE);
  colorStr = String(inputBuffer);

  // Getting tempo
  Bridge.get(TEMPO, inputBuffer, BUFFSIZE);
  tempoStr = String(inputBuffer);

  // Getting multiplier
  Bridge.get(MULTIPLIER, inputBuffer, BUFFSIZE);
  multiplierStr = String(inputBuffer);

  if (patternStr != NULL)
    Serial.println("Pattern: " + patternStr);

   if (multiplierStr != NULL)
    Serial.println("Multiplier: " + multiplierStr);
}

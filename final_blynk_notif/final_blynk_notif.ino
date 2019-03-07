#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Authorization token from the Blynk App.
char auth[] = "060e37effea2467ab0825b69a0cd62fb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Prince 812";
char pass[] = "";
// Use Virtual pin 5 for uptime display
#define PIN_UPTIME V5
int outputpin= A0;
float celsius=0.0;


BLYNK_READ(PIN_UPTIME)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  Blynk.virtualWrite(PIN_UPTIME, celsius);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Blynk.run();
}


void loop() {
  int analogValue = analogRead(outputpin);
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  celsius = millivolts/10;
  Serial.print("in DegreeC=   ");
  Serial.println(celsius);
  delay(100);
  Blynk.run();
}

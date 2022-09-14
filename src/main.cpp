#include <Arduino.h>
#include <NCD2Relay.h>

NCD2Relay relay;

unsigned long interval = 3000;
unsigned long lastUpdate = 0;



void setup() {
  // put your setup code here, to run once:
  relay.setAddress(0,0,0);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() > interval+lastUpdate){
    lastUpdate = millis();
    int random = rand()%4;
    Serial.printf("random %i\n", random);
    relay.setBankStatus(random);
  }
}

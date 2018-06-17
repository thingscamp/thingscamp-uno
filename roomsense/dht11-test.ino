#include <dht.h>

dht DHT;

#define DHT11_PIN 7
const int analogInPin = A0; // analog pin LDR is attached to
const int analogOutPin = 9;

int sensorValue = 0; // value read from the LDR
int outputValue = 0; // value output to the PWM

void setup(){
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);
  Serial.print("Sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  if (DHT.humidity >=60) {
    digitalWrite(3, HIGH); // turn blue LED on if it gets too damp
    delay(400);
    digitalWrite(3, LOW); // clear the LED
  }
  delay(1000);
}


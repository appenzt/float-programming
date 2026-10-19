#include <Arduino.h>

const int depthsensorPin = 25;
const int lightsensorpin = 15;
const int lightresistorohm = 10000; 
const int thermistorpin = 26;
const int thermistorresistorohm = 10000;

void setup() {

    Serial.begin(9600);
}


void loop() {
    // 
    int rawThermistorValue = analogRead(thermistorpin);
    float ThermistorVoltage = (rawThermistorValue / 4095.0);

    // Calculate the light sensor voltage, current, and lux level
    int rawlightValue = analogRead(lightsensorpin);
    float lightSensorVoltage = (rawlightValue / 4095.0) * 3.3;
    float lightSensorAmps = lightSensorVoltage / lightresistorohm;
    float lightSensorMicroAmps = lightSensorAmps * 1e6;
    float luxlevel = lightSensorMicroAmps / 3.5; 

    //Calculate the depth sensor voltage, convert to pressure and depth
    int rawValue = analogRead(depthsensorPin);
    float sensorVoltage = (rawValue / 4095.0) * 3.3;
    float pressurePSI = ((sensorVoltage - 0.5) / 4.0) * 10.0;
    if (pressurePSI < 0) {
        pressurePSI = 0;
    }
    float pressurePa = pressurePSI * 6894.76;
    float depth = pressurePa / (1000.0 * 9.81);


    Serial.print(" V | Pressure: ");

    Serial.print(pressurePSI, 3);

    Serial.print("Depth: ");

    Serial.print(depth, 3);

    Serial.println(" m");

    delay(500);
}
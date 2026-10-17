#include <Arduino.h>

const int sensorPin = 25;


void setup() {

    Serial.begin(9600);
}


void loop() {
    int rawValue = analogRead(sensorPin);

    float adcVoltage = (rawValue / 4095.0) * 3.3;

    float sensorVoltage = adcVoltage * 1.5;

    float pressurePSI = ((sensorVoltage - 0.5) / 4.0) * 10.0;

    if (pressurePSI < 0) {
        pressurePSI = 0;
    }

    float pressurePa = pressurePSI * 6894.76;

    float depth = pressurePa / (1000.0 * 9.81);

    Serial.print("Sensor voltage: ");

    Serial.print(sensorVoltage, 3);

    Serial.print(" V | Pressure: ");

    Serial.print(pressurePSI, 3);

    Serial.print(" PSI | Depth: ");

    Serial.print(depth, 3);

    Serial.println(" m");

    delay(500);
}
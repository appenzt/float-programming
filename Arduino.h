#pragma once

#include <stdint.h>
#include <stddef.h>

#define HIGH 1
#define LOW 0

#define INPUT 0x00
#define OUTPUT 0x01
#define INPUT_PULLUP 0x02

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7
#define A8 8
#define A9 9
#define A10 10
#define A11 11
#define A12 12
#define A13 13
#define A14 14
#define A15 15

#define LED_BUILTIN 2

class HardwareSerial {
public:
    void begin(unsigned long baud) { (void)baud; }
    void print(const char* text) { (void)text; }
    void print(char c) { (void)c; }
    void print(int value, int format = DEC) { (void)value; (void)format; }
    void print(unsigned int value, int format = DEC) { (void)value; (void)format; }
    void print(long value, int format = DEC) { (void)value; (void)format; }
    void print(unsigned long value, int format = DEC) { (void)value; (void)format; }
    void print(float value, int precision = 2) { (void)value; (void)precision; }
    void print(double value, int precision = 2) { (void)value; (void)precision; }

    void println(const char* text = "") { (void)text; }
    void println(char c) { (void)c; }
    void println(int value, int format = DEC) { (void)value; (void)format; }
    void println(unsigned int value, int format = DEC) { (void)value; (void)format; }
    void println(long value, int format = DEC) { (void)value; (void)format; }
    void println(unsigned long value, int format = DEC) { (void)value; (void)format; }
    void println(float value, int precision = 2) { (void)value; (void)precision; }
    void println(double value, int precision = 2) { (void)value; (void)precision; }
    void println() {}
};

inline HardwareSerial Serial;

inline void pinMode(int pin, int mode) { (void)pin; (void)mode; }
inline void digitalWrite(int pin, int value) { (void)pin; (void)value; }
inline int digitalRead(int pin) { (void)pin; return 0; }
inline int analogRead(int pin) { (void)pin; return 0; }
inline void analogWrite(int pin, int value) { (void)pin; (void)value; }
inline void delay(unsigned long ms) { (void)ms; }
inline unsigned long millis() { return 0; }
inline unsigned long micros() { return 0; }
inline void tone(int pin, unsigned int frequency, unsigned long duration = 0) {
    (void)pin;
    (void)frequency;
    (void)duration;
}
inline void noTone(int pin) { (void)pin; }
inline void yield() {}

using byte = uint8_t;

typedef unsigned int word;

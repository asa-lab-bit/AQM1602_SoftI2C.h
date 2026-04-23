#ifndef AQM1602_SOFTI2C_H
#define AQM1602_SOFTI2C_H

#include <Arduino.h>
#include <SoftI2C_VPORT.h>

class AQM1602 {
  public:
    AQM1602(SoftI2C_VPORT& i2c);

    void begin(uint8_t contrast = 0x72, uint8_t power = 0x52);
    void clear();
    void setCursor(uint8_t col, uint8_t row);

    void print(const char* text);
    void print(int value);
    void printAt(uint8_t col, uint8_t row, const char* text);
　　void printAt(uint8_t col, uint8_t row, int value);
  private:
    SoftI2C_VPORT& _i2c;

    void sendCommand(uint8_t cmd);
    void sendData(uint8_t data);
};

#endif

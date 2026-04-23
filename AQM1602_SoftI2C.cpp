#include "AQM1602_SoftI2C.h"

#define AQM1602_ADDR 0x3E

AQM1602::AQM1602(SoftI2C_VPORT& i2c) : _i2c(i2c) {}

void AQM1602::begin(uint8_t contrast, uint8_t power) {
  _i2c.begin();
  delay(50);

  sendCommand(0x38);
  delay(20);
  sendCommand(0x39);
  delay(20);
  sendCommand(0x14);
  delay(20);
  sendCommand(contrast);
  delay(20);
  sendCommand(power);
  delay(20);
  sendCommand(0x6C);
  delay(20);
  sendCommand(0x38);
  delay(20);
  sendCommand(0x0C);
  delay(20);
  sendCommand(0x01);
  delay(4);
}

void AQM1602::clear() {
  sendCommand(0x01);
  delay(2);
}

void AQM1602::setCursor(uint8_t col, uint8_t row) {
  if (row == 0) {
    sendCommand(0x80 + col);
  } else {
    sendCommand(0xC0 + col);
  }
}

void AQM1602::print(const char* text) {
  _i2c.start();
  _i2c.write(AQM1602_ADDR << 1);
  _i2c.write(0x40);

  while (*text) {
    _i2c.write(*text++);
  }

  _i2c.stop();
}

void AQM1602::print(int value) {
  if (value == 0) {
    sendData('0');
    return;
  }

  if (value < 0) {
    sendData('-');
    value = -value;
  }

  char buf[6];
  uint8_t i = 0;

  while (value > 0) {
    buf[i++] = (value % 10) + '0';
    value /= 10;
  }

  while (i--) {
    sendData(buf[i]);
  }
}

void AQM1602::printAt(uint8_t col, uint8_t row, const char* text) {
  setCursor(col, row);
  print(text);
}
void AQM1602::printAt(uint8_t col, uint8_t row, int value) {
  setCursor(col, row);
  print(value);
}

void AQM1602::sendCommand(uint8_t cmd) {
  _i2c.start();
  _i2c.write(AQM1602_ADDR << 1);
  _i2c.write(0x00);
  _i2c.write(cmd);
  _i2c.stop();
}

void AQM1602::sendData(uint8_t data) {
  _i2c.start();
  _i2c.write(AQM1602_ADDR << 1);
  _i2c.write(0x40);
  _i2c.write(data);
  _i2c.stop();
}

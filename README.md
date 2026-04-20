# AQM1602_SoftI2C

Lightweight AQM1602 LCD library using SoftI2C (no Wire required).  
Designed for small microcontrollers like ATtiny.

---

## ✨ Features

- No Wire library (lightweight)
- Works with SoftI2C (any GPIO pins)
- Suitable for ATtiny series
- Simple API
- Contrast adjustable

---

## 🚀 Usage

```cpp
#include <SoftI2C_VPORT.h>
#include "AQM1602_SoftI2C.h"

SoftI2C_VPORT i2c(PORTA, 1, 2);
AQM1602 lcd(i2c);

void setup() {
  lcd.begin(0x72, 0x52);

  lcd.printAt(0, 0, "Hello");
  lcd.printAt(0, 1, "ATtiny");
}

void loop() {
}
⚙️ Functions
begin(contrast, power) : initialize LCD
clear() : clear display
setCursor(col, row) : set cursor
print(text) : print string
print(int) : print number
printAt(col, row, text) : position + print
🔧 Contrast Adjustment
lcd.begin(0x60, 0x52); // lighter
lcd.begin(0x72, 0x52); // default
lcd.begin(0x7F, 0x52); // darker
📦 Installation
Download ZIP from GitHub
Arduino IDE → Sketch → Include Library → Add .ZIP Library
Open examples → Basic
📄 License

MIT

---

# ■ ② LICENSE（MIT）を確認

もし無ければ👇

👉 「Add file」→「Create new file」

```plaintext
LICENSE

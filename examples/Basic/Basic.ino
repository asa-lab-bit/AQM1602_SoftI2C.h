#include <SoftI2C_VPORT.h>
#include <AQM1602_SoftI2C.h>

// ★ I2Cをここで作る
SoftI2C_VPORT i2c(1, 2);  //使用するPinを設定する SDA=PA1, SCL=PA2  

// ★ 渡す
AQM1602 lcd(i2c);

void setup() {
  lcd.begin(0x73, 0x56);  //コントラスト設定  電圧設定3.3V向け
  int aa= -23;
  lcd.printAt(2, 0, "Hello");
  lcd.printAt(8, 0, "Hello");
  lcd.setCursor(0,1);
  lcd.print(aa);
  lcd.print(" abcdef");
}

void loop() {
}

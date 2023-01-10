#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <INA226_WE.h>
#define I2C_ADDRESS 0x40

INA226_WE ina226(I2C_ADDRESS);
// INA226_WE ina226 = INA226_WE(); // Alternative: sets default address 0x40

void setup() {
  Serial.begin(9600);
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  Wire.begin();
  // default parameters are set - for change check the other examples
  ina226.init();
  Serial.println("INA226 Current Sensor Example Sketch - PowerDown");
  Serial.println("Continuous Sampling starts");
  Serial.println();
}

void loop() {
  for(int i=0; i<5; i++){
    continuousSampling();
    delay(3000);
  }
  
  Serial.println("Power down for 7s");
  ina226.powerDown();
  for(int i=0; i<7; i++){
    Serial.print(".");
    delay(1000);
  }
  
  Serial.println("Power up!");
  Serial.println("");
  ina226.powerUp();
}

void continuousSampling(){
  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0; 
  float res=0.0;
  float pes=0.0;

  ina226.readAndClearFlags();
  shuntVoltage_mV = ina226.getShuntVoltage_mV();
  busVoltage_V = ina226.getBusVoltage_V();
  current_mA = ina226.getCurrent_mA();
  power_mW = ina226.getBusPower();
  loadVoltage_V  = busVoltage_V + (shuntVoltage_mV/1000);
  
  Serial.print("Shunt Voltage [mV]: "); Serial.println(shuntVoltage_mV);
  Serial.print("Bus Voltage [V]: "); Serial.println(busVoltage_V);
  lcd.setCursor ( 0 , 0);lcd.print("Voltage:");lcd.print(busVoltage_V);
  Serial.print("Load Voltage [V]: "); Serial.println(loadVoltage_V);
  Serial.print("Current[mA]: "); Serial.println(current_mA);
  res= busVoltage_V /0.07;
  pes=res*10;
  lcd.setCursor ( 0 , 1);lcd.print("Percentage:");lcd.print(pes);lcd.print("%");
  Serial.print("Bus Power [mW]: "); Serial.println(power_mW);
  if(!ina226.overflow){
    Serial.println("Values OK - no overflow");
  }
  else{
    Serial.println("Overflow! Choose higher current range");
  }
  Serial.println();
}

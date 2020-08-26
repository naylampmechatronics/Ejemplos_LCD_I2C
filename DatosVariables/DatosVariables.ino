/****************************************************************************************
 Datos y Variables
 
  En este ejemplo mostramos variables en un LCD , que pueden representar valores de sensores u otros datos. 
  Para simular los sensores se pueden usar potenciómetros conectados a los pines analógicos. 

 Conexiones:
  ------------------------------------------------------------------------
  M.LCD_I2C-> Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ------------------------------------------------------------------------
  GND      ->   GND                 |   GND            |   GND
  VCC      ->   5V                  |   5V             |   5V
  SDA      ->   A4                  |   20             |   2 
  SCL      ->   A5                  |   21             |   3
  ------------------------------------------------------------------------
  Sensor1(pot1) ->  A0
  Sensor2(pot2) ->  A1 
  Sensor3(pot3) ->  A2  
  ------------------------------------------------------------------------
  
  *No se puede cambiar de pines para el LCD_I2C, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente
  *Puede usar potenciómetros para simular sensores analógicos

 Dirección del módulo I2C
  a)Por defecto 0x3F (00111111) o seleccionar por hardware : 0|0|1|1|1|A2|A1|A0 
  b)Por defecto 0x27 (00100111) o seleccionar por hardware : 0|0|1|0|0|A2|A1|A0
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 25/08/2020

 Más información en:
   -https://naylampmechatronics.com/blog/35_Tutorial--LCD-con-I2C-controla-un-LCD-con-so.html
   -https://github.com/naylampmechatronics/Ejemplos_LCD_I2C

**************************************************************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  // 
//LiquidCrystal_I2C lcd(0x3F,16,2);  //Para dirección 0x3F 

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
}

void loop() {
  int sen1=analogRead(A0);
  float sen2=analogRead(A1)*(5.0 / 1023.0);
  float sen3=analogRead(A2)*(100.0 / 1023.0);
  int tiempo=millis()/1000;
  // Cursor en la primera posición de la primera fila
  lcd.setCursor(0,0);
  lcd.print("ADC:");
  lcd.print(sen1);
  lcd.print("   ");
  // Cursor en la 11° posición de la primera fila
  lcd.setCursor(10,0);
  lcd.print("V:");
  lcd.print(sen2,1);//1 decimal
  lcd.print("V  ");
  // Cursor en la primera posición de la 2° fila
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.print(sen3,1); //1 decimal
  lcd.print("\337C  "); // "337" -> "°"
  // Cursor en la 11° posición de la 2° fila
  lcd.setCursor(10,1);
  lcd.print("t:");
  lcd.print(tiempo);
  lcd.print(" s  ");
  
  delay(200);
  
}

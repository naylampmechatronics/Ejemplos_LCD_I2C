/****************************************************************************************
 Hola Mundo
 
  Programa para testear el funcionamiento de un LCD1602 o LCD2004 usando un adaptador I2C para LCD

 Conexiones:
  ------------------------------------------------------------------------
  M.LCD_I2C-> Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ------------------------------------------------------------------------
  GND      ->   GND                 |   GND            |   GND
  VCC      ->   5V                  |   5V             |   5V
  SDA      ->   A4                  |   20             |   2 
  SCL      ->   A5                  |   21             |   3
  ------------------------------------------------------------------------
  
  *No se puede cambiar de pines, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente

 Dirección del módulo I2C
  a)Por defecto 0x3F (00111111) o seleccionar por hardware : 0|0|1|1|1|A2|A1|A0 
  b)Por defecto 0x27 (00100111) o seleccionar por hardware : 0|0|1|0|0|A2|A1|A0
 
 Programa basado en el ejemplo HelloWord de la librería LiquidCrystal y LiquidCrystal_I2C
 
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
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("Hola Mundo");
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}

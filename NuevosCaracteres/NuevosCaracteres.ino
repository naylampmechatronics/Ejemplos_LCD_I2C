/****************************************************************************************
 Nuevos Caracteres 
 
  En este ejemplo agregaremos caracteres personalizados en nuestro LCD

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

//---Nuevos caracteres------------------
byte N[8] = {
B11111,
B10001,
B10001,
B10001,
B10001,
B10001,
B10001,
B00000,
};
byte A[8] = {
B11111,
B10001,
B10001,
B10001,
B10001,
B11111,
B10001,
B00000,
};
byte Y[8] = {
B10001,
B10001,
B10001,
B10001,
B11111,
B00100,
B00100,
B00000,
};
byte L[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B11111,
B00000,
};
byte M[8] = {
B11111,
B10101,
B10101,
B10101,
B10101,
B10101,
B10101,
B00000,
};
byte P[8] = {
B11111,
B10001,
B10001,
B10001,
B11111,
B10000,
B10000,
B00000,
};
byte cara[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000,
};
byte cuerpo[8] = {
B01110,
B01110,
B00100,
B11111,
B00100,
B01010,
B10001,
B00000,
};
//---------------------------

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  //creamos los nuevos caracteres
  lcd.createChar (0,N);
  lcd.createChar (1,A);
  lcd.createChar (2,Y);
  lcd.createChar (3,L);
  lcd.createChar (4,M);
  lcd.createChar (5,P);
  lcd.createChar (6,cara);
  lcd.createChar (7,cuerpo);
 // Escribimos el texto en el LCD
  lcd.setCursor(0, 0); 
  lcd.print("Tutorial LCD_I2C");
  lcd.setCursor(0, 1);
  lcd.write (byte (7));
  lcd.print(" ");
  lcd.write (byte (6));
  lcd.print(" ");
  lcd.write (byte (0));
  lcd.write (byte (1));
  lcd.write (byte (2));
  lcd.write (byte (3));
  lcd.write (byte (1));
  lcd.write (byte (4));
  lcd.write (byte (5));
  lcd.print(" ");
  lcd.write (byte (6));
  lcd.print(" ");
  lcd.write (byte (7));
  

  
}

void loop () {}

# Ejemplos_LCD_I2C
Ejemplos para controlar un LCD con un módulo adaptador LCD a I2C

![Módulo adaptador LCD a I2C](https://naylampmechatronics.com/700-large_default/modulo-adaptador-lcd-a-i2c.jpg)

Información detallada de los ejemplos en: [Tutorial módulo adaptador LCD a I2C](https://naylampmechatronics.com/blog/35_Tutorial--LCD-con-I2C-controla-un-LCD-con-so.html)

## Contenido
* **HolaMundo:** Programa para testear el funcionamiento de un LCD1602 o LCD2004 con un módulo adaptador LCD a I2C
* **Desplazamiento:** Permite desplazar el texto del LCD a la derecha o izquierda..
* **DatosVariables:** Para mostrar variables en el LCD, que pueden representar valores de sensores u otros datos.
* **NuevosCaracteres:** En este ejemplo agregaremos caracteres personalizados a un LCD.
 
## Requerimientos
 **Software**
  * IDE Arduino
  * Librería  [Wire](https://www.arduino.cc/en/Reference/Wire) (Ya viene instalada en Arduino)
  * Librería  [LiquidCrystal_I2C](https://gitlab.com/tandembyte/LCD_I2C)
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * [Módulo adaptador LCD a I2C](https://naylampmechatronics.com/displays/60-modulo-adaptador-lcd-a-i2c.html) 
  * [LCD1602](https://naylampmechatronics.com/displays/110-display-lcd1602-azul-backlight.html) o [LCD2004](https://naylampmechatronics.com/displays/158-display-lcd-2004-azul-backlight.html)
  
## Conexiones
  
  Módulo LCD_I2C | Arduino Uno, Nano, Mini | Arduino Mega, DUE | Arduino Leonardo
  ----------|-----------------------|------------------|---------------------
  GND      |   GND                 |   GND            |   GND
  VCC      |   5V                  |   5V             |   5V
  SDA      |   A4                  |   20             |   2 
  SCL      |   A5                  |   21             |   3
   
No se puede cambiar de pines, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente

## Dirección del módulo I2C
Comúnmente encontramos módulos con las siguientes direcciones:
  * Por defecto 0x3F (00111111) o seleccionar por hardware : 0|0|1|1|1|A2|A1|A0 
  * Por defecto 0x27 (00100111) o seleccionar por hardware : 0|0|1|0|0|A2|A1|A0

## Licencia
Los ejemplos son Open Source, desarrollados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial Módulo adaptador LCD a I2C](https://naylampmechatronics.com/blog/35_Tutorial--LCD-con-I2C-controla-un-LCD-con-so.html)
 * [Módulo adaptador LCD a I2C](https://naylampmechatronics.com/displays/60-modulo-adaptador-lcd-a-i2c.html)
 * [Display Alfanumérico LCD 1602](https://naylampmechatronics.com/displays/110-display-lcd1602-azul-backlight.html)
 * [Librería LiquidCrystal_I2C](https://gitlab.com/tandembyte/LCD_I2C)

/* 
How to Calibrate Your Scale
https://www.instructables.com/id/How-to-Interface-HX711-Balance-Module-With-Load-Ce/
 */

#include "HX711.h"

HX711 bilancia(2, 3);

void setup() {
  Serial.begin(9600);
 
  bilancia.set_scale();
  bilancia.tare();

  Serial.println("premi");
  while (!Serial.available()) {}

  float peso_in_uscita = bilancia.get_units(20);
  float peso = 120.0f;  
  float parametro_di_calibrazione = peso_in_uscita / peso;
  
  Serial.print("parametro_di_calibrazione: ");
  Serial.println(parametro_di_calibrazione);                 
}

void loop() {
  
}

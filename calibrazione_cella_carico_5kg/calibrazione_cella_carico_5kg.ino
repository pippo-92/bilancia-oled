#include "HX711.h"

HX711 bilancia(2, 3);

float parametro_di_calibrazione = -403; // this calibration factor is adjusted according to my load cell
float peso;


void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");

  bilancia.set_scale();
  bilancia.tare();  
}

void loop() {
  bilancia.set_scale(parametro_di_calibrazione); 

  Serial.print("lettura: ");
  peso = bilancia.get_units(); 
  if (peso < 0) {
    peso = 0.00;
  }
  Serial.print(peso);
  Serial.print(" g."); 
  Serial.print(" parametro_di_calibrazione: ");
  Serial.print(parametro_di_calibrazione);
  Serial.println();

  if(Serial.available()) {
    char par = Serial.read();
    if (par == 'u') {
      parametro_di_calibrazione += 1;
    } else if(par == 'd') {
      parametro_di_calibrazione -= 1;
    }
  }
}

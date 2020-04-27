#include "HX711.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, 4);

HX711 bilancia(2, 3);

float parametro_di_calibrazione = -410; // this calibration factor is adjusted according to my load cell
float peso;

int x = 0;
int y = 0;
void setup() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while(true);
  }
  display.display();
  display.clearDisplay();

  Serial.begin(9600);

  bilancia.set_scale();
  bilancia.tare();  //Reset the scale to 0  
}

void loop() {
  bilancia.set_scale(parametro_di_calibrazione); 
  peso = bilancia.get_units(); 
  if (peso < 0) {
    peso = 0.00;
  }
  display.clearDisplay();
  display.setTextSize(3);//dimensione del testo da scrivere
  display.setTextColor(WHITE);//colore del testo da scrivereù
  display.setCursor(x,y);//coordinate del cursore iniziale 
  display.print(peso);
  display.display();
}

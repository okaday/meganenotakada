#define trigPin 2
#define echoPin 3

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(29, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 100){
     colorWipe(strip.Color(0, 0, 255), 1); // BLUE
     

  }
  else {
  if (distance <=200 ){
    colorWipe(strip.Color(255, 0, 0), 1); // RED
    colorWipe(strip.Color(0, 0, 255), 1); // BLUE
  }
  else {
    colorWipe(strip.Color(255, 0, 0), 1); // RED
    colorWipe(strip.Color(255, 0, 0), 1); // RED
    colorWipe(strip.Color(255, 0, 0), 1); // RED
    colorWipe(strip.Color(0, 0, 255), 1); // BLUE
    colorWipe(strip.Color(0, 0, 255), 1); // BLUE
   colorWipe(strip.Color(0, 0, 255), 1); // BLUE 
   } 
 }  
  delay(500);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}


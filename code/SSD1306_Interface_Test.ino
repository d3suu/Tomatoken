#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  pinMode(A0, INPUT);
  // Clear the buffer
  display.clearDisplay();

  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  
}

int bar = 0;
int reading_a, reading_b = 0;

void loop() {
  bar = 0;
  display.clearDisplay();
  char text[20] = " ";
  display.setCursor(30, 0);
  
  
  sprintf(text, "%d%d", reading_a, reading_b);
  for(int i = 0; i<20; i++){
    display.write(text[i]);
  };

  display.drawRect(0, 24, 120, 7, WHITE);
  
  while(bar<120){
    display.fillRect(0, 25, bar, 5 /*display.height()-2*1*/, WHITE);
    bar+=12;
    display.display();
    if(bar<60){
      reading_b = analogRead(A0);
    }else if(bar>60){
      reading_a = analogRead(A0);
    }
    delay(1000);
  }

  display.display();
}

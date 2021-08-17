#include "DisplayManager.h"

#include "SPI.h"
#include "Wire.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET -1

DisplayManager::DisplayManager (HardwareSerial * serial) {
    this->serial_ref = serial; 
}

DisplayManager::~DisplayManager () {

}

bool DisplayManager::connectDisplay() {
    serial_ref->println("Connecting Display ....");
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    this->display_ref = &display;
    if(!this->display_ref->begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        serial_ref->println(F("SSD1306 allocation failed"));
        //for(;;); // Don't proceed, loop forever
        return false;
    }

    this->display_ref->display();

    delay(200); // Pause for 2 seconds

    // Clear the buffer
    this->display_ref->clearDisplay();

    delay(200);

    this->display_ref->setTextSize(1);             // Normal 1:1 pixel scale
    this->display_ref->setTextColor(SSD1306_WHITE);        // Draw white text
    this->display_ref->setCursor(0,0);             // Start at top-left corner
    this->display_ref->println(F("Display Initialized\n"));

    this->display_ref->display();
    
    return true;
}

bool DisplayManager::printStuff () {
    return true;
}
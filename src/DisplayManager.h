#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include "SPI.h"
#include "Wire.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
    private:
        HardwareSerial * serial_ref = nullptr;
        Adafruit_SSD1306 * display_ref = nullptr;

    public:
        DisplayManager(HardwareSerial * serial); 
        ~DisplayManager();
        bool printStuff();
        bool connectDisplay();
};

#endif
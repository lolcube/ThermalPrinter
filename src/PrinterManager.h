#ifndef PRINTER_MANAGER_H
#define PRINTER_MANAGER_H

#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

class PrinterManager {
    public:
        HardwareSerial * hwSerial;
        Adafruit_Thermal * printer;
        SoftwareSerial * softSerial;
    public:
        PrinterManager(HardwareSerial * Serial);
        ~PrinterManager(){};
        bool connectPrinter();
        void testPrint();
};

#endif
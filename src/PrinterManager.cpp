#include "PrinterManager.h"

#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN D3
#define RX_PIN D4


PrinterManager::PrinterManager(HardwareSerial * Serial) {
    this->hwSerial = Serial;
}

bool PrinterManager::connectPrinter() {


    SoftwareSerial sSerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
    softSerial = &sSerial;
    Adafruit_Thermal Printer(softSerial);

    softSerial->begin(9600);
    
    printer = &Printer;

    printer->begin();

    hwSerial->println("\nConnecting Printer...\n");

    printer->justify('C');
    printer->println(F("Center justified 1"));
    printer->println("\n\n");

    return true;
}

void PrinterManager::testPrint() {

    this->hwSerial->println("\nTest Printer...\n");
    //this->printer->begin();
    printer->justify('C');
    printer->println(F("Center justified 2"));
    printer->println("\n\n");
    
    this->hwSerial->println("\nFinished Test Printer...\n");

}

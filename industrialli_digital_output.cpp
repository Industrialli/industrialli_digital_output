#include "industrialli_digital_output.h"

void industrialli_digital_output::begin(){
    pinMode(SPI4_NSS_PE4, OUTPUT);
    pinMode(ISO_DIS_PE3, OUTPUT);
    pinMode(IC1_ISO_DIAG_PC0, INPUT);
    pinMode(IC2_ISO_DIAG_PC1, INPUT);
    digitalWrite(ISO_DIS_PE3, LOW);

    spi = new SPIClass;
    spi->setMISO(SPI4_MISO_PE5);
    spi->setMOSI(SPI4_MOSI_PE6);
    spi->setSCLK(SPI4_SCK_PE2);
    spi->begin();

    digital_outputs = 0;
}

void industrialli_digital_output::enable(){
    digitalWrite(ISO_DIS_PE3, HIGH);
}

void industrialli_digital_output::disable(){
    digitalWrite(ISO_DIS_PE3, LOW);
}


void industrialli_digital_output::update(){
    spi->beginTransaction(SPISettings(20000000UL, MSBFIRST, SPI_MODE3));

    digitalWrite(SPI4_NSS_PE4, LOW);
    spi->transfer(digital_outputs >> 8);
    spi->transfer(digital_outputs & 0xFF);
    digitalWrite(SPI4_NSS_PE4, HIGH);
    
    spi->endTransaction();

    ledsCtrl.ledsUpdate();
    
    digital_outputs = 0;
}

void industrialli_digital_output::write(uint8_t _output, bool _value){
    if(_value){
        digital_outputs |= 0x01 << (_output - 1);
    }else {
        digital_outputs &= ~(0x01 << (_output - 1));
    }

    set_digital_output_led(_output - 1, _value);
}

void industrialli_digital_output::set_digital_output_led(uint8_t _led, bool _value){
    if(_led < 8){
        if (_value){
            ledsCtrl.ledOn(_led + 12);
        
        }else{
            ledsCtrl.ledOn(_led + 12);
        }
    }else {
        if (_value){
            ledsCtrl.ledOn(_led + 16);
        
        }else{
            ledsCtrl.ledOn(_led + 16);
        }
    }
}

void industrialli_digital_output::update_power_leds_status(){
    if (digitalRead(IC1_ISO_DIAG_PC0)){
        ledsCtrl.ledOn(22);
    }else{
        ledsCtrl.ledOff(22);
    }

    if (digitalRead(IC2_ISO_DIAG_PC1)){
        ledsCtrl.ledOn(23);
    }else{
        ledsCtrl.ledOff(23);
    }
}

bool industrialli_digital_output::output_1_to_8_status(){
    return digitalRead(IC1_ISO_DIAG_PC0);
}

bool industrialli_digital_output::output_9_to_16_status(){
    return digitalRead(IC2_ISO_DIAG_PC1);
}


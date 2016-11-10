#include "IRLed.hpp"


IRLed::IRLed(target::d2_36kHz & diode): 
	diode(diode)
{}



void IRLed::on() {
	diode.set(1);
}

void IRLed::off() {
	diode.set(0);
}




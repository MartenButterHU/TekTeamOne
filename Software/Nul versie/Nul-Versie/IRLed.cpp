#include "IRLed.hpp"
namespace IR{
	

IRLed::IRLed(d2_36kHz & diode) : diode(diode)
{}



void IRLed::on(){	diode.set(0);	}

void IRLed::off(){	diode.set(1);	}

}
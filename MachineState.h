#ifndef MACHINE_STATE_H
#define MACHINE_STATE_H

#include <PinButton.h>
#include "constants.h"

PinButton enc(PIN_ENC_BTN);

class MachineState
{
	public:
		void update(){}
};

#endif
#ifndef MUX_CONTROL_H
#define MUX_CONTROL_H

#include "constants.h"
class FXArcade;

class MuxControl
{
	public:
		MuxControl(FXArcade &_owner);
		
	private:
		void setPath(byte path);
		FXArcade &owner;
	
};

#endif

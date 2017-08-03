#ifndef ARCADE_BUTTONS_H
#define ARCADE_BUTTONS_H

#include "constants.h"

class FXArcade;

class ArcadeButtons
{
	public:
		ArcadeButtons (FXArcade &_owner);
		void update();
		void init() {}

	private:
		FXArcade &owner;
};

#endif
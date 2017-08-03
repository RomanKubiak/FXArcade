#ifndef FX_ARCADE_H
#define FX_ARCADE_H

#include "constants.h"
#include "ArcadeButtons.h"
#include "ArcadeLights.h"

class FXArcade
{
	public:
		FXArcade();
		void update();
		void init();
		void buttonSingleClicked(const int buttonNum);
		void buttonDoubleClicked(const int buttonNum);
		void buttonClicked(const int buttonNum);
		void addButtonListener(ButtonListener *listenerToAdd);
		void removeButtonListener(ButtonListener *listenerToRemove);
	private:
		ArcadeButtons arcadeButtons;
		ArcadeLights arcadeLights;
		ButtonListener *buttonListeners[_LISTENERS];
};
#endif
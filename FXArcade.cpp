#include "FXArcade.h"

FXArcade::FXArcade() 
	: 	arcadeButtons(*this),
		arcadeLights(*this),
		buttonListeners{nullptr}
{
	pinMode(PIN_ADDR_A1, OUTPUT);
	pinMode(PIN_ADDR_A0, OUTPUT);
	pinMode(PIN_ENABLE, OUTPUT);
	pinMode(PIN_POT_IN, INPUT);
	pinMode(PIN_SYNC_IN, INPUT);
	digitalWrite(PIN_ENABLE, HIGH);
}

void FXArcade::init()
{
	DBG("init\n");
	arcadeButtons.init();
	arcadeLights.init();
}

void FXArcade::update()
{
	arcadeButtons.update();
}

void FXArcade::buttonSingleClicked(const int buttonNum)
{
	DBG("FXArcade::buttonSingleClicked: %d\n", buttonNum);
	for (int i=0; i<_LISTENERS; i++)
	{
		if (buttonListeners[i] != nullptr)
			buttonListeners[i]->buttonSingleClicked(buttonNum);
	}
}

void FXArcade::buttonClicked(const int buttonNum)
{
	DBG("FXArcade::buttonClicked: %d\n", buttonNum);
	for (int i=0; i<_LISTENERS; i++)
	{
		if (buttonListeners[i] != nullptr)
			buttonListeners[i]->buttonClicked(buttonNum);
	}
}

void FXArcade::buttonDoubleClicked(const int buttonNum)
{
	DBG("FXArcade::buttonDoubleClicked: %d\n", buttonNum);
	for (int i=0; i<_LISTENERS; i++)
	{
		if (buttonListeners[i] != nullptr)
			buttonListeners[i]->buttonDoubleClicked(buttonNum);
	}
}

void FXArcade::addButtonListener(ButtonListener *listenerToAdd)
{
	for (int i=0; i<_LISTENERS; i++)
	{
		if (buttonListeners[i] == nullptr)
		{
			DBG("FXArcade::addButtonListener: added at position %d\n", i);
			buttonListeners[i] = listenerToAdd;
			return;
		}
	}
}

void FXArcade::removeButtonListener(ButtonListener *listenerToRemove)
{
	for (int i=0; i<_LISTENERS; i++)
	{
		if (buttonListeners[i] == listenerToRemove)
		{
			buttonListeners[i] = nullptr;
			return;
		}
	}
}
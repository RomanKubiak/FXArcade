#ifndef ARCADE_LIGHTS_H
#define ARCADE_LIGHTS_H

#include "constants.h"

class FXArcade;

class ArcadeLight
{
	public:
		ArcadeLight(int _pin, bool _state, bool _invertedLogic=false) 
			: 	pin(_pin), 
				state(_state), 
				invertedLogic(_invertedLogic),
				blinkInterval(150)
		{
			pinMode(pin, OUTPUT);
			setState(state);
		}

		void setState(const bool _state=true)
		{
			digitalWrite(pin, invertedLogic ? !_state : _state);
			state = _state; 
		}

		void toggle()
		{
			setState(!state); 
		}

		void blink(const int _blinkInterval);

	private:
		int pin;
		bool state;
		bool invertedLogic;
		int blinkInterval;
};

static ArcadeLight red1Led(PIN_LED_RED1, false);
static ArcadeLight red2Led(PIN_LED_RED2, false);
static ArcadeLight grn1Led(PIN_LED_GREEN1, false);
static ArcadeLight grn2Led(PIN_LED_GREEN2, false);
static ArcadeLight ylwLed(PIN_LED_YELLOW, false);
static ArcadeLight encRed(PIN_ENC_RED, false, true);
static ArcadeLight encGrn(PIN_ENC_GRN, true, true);

class ArcadeLights : public ButtonListener
{
	public:
		ArcadeLights(FXArcade &_owner);
		void buttonClicked(const int buttonNum);
		void buttonSingleClicked(const int buttonNum);
		void buttonDoubleClicked(const int buttonNum);
		void init();
	private:
		FXArcade &owner;
};

#endif
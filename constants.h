#ifndef __contants_h__
#define __contants_h__

#include "Arduino.h"
#include <stdarg.h>
#include <stdio.h>
#include <PinButton.h>

// MIDI
#define MIDI_CLOCKS_PER_SECOND	24
// PINS
#define PIN_BTN_RED1	8
#define PIN_BTN_RED2	7
#define PIN_BTN_GREEN1	9
#define PIN_BTN_GREEN2	5
#define PIN_BTN_YELLOW	6

#define PIN_LED_RED1	13
#define PIN_LED_RED2	3
#define PIN_LED_GREEN1	2
#define PIN_LED_GREEN2	4
#define PIN_LED_YELLOW	A1

#define PIN_ADDR_A1 	12
#define PIN_ADDR_A0 	11
#define PIN_ENABLE 		10

#define PIN_ENC_RED		A5
#define PIN_ENC_GRN		A0
#define PIN_SYNC_IN		A6
#define PIN_BTN_ENC		A7
#define PIN_POT_IN		A2
#define PIN_MIDI_IN		A3

// LEDS
#define ARCADE_LIGHTS	8
// BUTTONS
#define ARCADE_BUTTONS	6
static PinButton red1Btn(PIN_BTN_RED1, true, false);
static PinButton red2Btn(PIN_BTN_RED2, true, false);
static PinButton grn1Btn(PIN_BTN_GREEN1, true, false);
static PinButton grn2Btn(PIN_BTN_GREEN2, true, false);
static PinButton ylwBtn(PIN_BTN_YELLOW, true, false);
static PinButton encBtn(PIN_BTN_ENC, false, true);
#define ALLBUTTONS(call) for (int i=0; i<ARCADE_BUTTONS; i++) { buttons[i]->call(); }

// DEBUG
void _SerialPrintf(const char *fmt, ...);
#define SerialPrintf(fmt, ...) 	_SerialPrintf(PSTR(fmt), ##__VA_ARGS__)
#if DEBUG
#define DBG(fmt, ...) 			_SerialPrintf(PSTR(fmt), ##__VA_ARGS__)
#else
#define DBG(fmt, ...) do {} while (0)
#endif

// CONSTANTS
enum SwitchingState
{
	NoSwitching,
	FastFree,
	FastSynced,
	FastTuned,
	FastRandom
};

enum ArcadeButtonPressed
{
	Red1,
	Red2,
	Green1,
	Green2,
	Yellow,
	None
};

enum SyncState
{
	Free,
	AnalogSyncMode,
	MIDISyncMode
};

// Listeners, we define the numbers of possible listeners to 8
// we can't do dynamic allocations (we shouldnt?) so this is safer
#define _LISTENERS 8
class ButtonListener
{
	public:
		virtual void buttonSingleClicked(const int buttonNum) = 0;
		virtual void buttonClicked(const int buttonNum) = 0;
		virtual void buttonDoubleClicked(const int buttonNum) {}
		virtual void buttonReleased(const int buttonNum) {}
		virtual void buttonLongPressed(const int buttonNum) {}
};
#endif
#include "MidiSync.h"
#include "FXArcade.h"

#include <SoftwareSerial.h>
#include <MIDI.h>

SoftwareSerial midiSerial(PIN_MIDI_IN, A2);
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, midiIn);

MidiSync::MidiSync(FXArcade &_owner)
	:	owner(_owner), 
		currentState(Stopped), 
		clockCount(0)
{
	midiSerial.begin(31250);
	midiIn.begin(0);
}

void MidiSync::update()
{
	if (midiIn.read())
	{
		if (midiIn.getType() == midi::Clock)
		{
			clockCount = (clockCount + 1) % MIDI_CLOCKS_PER_SECOND;

			if (clockCount % 24)
		}

		if (midiIn.getType() == midi::Start)
		{
			currentState = Started;
		}

		if (midiIn.getType() == midi::Stop)
		{
			currentState 	= Stopped;
			clockCount 		= 0;
		}

		if (midiIn.getType() == midi::Continue)
		{
			currentState = Running;
		}
	}
}
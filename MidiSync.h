#ifndef MIDI_SYNC_H
#define MIDI_SYNC_H

#include "constants.h"

class FXArcade;

enum MidiMachineState
{
	Stopped,
	Started,
	Running,
};

class MidiSync
{
	public:
    MidiSync(FXArcade &_owner);
		void update();

  private:
    FXArcade &owner;
    MidiMachineState currentState;
    uint16_t clockCount;
};

#endif
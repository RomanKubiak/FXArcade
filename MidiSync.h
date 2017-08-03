#ifndef MIDI_SYNC_H
#define MIDI_SYNC_H

#include <SoftwareSerial.h>
#include <MIDI.h>
#include "constants.h"

SoftwareSerial midiSerial(PIN_MIDI_IN, A2);
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);

class MidiSync
{
	public:
    MidiSync()
    {
      midiSerial.begin(31250);
      MIDI.begin(0);
    }

		void update()
		{
  	}

    void debugMidi()
    {
      if (MIDI.read())
      {
        Serial.print(millis());Serial.print(": ");
        Serial.print((const byte)MIDI.getType() + MIDI.getChannel(), HEX);
        Serial.print(":");
        Serial.print(MIDI.getData1(), HEX);
        Serial.print(":");
        Serial.println(MIDI.getData2(), HEX);
      }
    }
};

#endif
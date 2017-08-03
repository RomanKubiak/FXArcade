#ifndef ANALOG_SYNC_H
#define ANALOG_SYNC_H

#include "constants.h"

class AnalogSync
{
	public:
		void update()
		{
			if (syncState == AnalogSyncMode)
			{
				const int s = analogRead(PIN_SYNC_IN);
				if (s >= 150 && lastReadWasLow)
  				{
    				lastReadWasLow      = false;
    				digitalWrite(PIN_ENC_RED, LOW);
  				}
  				if (s < 150)
  				{
    				lastReadWasLow    = true;
    				digitalWrite(PIN_ENC_RED, HIGH);
  				}
  		}

  	private:
  		bool lastReadWasLow;
};

#endif
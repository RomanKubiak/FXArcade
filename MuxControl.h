#ifndef EXTERNAL_SYNC_H
#define EXTERNAL_SYNC_H

#include "constants.h"
class MuxControl
{
	public:
	void muxClose(byte ch)
	{
	switch (ch)
	{
		case 0:
			digitalWrite(PIN_ADDR_A0, LOW);
			digitalWrite(PIN_ADDR_A1, LOW);
			break;

		case 1:
			digitalWrite(PIN_ADDR_A0, HIGH);
			digitalWrite(PIN_ADDR_A1, LOW);
			break;

		case 2:
			digitalWrite(PIN_ADDR_A0, LOW);
			digitalWrite(PIN_ADDR_A1, HIGH);
			break;

		case 3:
			digitalWrite(PIN_ADDR_A0, HIGH);
			digitalWrite(PIN_ADDR_A1, HIGH);
			break;

		default:
			break;
	}
};

#endif

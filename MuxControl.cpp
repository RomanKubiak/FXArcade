#include "MuxControl.h"
#include "FXArcade.h"

MuxControl::MuxControl(FXArcade &_owner) 
	: owner(_owner)
{
	pinMode(PIN_ADDR_A0, OUTPUT);
	pinMode(PIN_ADDR_A1, OUTPUT);
	pinMode(PIN_ENABLE, OUTPUT);
	digitalWrite(PIN_ENABLE, LOW);

}
void MuxControl::setPath(byte ch)
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
}
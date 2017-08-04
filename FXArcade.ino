#include "FXArcade.h"
#include <Timer.h>

static FXArcade fxArcade;

void setup()
{
	Serial.begin(115200);
	fxArcade.init();
}

void loop()
{
	fxArcade.update();
}
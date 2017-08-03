#include "ArcadeLights.h"
#include "FXArcade.h"


const ArcadeLight *lights[ARCADE_LIGHTS]
{
	&red1Led, &red2Led, &grn1Led, &grn2Led, &ylwLed, &encRed, &encGrn
};

ArcadeLights::ArcadeLights(FXArcade &_owner)
	: owner(_owner)
{	
}

void ArcadeLights::init()
{
	owner.addButtonListener(this);
}

void ArcadeLights::buttonClicked(const int buttonNum)
{
	DBG("ArcadeLights::buttonClicked %d\n", buttonNum);
	if (lights[buttonNum] != nullptr)
	{
		lights[buttonNum]->toggle();
	}
}

void ArcadeLights::buttonSingleClicked(const int buttonNum)
{
	DBG("ArcadeLights::buttonSingleClicked %d\n", buttonNum);
}

void ArcadeLights::buttonDoubleClicked(const int buttonNum)
{
	DBG("ArcadeLights::buttonDoubleClicked %d\n", buttonNum);
}
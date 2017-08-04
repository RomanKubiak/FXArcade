#include "ArcadeButtons.h"
#include "FXArcade.h"

PinButton *buttons[ARCADE_BUTTONS]
{
	&red1Btn, &red2Btn, &grn1Btn, &grn2Btn, &ylwBtn, &encBtn
};

ArcadeButtons::ArcadeButtons (FXArcade &_owner) : owner(_owner)
{
}

void ArcadeButtons::update()
{
	for (int i=0; i<ARCADE_BUTTONS; i++)
	{
		buttons[i]->update();

		if (buttons[i]->isClick())
			owner.buttonClicked(i);

		if (buttons[i]->isSingleClick())
			owner.buttonSingleClicked(i);

		if (buttons[i]->isDoubleClick())
			owner.buttonDoubleClicked(i);
	}
}
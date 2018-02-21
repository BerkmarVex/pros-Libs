#include <joystick.h>

int DEADZONE = 0;

void setDeadZone(int input)
{
	DEADZONE = input;
}

int joyDualZoneDrive(int inputVal, int zone, double lowScalar, double highScalar, bool reversed)
{
	int inverted = 1;

	if (reversed) 
	{
		inverted = -1;
	}

	else if (!reversed)
	{
		inverted = 1;
	}

	if (abs(inputVal) > DEADZONE) 
	{
		if (abs(inputVal) > zone) 
		{
			return inverted *(inputVal * highScalar);
		}

		else if (abs(inputVal) < zone) {
			return inverted * (inputVal * lowScalar);
		}
	}
	return 0;
}

int joyExpDrive(int inputVal, double scalar, bool reversed)
{
	int CONSTANT = 16129;
	int inverted = 1;

	if (reversed) 
	{
		inverted = -1;
	}

	else if (!reversed)
	{
		inverted = 1;
	}

	if (abs(inputVal) > DEADZONE)
	{
		return inverted * ((pow(inputVal, 3)) / (CONSTANT * scalar));
	}
	return 0;
}

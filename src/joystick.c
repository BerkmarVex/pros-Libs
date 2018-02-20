#include <joystick.h>



int DEADZONE = 0;

void setDeadZone(int input)
{
	DEADZONE = input;
}

int joyDualZoneDrive(int inputVal, int zone, double lowScalar, double highScalar)
{
	if (abs(inputVal) > DEADZONE) 
	{
		if (abs(inputVal) > zone) 
		{
			return inputVal * highScalar;
		}

		else if (abs(inputVal) < zone) {
			return inputVal * lowScalar;
		}
	}
	return 0;
}

int joyExpDrive(int inputVal, double scalar)
{
	int CONSTANT = 16129;
	if (abs(inputVal) > DEADZONE)
	{
		return (pow(inputVal, 3)) / (CONSTANT * scalar);
	}
	return 0;
}

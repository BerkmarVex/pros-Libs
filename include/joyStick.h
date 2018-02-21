/** @file joystick.h
* @brief Header file for global joyStick functions
*
* Any experienced C or C++ programmer knows the importance of header files. For those who
* do not, a header file allows multiple files to reference functions in other files without
* necessarily having to see the code (and therefore causing a multiple definition). To make
* a function in "opcontrol.c", "auto.c", "main.c", or any other C file visible to the core
* implementation files, prototype it here.
*
*/

#ifndef JOYSTICK_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define JOYSTICK_H_

//allows the uses of advanced math functions
#include <stdlib.h>
#include <math.h>

//allows the uses of pros functions
#include <main.h>

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

	void setDeadZone(int input);

	int joyDualZoneDrive(int inputVal, int zone, double lowScalar, double highScalar, bool reversed);

	int joyExpDrive(int inputVal, double scalar, bool reversed);

	// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif

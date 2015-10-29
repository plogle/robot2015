// Wheel Motors
#pragma config(Motor, port3, leftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, rightMotor, tmotorVex393_MC29, openLoop, reversed)

// Hand open/close servos
#pragma config(Motor, port5, leftHand, tmotorServoStandard, openLoop)
#pragma config(Motor, port8, rightHand, tmotorServoStandard, openLoop)

// Hand Rotate Motor
#pragma config(Motor, port7, handMotor, tmotorVex269_MC29, openLoop)

// Arm Raise / Lower Motor
#pragma config(Motor, port9, armMotor, tmotorVex269_MC29, openLoop)


/*
	Joystick mapping:
		Ch3 - Left Joystick up/down
		Ch2 - Right Joystick up/down

	Buttons mapping:
		Btn5U - Hand Rotate Left
		Btn6U - Hand Rotate Right
		Btn5D - Raise Arm
		Btn6D - Lower Arm
		Btn8D - Open Hand
*/

task main ()
{
	int  leftHandClose = 0;
	int  rightHandClose = 0;

	int  leftHandOpen = 127;
	int  rightHandOpen = -127;

	// Set Servos to closed.
	motor[leftHand] = leftHandClose;
	motor[rightHand] = rightHandClose;

	wait1Msec(2000);

	while(1 == 1) {

		// Update Wheel Positions to current joystick values
		motor[leftMotor] = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value.

		// If Button 8D is pressed open hand.
		if (vexRT[Btn8D] == 1) {
			motor[leftHand] = leftHandOpen;
			motor[rightHand] = rightHandOpen;
		} else {
			motor[leftHand] = leftHandClose;
			motor[rightHand] = rightHandClose;
		}

	}

}

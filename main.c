#pragma config(Motor, port3, leftWheel, tmotorVex393_MC29, openLoop) // Left Wheel
#pragma config(Motor, port4, rightWheel, tmotorVex393_MC29, openLoop, reversed) // Right Wheel
#pragma config(Motor, port5, leftHand, tmotorServoStandard, openLoop) // Left side of hand
#pragma config(Motor, port8, rightHand, tmotorServoStandard, openLoop) // right side of hand
#pragma config(Motor, port7, handMotor, tmotorVex269_MC29, openLoop) // Rotate Arm
#pragma config(Motor, port9, armMotor, tmotorVex269_MC29, openLoop) // Arm Raise / Lower Motor


/************************************
	Joystick mapping:
		Ch3 - Left Joystick up/down
		Ch2 - Right Joystick up/down

	Buttons mapping:
		Btn5U - Hand Rotate Left
		Btn6U - Hand Rotate Right
		Btn5D - Raise Arm
		Btn6D - Lower Arm
		Btn8D - Open Hand
*************************************/

task main ()
{
	// Hand Servo Closed Values
	int  leftHandClose = 0;
	int  rightHandClose = 0;

	// Hand Servo Open Values
	int  leftHandOpen = 127;
	int  rightHandOpen = -127;

	// Set Hand to closed by default.
	motor[leftHand] = leftHandClose;
	motor[rightHand] = rightHandClose;

	wait1Msec(2000);

	// Main execution loop
	while(1 == 1) {

		// Update Wheel Positions to current joystick values
		motor[leftWheel] = vexRT[Ch3]; // Left Joystick Y value
		motor[rightWheel] = vexRT[Ch2]; // Right Joystick Y value.

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

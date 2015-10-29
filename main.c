#pragma config(Motor, port3, leftWheel, tmotorVex393_MC29, openLoop) // Left Wheel
#pragma config(Motor, port4, rightWheel, tmotorVex393_MC29, openLoop, reversed) // Right Wheel
#pragma config(Motor, port5, leftHand, tmotorServoStandard, openLoop) // Left side of hand
#pragma config(Motor, port8, rightHand, tmotorServoStandard, openLoop) // right side of hand
#pragma config(Motor, port7, handMotor, tmotorVex269_MC29, openLoop) // Rotate Arm
#pragma config(Motor, port9, armMotor, tmotorVex269_MC29, openLoop) // Arm Raise / Lower Motor


/******************************************
Joystick mapping:
	Ch3 - Left Joystick up/down
	Ch2 - Right Joystick up/down

Buttons mapping:
	Btn5U - Hand Rotate Left
	Btn6U - Hand Rotate Right
	Btn5D - Raise Arm
	Btn6D - Lower Arm
	Btn8D - Open Hand
******************************************/

// Left Side of hand
int leftHandClose = 0;
int leftHandOpen = 127;

// Right side of hand
int rightHandClose = 0;
int rightHandOpen = -127;

int wheelThreshold = 10;

void openHand() {
	servo[leftHand] = leftHandOpen;
	servo[rightHand] = rightHandOpen;
}

void closeHand() {
	servo[leftHand] = leftHandClose;
	servo[rightHand] = rightHandClose;
}

void rotateHandLeft() {
	motor[handMotor] = -50;
}

void rotateHandRight() {
	motor[handMotor] = 50;
}

void rotateHandStop() {
	motor[handMotor] = 0;
}

void armRaise() {
	motor[armMotor] = 50;
}

void armLower() {
	motor[armMotor] = -50;
}

void armStop() {
	motor[armMotor] = 0;
}

void tankControl() {
	int positiveThreshold = wheelThreshold;
	int negativeThreshold = wheelThreshold - (wheelThreshold * 2);

	// Check if Left Joystick is outside of threshold then update motor speed
	if (vexRT[Ch3] => positiveThreshold || vexRT[Ch3] <= negativeThreshold) {
		motor[leftWheel] = vexRT[Ch3];
	} else {
		motor[leftWheel] = 0;
	}

	// Check if Left Joystick is outside of threshold then update motor speed
	if (vexRT[Ch2] => positiveThreshold || vexRT[Ch2] <= negativeThreshold) {
		motor[rightWheel] = vexRT[Ch2];
	} else {
		motor[rightWheel] = 0;
	}
}


task main ()
{
	// Set Hand to closed by default.
	closeHand();

	delay(200);

	// Main execution loop
	while (true) {

		// Update Wheel Positions to current joystick values
		tankControl();

		// If Button 8D is pressed open hand.
		if (vexRT[Btn8D] == 1) {
			openHand();
		} else {
			closeHand();
		}

		// If Button 5U pressed rotate hand left
		if (vexRT[Btn5U] == 1) {
			rotateHandLeft();
		} else {
			rotateHandStop();
		}

		// If Button 6U pressed rotate hand right
		if (vexRT[Btn6U] == 1) {
			rotateHandRight();
		} else {
			rotateHandStop();
		}

		// If Button 5D pressed raise Arm
		if (vexRT[Btn5D] == 1) {
			armRaise();
		} else {
			armStop();
		}

		// If Button 5D pressed raise Arm
		if (vexRT[Btn6D] == 1) {
			armLower();
		} else {
			armStop();
		}

		delay(200);

	}

}

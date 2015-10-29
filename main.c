#pragma config(Motor, port3, leftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, rightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor, port5, handServo, tmotorServoStandard, openLoop)
#pragma config(Motor, port7, handServo2, tmotorVex269_MC29, openLoop)
#pragma config(Motor, port8, handMotor, tmotorServoStandard, openLoop)
#pragma config(Motor, port9, armMotor, tmotorVex269_MC29, openLoop)

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
	Btn8U - Closes Hand
******************************************/

task main ()
{
	int  handState1 = 0;
	int  handState2 = 0;
	int  maxServoPos = 127;
	int  maxServoNeg = -127;
	int  servoIncrement = 10;

	motor[handServo] = handState1;
	motor[handServo2] = handState2;

	wait1Msec(2000);

	while(true) {

		motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value.

		// Open hand
		if (vexRT[Btn8D] == 1) {

			if (handState1 < maxServoPos) {

				handState1 += servoIncrement;
				handState2 -= servoIncrement;

			}

			motor[handServo] = handState1;
			motor[handServo2] = handState2;

		}

		// Close Hand
		if (vexRT[Btn8U] == 1) {

			if (handState1 > maxServoNeg ) {

				handState1 -= servoIncrement;
				handState2 += servoIncrement;

			}

			motor[handServo] = handState1;
			motor[handServo2] = handState2;

		}

		// Button 5D raises arm
		if (vexRT[Btn5D] == 1) {
			motor[armMotor] = 100;
		}

		// Button 6D lowers arm
		if (vexRT[Btn6D] == 1) {
			motor[armMotor] = -100;
		}

		// If neither pressed stop motor
		if (vexRT[Btn6D] == 0 && vexRT[Btn5u] == 0) {
			motor[armMotor] = 0;
		}

		// Button 5U rotates hand left
		if (vexRt[Btn5U] == 1) {
			motor[handMotor] = 100;
		}

		// Button 6U rotates hand right
		if (vexRt[Btn6U] == 1) {
			motor[handMotor] = -100;
		}

		// If neither pressed stop motor
		if (vexRt[Btn5U] == 0 && vexRt[Btn6U] == 0) {
			motor[handMotor] = 0;
		}

	}

}

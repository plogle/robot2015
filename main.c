#pragma config(Motor, port3, leftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, rightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor, port5, handServo, tmotorServoStandard, openLoop)
#pragma config(Motor, port7, handServo2, tmotorServoStandard, openLoop)
#pragma config(Motor, port8, handMotor, tmotorVex393_MC29, openLoop)
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

	int threshold = 10;

	wait1Msec(2000);

	while(true) {

		// If greater then threshold set, otherwise set to 0
		if (vexRT[Ch3] > threshold || vexRT[ch3] < -threshold) {
			motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		} else {
			motor[leftMotor] = 0;
		}

		// If greater then threshold set, otherwise set to 0
		if (vexRT[Ch2] > threshold || vexRT[ch2] < -threshold) {
			motor[rightMotor]  = vexRT[Ch2];   // Right Joystick Y value
		} else {
			motor[rightMotor] = 0;
		}

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
		} else if (vexRT[Btn6D] == 1) {
			motor[armMotor] = -100;
		} else {
			motor[armMotor] = 0;
		}

		// Button 5U rotates hand left
		if (vexRT[Btn5U] == 1) {
			motor[handMotor] = 100;
		} else if (vexRT[Btn6U] == 1) {
			motor[handMotor] = -100;
		} else {
			motor[handMotor] = 0;
		}

	}

}

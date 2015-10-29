#pragma config(Motor, port3, leftWheel, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, rightWheel, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor, port5, handLeft, tmotorServoStandard, openLoop)
#pragma config(Motor, port7, handRight, tmotorVex269_MC29, openLoop)
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

	motor[handLeft] = handState1;
	motor[handRight] = handState2;

	wait1Msec(2000);

	while(true) {

		motor[leftWheel]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightWheel] = vexRT[Ch2];   // Right Joystick Y value.
		motor[armMotor] = 0;  // Arm motor
		motor[handMotor] = 0;  // Hand motor

		// Open hand
		if (vexRT[Btn8D] == 1) {

			if (handState1 < maxServoPos) {

				handState1 += servoIncrement;
				handState2 -= servoIncrement;

			}

			motor[handLeft] = handState1;
			motor[handRight] = handState2;

		}

		// Close Hand
		if (vexRT[Btn8U] == 1) {

			if (handState1 > maxServoNeg ) {

				handState1 -= servoIncrement;
				handState2 += servoIncrement;

			}

			motor[handLeft] = handState1;
			motor[handRight] = handState2;

		}

		// Button 5D raises
		if (vexRT[Btn5D] == 1) {
			motor[armMotor] = 50;
		}

		// Button 6D lowers
		if (vexRT[Btn6D] == 1) {
			motor[armMotor] = -50;
		}

		// Button 5U rotates left
		if (vexRt[Btn5U] == 1) {
			motor[handMotor] = 50;
		}

		// Button 6U rotates right
		if (vexRt[Btn6U] == 1) {
			motor[handMotor] = -50;
		}

	}

}

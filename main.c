// Wheel Motors
#pragma config(Motor, port3, leftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, rightMotor, tmotorVex393_MC29, openLoop, reversed)

// Hand open/close servos
#pragma config(Motor, port5, handServo, tmotorServoStandard, openLoop)
#pragma config(Motor, port8, handServo2, tmotorServoStandard, openLoop)

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
	int  handState1 = 0;
	int  handState2 = 0;
	int  maxServoPos = 127;
	int  maxServoNeg = -127;
	int  servoIncrement = 10;

	motor[handServo] = handState1;
	motor[handServo2] = handState2;

	wait1Msec(2000);

	while(1 == 1) {

		motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value.
		motor[armMotor] = vexRT[Ch4];  // Arm motor
		motor[handMotor] = vexRT[Ch1];  // Hand motor

		if (vexRT[Btn5U] == 1) {

			if (handState1 < maxServoPos) {

				handState1 += servoIncrement;
				handState2 -= servoIncrement;
			}

			motor[handServo] = handState1;
			motor[handServo2] = handState2;
		}

		if (vexRT[Btn5D] == 1) {

			if (handState1 > maxServoNeg ) {

				handState1 -= servoIncrement;
				handState2 += servoIncrement;
			}

			motor[handServo] = handState1;
			motor[handServo2] = handState2;
		}


	}

}

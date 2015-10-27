#pragma config(Motor, port3, leftMotor, tmotorVex393_MC29)
#pragma config(Motor, port4, rightMotor, tmotorVex393_MC29, reversed)
#pragma config(Motor, port5, handServo, tmotorServoStandard)
#pragma config(Motor, port8, handServo2, tmotorServoStandard)
#pragma config(Motor, port9, armMotor, tmotorVex269_MC29)
#pragma config(Motor, port7, handMotor, tmotorVex269_MC29)

task main (){	
	int handState1 = 0;
	int handState2 = 0;	
	int maxServoPos = 127;	
	int maxServoNeg = -127;
	int servoIncrement = 10;	
	
	motor[handServo] = handState1;	
	motor[handServo2] = handState2;	
	
	wait1Msec(2000);	
	
	if(1==1) {		
		motor[leftMotor] = vexRT[Ch3];
		
		// Left Joystick Y value
		motor[rightMotor] = vexRT[Ch2]; 
		
		// Right Joystick Y value.	
	}	
	
	if (vexRT[Btn5U]==1) {
		motor[armMotor] = vexRT[Btn5U]*50;	
	}	
	
	if (vexRT[Btn6U]==1) {		
		motor[armMotor] = vexRT[Btn6U]*50;	
	}	
	
	if (vexRT[Btn5D]==1) {		
		motor[handMotor] = vexRT[Btn5D]*50;	
	}	
	
	if (vexRT[Btn6D]==1) {		
		motor[handMotor] = vexRT[Btn6D]*50;	
	}
}	

if (vexRT[Btn8D] == 1) {				
	if (handState1 < maxServoPos) {					
		handState1 += servoIncrement;					
		handState2 -= servoIncrement;
	}			
	
	motor[handServo] = handState1;			
	motor[handServo2] = handState2;		
}		

if (vexRT[Btn8U] == 1) {			
	if (handState1 > maxServoNeg) {
		handState1 -= servoIncrement;
		handState2 += servoIncrement; 
		
		// this will not run... it is a comment. lolz			
	}			
	
	motor[handServo] = handState1;			
	motor[handServo2] = handState2;		
}		

delay(200);				
}

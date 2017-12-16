#include <Benchy.h>
#include <Prefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <NetworkTables/NetworkTable.h>

Benchy::Benchy(void):

a_Joystick(JOYSTICK_PORT), // this should be the gamepad - list on port 0
a_Pan(PAN_PORT),
a_Tilt(TILT_PORT),
a_LRC()

{
	SmartDashboard::init();
	a_Desk = NetworkTable::GetTable("datatable");
}

void oControl(void){
	double x = 0;
	double y = 0;
	while (IsOperatorControl() && IsEnabled()){
		a_Desk.PutNumber("X", x);
		a_Desk.PutNumber("Y", y);
		x+=1;
		y+=1;
	}
}

void Benchy::RobotInit()
{

}

void Benchy::RobotPeriodic()
{

}

void Benchy::DisabledInit()
{

}

void Benchy::DisabledPeriodic()
{
	SmartDashboard::PutString("Enabled: ", "False");
	a_LRC.SetColor(0,0,100,0);
	a_LRC.SetColor(1,0,100,0);
	a_LRC.SetColor(2,0,100,0);
}

void Benchy::AutonomousInit()
{}

void Benchy::AutonomousPeriodic()
{}

void Benchy::TeleopInit()
{
	SmartDashboard::PutString("Enabled: ", "True");
}

void Benchy::TeleopPeriodic()
{
	a_LRC.SetColor(0,0,0,100);
	a_LRC.SetColor(1,0,0,100);
	a_LRC.SetColor(2,0,0,100);
	static int angle = 0;
	if (angle == 170){
		angle = 0;
	}
	else {
		angle++;
	}
	a_Pan.SetAngle(angle);
	a_Tilt.SetAngle(angle);
}

void Benchy::TestInit()
{}

void Benchy::TestPeriodic()
{
	a_Pan.SetAngle(50);
	a_Tilt.SetAngle(50);
}

START_ROBOT_CLASS(Benchy);

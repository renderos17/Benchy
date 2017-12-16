/*
 *
 * Let's see if this actually works.
 *
 */

#ifndef SRC_BENCHY_H_
#define SRC_BENCHY_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <IterativeRobot.h>
#include <LightRingController.h>
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"

class Benchy : public IterativeRobot {
public:
	Benchy(void);
	void RobotInit(void);
	void RobotPeriodic(void);
	void DisabledInit(void);
	void DisabledPeriodic(void);
	void TeleopInit(void);
	void TeleopPeriodic(void);
	void TestInit(void);
	void TestPeriodic(void);
	void AutonomousInit(void);
	void AutonomousPeriodicFull(void);
	void AutonomousPeriodic(void);
	void AutonomousPeriodicSimple(void);

private:
	Joystick a_Joystick;
	Servo a_Pan;
	Servo a_Tilt;
	LightRingController a_LRC;
	NetworkTable a_Desk;
};

#endif

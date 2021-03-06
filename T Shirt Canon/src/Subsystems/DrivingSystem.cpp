// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DrivingSystem.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DrivingSystem::DrivingSystem() : Subsystem("DrivingSystem") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    speedController1 = RobotMap::drivingSystemSpeedController1;
    speedController2 = RobotMap::drivingSystemSpeedController2;

    accelerometer = RobotMap::drivingSystemAccelerometer1;
    robotDrive2 = RobotMap::drivingSystemRobotDrive2;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DrivingSystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivingSystem::tank_drive()
{
	robotDrive2->TankDrive(-0.8*Robot::oi->getxboxController()->GetRawAxis(1),
							-0.8*Robot::oi->getxboxController()->GetRawAxis(5),true);
}

void DrivingSystem::tank_drive(float left, float right)
{
	robotDrive2->TankDrive(left,right,true);
}

void DrivingSystem::feedback()
{
	if(Robot::oi->getxboxController()->GetRawAxis(1)>0.1
				||Robot::oi->getxboxController()->GetRawAxis(1)<0.1
				||Robot::oi->getxboxController()->GetRawAxis(5)>0.1
				||Robot::oi->getxboxController()->GetRawAxis(5)<0.1
				||Robot::oi->getxboxController()->GetRawAxis(0)>0.1
				||Robot::oi->getxboxController()->GetRawAxis(0)<0.1)
		{
			Robot::oi->getxboxController()->SetRumble(Joystick::kLeftRumble,max(getAccY(),getAccX()));
		}
		else if(getAccY()&&getAccX())
		{
			Robot::oi->getxboxController()->SetRumble(Joystick::kLeftRumble,1);
			Robot::oi->getxboxController()->SetRumble(Joystick::kRightRumble,1);
		}
}

double DrivingSystem::getAccX()
{
	return accelerometer->GetX();
}

double DrivingSystem::getAccY()
{
	return accelerometer->GetY();
}

double DrivingSystem::getAccZ()
{
	return accelerometer->GetZ();
}

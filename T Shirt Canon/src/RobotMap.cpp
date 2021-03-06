// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::drivingSystemSpeedController1;
std::shared_ptr<SpeedController> RobotMap::drivingSystemSpeedController2;
std::shared_ptr<Accelerometer> RobotMap::drivingSystemAccelerometer1;
std::shared_ptr<RobotDrive> RobotMap::drivingSystemRobotDrive2;
std::shared_ptr<SpeedController> RobotMap::compressorSpeedController1;
std::shared_ptr<SpeedController> RobotMap::canonSpeedController1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    drivingSystemSpeedController1.reset(new Talon(0));
    lw->AddActuator("Driving System", "Speed Controller 1", (Talon&) drivingSystemSpeedController1);
    
    drivingSystemSpeedController2.reset(new Talon(1));
    lw->AddActuator("Driving System", "Speed Controller 2", (Talon&) drivingSystemSpeedController2);
    
    drivingSystemRobotDrive2.reset(new RobotDrive(drivingSystemSpeedController1, drivingSystemSpeedController2));
    
    drivingSystemRobotDrive2->SetSafetyEnabled(true);
        drivingSystemRobotDrive2->SetExpiration(0.1);
        drivingSystemRobotDrive2->SetSensitivity(0.5);
        drivingSystemRobotDrive2->SetMaxOutput(1.0);
        //drivingSystemRobotDrive2->SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);
        //drivingSystemRobotDrive2->SetInvertedMotor(RobotDrive::kFrontRightMotor,true);

    drivingSystemAccelerometer1.reset(new BuiltInAccelerometer());

    compressorSpeedController1.reset(new Talon(2));
    lw->AddActuator("Compressor", "Speed Controller 1", (Talon&) compressorSpeedController1);
    
    canonSpeedController1.reset(new Talon(3));
    lw->AddActuator("Canon", "Speed Controller 1", (Talon&) canonSpeedController1);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// armMotor             motor         6               
// liftMotor            motor_group   19, 20          
// BumperB              bumper        B               
// Drivetrain           drivetrain    2, 8            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {

}


void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {
  liftMotor.setVelocity(100, percent);

    
// controllerInputWheel
int forward = Controller1.Axis3.position(vex::percent);
int turn = Controller1.Axis1.position(vex::percent);

    // controllerInput

    if (Controller1.ButtonR1.pressing()) {
        liftMotor.spin(vex::forward);
    }
    else {
      if (Controller1.ButtonR2.pressing()) {
        liftMotor.spin(reverse);
      }
      else {
        liftMotor.stop();
      }
    }

    if (BumperB.pressing()) {
      armMotor.spin(vex::forward);}
      
    else {
      if (Controller1.ButtonL2.pressing()  == true || Controller1.ButtonL1.pressing()) {
        armMotor.spin(reverse);
      }
      else {
        armMotor.stop();
      }
    }
  wait(5, msec);
  }
}
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol); 


  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

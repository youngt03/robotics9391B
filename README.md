/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX 9391B                                                 */
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

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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

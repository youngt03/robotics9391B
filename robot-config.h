using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor armMotor;
extern motor_group liftMotor;
extern bumper BumperB;
extern drivetrain Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

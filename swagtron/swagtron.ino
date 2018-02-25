/*************** SWAGTRON BOT CODE ******************
 *      Stanford ME210 Final Project
 * Michael Parrott, Will Walecka, Arjun Arora, Kameron Butler
 * 
 * Designed for ME210 2018 Winter Challenge: BuzzWords
 * Started on 2.22.18
 * 
 */

/* Constants, Pin Numbering */
#define DESIRED_FWD_SPEED  100

/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_MOVE_FORWARD, STATE_MOVE_BACKWARD, STATE_MOVE_LEFT, STATE_MOVE_RIGHT, STATE_STOP, STATE_DISPENSE
} States_t;

typedef enum {
  GOAL_ROUNDA, GOAL_ROUNDB, GOAL_PATENT, GOAL_ENDGAME, GOAL_FINDLINE, GOAL_REFILL
} Goals_t;

/* Global Variables (by section) */

States_t state;  
Goals_t goal;
/* Motors */

/* Sensors */


void setup() {
  /* Timer Setup */

  /* Motor Setup */

  /* Sensor Setup */

  /* Stepper Setup*/

  //probably also for line

}

void loop() {
  // put your main code here, to run repeatedly:
  checkGlobalEvents();
  setMotorStates();
  driveMotors();
}

/***************************** checkGlobalEvents and Helpers ***********************/
/*
 *  Function: checkGlobalEvents()
 *  
 *  Called on every loop, this function determines goal from sensor states and past information
 *  
 *  Goal is overall desire (e.g. GOAL_ROUNDA)
 * 
 */
void checkGlobalEvents(){
  //will check line & IR sensors, change goal based on changes from past information
  if (TestLineSensors()) RespLineSensors();  // here, knowing direction and current goal, can change goal
  if (TestBeaconSensors()) RespBeaconSensors();  //here knowing goal, can determine when to change goal
  if (TestLimitSwitch()) RespLimitSwitch();
}

/****************************** setMotorStates and Helpers **********************/
/*
 *  
 *  
 */

void setMotorStates(){
  switch (goal) {
    case GOAL_ROUNDA:
      goToRoundA();
      break;
    case GOAL_ROUNDB:
      goToRoundB();
      break;
    case GOAL_DISPENSE:
      dispenseBalls();
      break;
    case GOAL_ENDGAME:
      goToEndgame();
      break;
    case GOAL_REFILL:
      goToIncubator();
      break;
}

void goToRoundA(){
  
}

void goToRoundB(){
  
}

void dispenseBalls(){
  
}

void goToEndgame(){
  
}

void goToIncubator(){
  
}

int [] lineResponse(double leftSpeed, double rightSpeed){
  return null;
}

/****************************** driveMotors and Helpers **********************/

void driveMotors(){
  //loop through all motors and set drive values
}

}


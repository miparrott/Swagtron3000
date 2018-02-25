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
#define REFLECT_VAL 1

#define GoalAx = 2
#define GoalAy = 1

#define GoalBx = 4
#define GoalBy = 1

#define Endx = 5
#define Endy = 2
/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_MOVE_FORWARD, STATE_MOVE_LEFT, STATE_MOVE_RIGHT,STATE_MOVE_BACKWARD, STATE_STOP, STATE_DISPENSE
} States_t;

typedef enum {
  GOAL_ROUNDA, GOAL_ROUNDB, GOAL_PATENT, GOAL_ENDGAME, GOAL_FINDLINE, GOAL_REFILL
} Goals_t;

/* Global Variables (by section) */

States_t state;  
Goals_t goal;
/* Motors */

/* Sensors */

int beaconStates = [0 0 0];
int motorState = [0 0 0 0];

/************** Action Flags (for history purposes) *********/

boolean beaconAActivated;
boolean beaconBActivated;
boolean gateActivated;

/************ Position Variables ***********/

int xPos;
int yPos;

void setup() {
  //setup motors, sensors, etc
  //setup drive motors

  //setup line sensors


  //setup beacon sensors
  
  //initial goal will be go to round A
  yPos = 0;
  xPos = 1;
  goal = GOAL_ROUND_A
}

void loop() {
  checkGlobalEvents();
  //changeStateFromBeacon();
  setMotorDirection();
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

 int [] oldLineSensorState = [0 0 0 0 0 0];
 int [] newLineSensorState = [0 0 0 0 0 0];
 int [] oldBeaconSensorState = [0 0 0 0];
 int [] newBeaconSensorState = [0 0 0 0];

 
void checkGlobalEvents(){
  //will check line & IR sensors, change goal based on changes from past information
  if (TestLineSensors()) RespLineSensors();  // here, knowing direction and current goal, can change goal
  if (TestBeaconSensors()) RespBeaconSensors();  //here knowing goal, can determine when to change goal
  if (TestLimitSwitch()) RespLimitSwitch();
}


int TestLineSensors() {
  populateNewSensorState();
  return 1;
}

void populateNewSensorState(){
  oldLineSensorState = newLineSensorState;
  //get line array booleans
  //replace old with last new
}

//boolean checkMatchingLine(){
//  for (int i = 0; i < sensorState.length();i ++){
//    if (oldLineSensorState[i] != newLineSensorState[i]) return false;
//  }
//  return true;
//}

void RespLineSensors(){
  //based on direction of motion, if crossed perpendicular, update count
  if (state == STATE_MOVE_FORWARD){
    if (newLineSensorState[3] == REFLECT_VAL && oldSensorState[3] != newSensorState[3]){
      yPos += 2; 
    }
  } else if (state == STATE_MOVE_BACKWARD){
    if (newLineSensorState[5] == REFLECT_VAL && oldSensorState[5] != newSensorState[5]){
      yPos -= 1;
    }
    
  } else if (state == STATE_MOVE_LEFT){
    if (newLineSensorState[0] == REFLECT_VAL && oldSensorState[0] != newSensorState[0]){
      xPos += 1;
    }
    
  } else if (state == STATE_MOVE_RIGHT){
    if (newLineSensorState[1] == REFLECT_VAL && oldSensorState[1] != newSensorState[1]){
      xPos -=1;
    }
  }
}

int TestBeaconSensors() {
  //TBD
  return null;
}

void RespBeaconSensors(){
  changeStateFromBeacon();
}

int TestLimitSwitch() {
  return null;
}

void RespLimitSwitch(){
  // when limit switch gets activated, dispenseBall
}


/**************** changeStateFromBeacon() ****************/

void changeStateFromBeacon(){
  if (beaconStates[0] == 1 && beaconAActivated == 0){
    beaconAActivated = 1;
  }
  if (beaconStates[1] == 1 && beaconBActivated == 0){
    beaconBActivated = 1;
  }
  if (beaconStates[2] == 1 && gateActivated == 0){
    gateActivated == 1;
  }
  if (beaconAActivated != 1){
    goal = GOAL_ROUNDA;
  } else if (beaconAActivated ==1 && beaconBActivated == 1){
    goal = GOAL_ROUNDB;
  } else {
    goal = GOAL_ENDGAME;
  }
}


/**************** setMotorStates() ***********/


void setMotorStates(){
  switch (goal) {
    case GOAL_ROUNDA:
      goToRoundA();
      break;
    case GOAL_ROUNDB:
      goToRoundB();
      break;
    case GOAL_DISPENSE:
      dispenseBall();
    case GOAL_ENDGAME:
      goToEndGame();
    default:    // Should never get into an unhandled state
      Serial.print("Oh no...");
  }
}

void goToRoundA(){
  if (xPos != GoalAx){
    if (xPos > GoalAx){
      state = MOVE_RIGHT;
    }
    if (xPos < GoalAx){
      state = MOVE_LEFT;
    }
  } else if (yPos != GoalAy) {
    if (yPos > GoalAy){
      state = MOVE_BACK;
    } else {
      state = MOVE_FORWARD;
    }
  } else {
    state = MOVE_FORWARD;
  }
  
}

void goToRoundB(){
  if (xPos != GoalBx){
    if (xPos > GoalBx){
      state = MOVE_RIGHT;
    }
    if (xPos < GoalBx){
      state = MOVE_LEFT;
    }
  } else if (yPos != GoalBy) {
    if (yPos > GoalBy){
      state = MOVE_BACK;
    } else {
      state = MOVE_FORWARD;
    }
  } else {
    state = MOVE_FORWARD;
  }
}

void goToEndgame(){
  
}
void dispenseBall(){
  //open gate
  //delay x
  //close gate
  //move back 10 ms
}





/***************** DriveMotorStates() *********/


void driveMotorStates(){
  //line following will happen here
  for (int i = 0; i < 4; i++){
    //iterate through motor values, drive motor
  }
}


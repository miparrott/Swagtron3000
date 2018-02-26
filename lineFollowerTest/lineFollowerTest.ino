int curMotor;
IntervalTimer timer;

//pin #s
int lineSensors [4];
int lineSensorVals[4]

int motorValues[4];

#define RUNNING_SPEED 100
#define GRAY_THRESHOLD 400
#define BLACK_THRESHOLD 800
#define MAX_VAL 1023
#define MIN_VAL 0
#define GREY_VALUE 1
#define BLACK_VALUE 2
#define SWITCHING_TIME 10000
#define ADJUSTMENT_PWM 20

typedef enum {
  STATE_MOVE_FORWARD, STATE_MOVE_LEFT, STATE_MOVE_RIGHT,STATE_MOVE_BACKWARD, STATE_STOP, STATE_DISPENSE
} States_t;

States_t state;
States_t lastState;

void setup() {
  // put your setup code here, to run once:
  //setup motors

}

void loop() {
  state = STATE_FORWARD;
  checkGlobalValues();
  lineFollowing(state);
}

void checkGlobalValues(){
  checkLineSensors();
}

void checkLineSensors(){
  for (int i = 0; i < lineSensors; i++){
    lineSensorVals[i] = getLineState(i); ///where 0 is no tape, 1 is black tape, 2 is reflective tape
  }
}

int getLineState(int i){
  double x = analogRead(lineSensors[i]);
  if (x > LINE_THRESHOLD){
    return 1;
  } else {
    return 0;
  }
}


void lineFollowing(States_t state){
  int motors[3];
  int sensors[2];
  switch(state):
    case 'STATE_FORWARD':
      motors = {1,3,0};
      sensors = {0,1};
      setMotors(motors,sensors)
      break;
}

void setMotors(int motors[], int sensors[]){
  motorValues[motors[0]] = RUNNING_SPEED;
  motorValues[motors[1]] = RUNNING_SPEED;
  curMotor = motors[2]
  if (sensors[0] == 1)
  {
    motorValues[curMotor] = ADJUSTMENT_PWM;
    begin.timer(adjustment, SWITCHING_TIME);
  }
  else if (sensors[1] == 1)
  {
    motorValues[curMotor] = -1*ADJUSTMENT_PWM;
    begin.timer(adjustment, SWITCHING_TIME);
  }
}

void adjustment(void)
{
  motorValues[curMotor] = 0;
  end.timer();
  }


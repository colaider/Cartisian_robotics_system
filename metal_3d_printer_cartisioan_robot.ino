#define spr 200
int delForMotors = 1000;


// z -> 0 y -> 1 x -> 0 || (axes -> index in pin arr)
const int dirPin[3] = {2,7,9};
const int stepPin[3] = {3,8,10};
const int limitPin[3] = {19,20,21};

//<-- all microsteping is common for all actuators -->
const int msPins[3] = {4, 5, 6};

//<-- function prototypres -->
void setupMicrosteping(float step);
void movePerMilsOnStep(float step, float mm);
void homing();
void bubbleSort(int array[], int size);
bool valueinarray(int val, int *arr, size_t n);
float * retMmArr(float x, float y, float z);
void moveAllMotorsOnDistance(float step, float x, float y, float z);
void zigZagPatern(int len, int heigh);


void setup(){
  Serial.begin(9600);

  //<-- setting up pins -->
  for(int i=0;i<3;i++){
    pinMode(stepPin[i], OUTPUT);
	  pinMode(dirPin[i], OUTPUT);
  }

   homing();
   //<-- put same number as in zig zag len --> 
   moveAllMotorsOnDistance(1.0,-125.0,-125.0,-0);
}
 
void loop(){
  // <-- len of zig zag -->
  // <-- heigh of movoment -->
   zigZagPatern(123, 1);
   
}	

void setupMicrosteping(float step){
  for(int i=0;i<3;i++)
    pinMode(msPins[i], 1);

  if(step == 1.0){
    digitalWrite(msPins[0], 0);
    digitalWrite(msPins[1], 0);
    digitalWrite(msPins[2], 0);
  }else if(step == 1.0/2.0){
    digitalWrite(msPins[0], 1);
    digitalWrite(msPins[1], 0);
    digitalWrite(msPins[2], 0);
  }else if(step == 1.0/4.0){
    digitalWrite(msPins[0], 0);
    digitalWrite(msPins[1], 1);
    digitalWrite(msPins[2], 1);
  }else if(step == 1.0/8.0){
    digitalWrite(msPins[0], 1);
    digitalWrite(msPins[1], 1);
    digitalWrite(msPins[2], 0);
  }else if(step == 1.0/16.0){
    digitalWrite(msPins[0], 1);
    digitalWrite(msPins[1], 1);
    digitalWrite(msPins[2], 1);
  }
}

//<-- forward: dir = high || backward: dir = low -->
void movePerMilsOnStep(int dir, int actuator){
  digitalWrite(dirPin[actuator], dir);
  digitalWrite(stepPin[actuator], HIGH);
  delayMicroseconds(delForMotors);
  digitalWrite(stepPin[actuator], LOW);
  delayMicroseconds(delForMotors);
}

void zigZagPatern(int len, int heigh){

  //DIR 0 -> aginst motor
  moveSingleMotor(2, 0, heigh);
  if(len%20 == 0){
    for(int i=0; i<len/20;i++){
     moveSingleMotor(0, 0, 30);
     moveSingleMotor(1, 0, 10);
     moveSingleMotor(0, 1, 30);
     moveSingleMotor(1, 0, 10);
    }
  }else{
    while(len%20 != 0){
      len -= 1;
    }
    for(int i=0; i<len/20;i++){
     moveSingleMotor(0, 0, 30);
     moveSingleMotor(1, 0, 10);
     moveSingleMotor(0, 1, 30);
     moveSingleMotor(1, 0, 10);
    }
  }

  moveSingleMotor(1, 1, len);
  moveSingleMotor(2, 1, heigh);
}


void homing(){
  // <-- limit switches states -->
  int lmStates[3] = {1,1,1}; 

  // <-- homing procedure -->
  //,-- put i<3 for 3 switches -->
  for(int i=0;i<2;i++){
    pinMode(limitPin[i], INPUT_PULLUP);
    while(lmStates[i] == 1){
      movePerMilsOnStep(0, i);
      lmStates[i] = digitalRead(limitPin[i]); 
    }
  }
}

// forw 0 backw 1
void moveSingleMotor(int m, int dir, float dis){
  delForMotors = 1000;
  if(m != 2){
    for(int i=0;i<int(dis*25.0);i++)
      movePerMilsOnStep(dir, m);
  }else{
    for(int i=0;i<int(dis*40.0);i++)
      movePerMilsOnStep(dir, m);
  }
}

// only for multiple motors simulteniously
// if you move sequntially use move single motor
void moveAllMotorsOnDistance(float step, float x, float y, float z){
  delForMotors = 400;
  float mm[3]; mm[0] = x; mm[1] = y; mm[2] = z;
  
  int amountOfSteps[3] = {0.0,0.0,0.0}; int  aStepsSorted[3];
  int orderArr[3]; int dirArr[3];

  // 0 -> ywords mototr : 1 -> oposite
  for(int i=0;i<3;i++){
    dirArr[i] = mm[i] < 0 ? 1 : 0;
    mm[i] = mm[i] < 0 ? mm[i]*-1 : mm[i]; 
  }

  setupMicrosteping(step);
  amountOfSteps[0] = mm[0]*25/step;
  amountOfSteps[1] = mm[1]*25/step;
  amountOfSteps[2] = mm[2]*40/step;

  for(int i=0;i<3;i++){
    aStepsSorted[i] = amountOfSteps[i];
  }
  
  bubbleSort(aStepsSorted, 3);

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(aStepsSorted[i] == amountOfSteps[j] && !valueinarray(j, orderArr, 3))
        orderArr[i] = j;
    }
  }

  for(int i=0; i<aStepsSorted[0];i++){
    movePerMilsOnStep(dirArr[orderArr[0]], orderArr[0]);
    movePerMilsOnStep(dirArr[orderArr[1]], orderArr[1]);
    movePerMilsOnStep(dirArr[orderArr[2]], orderArr[2]);
  }

   for(int i=0; i<aStepsSorted[1] - aStepsSorted[0];i++){
    movePerMilsOnStep(dirArr[orderArr[1]], orderArr[1]);
    movePerMilsOnStep(dirArr[orderArr[2]], orderArr[2]);
    blinkingMotFunc();
    
  }

  for(int i=0; i<aStepsSorted[2] - aStepsSorted[1] - aStepsSorted[0];i++){
    movePerMilsOnStep(dirArr[orderArr[2]], orderArr[2]);
    blinkingMotFunc();
    blinkingMotFunc();
  }

}

void blinkingMotFunc(){
    digitalWrite(52, 1);
    digitalWrite(13, 1);
    delayMicroseconds(delForMotors);
    digitalWrite(13,0);
    delayMicroseconds(delForMotors);
}
void bubbleSort(int * arr, int size) {
    for (int step = 0; step < size - 1; ++step) {
        int swapped = 0;

        for (int i = 0; i < size - step - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

bool valueinarray(int val, int * arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        if(arr[i] == val)
            return true;
    }
    return false;
}



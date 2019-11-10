#define NUM_SENSORS             8  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2
#define INTERSECTION_CONDITION (sensorValues[0] <700 &&sensorValues[7]<700) || (sensorValues[1]<700&&sensorValues[7]<700) || (sensorValues[0]<700 &&sensorValues[6]<700 )|| (sensorValues[1]<700 &&sensorValues[6]<700 ) 
#define RFID (sensorValues[0]<650 && sensorValues[4]<650) ||(sensorValues[5]<650 && sensorValues[7]<650) || (sensorValues[3]<650 && sensorValues[1]<650) ||(sensorValues[1]<650 && sensorValues[3]<650)
#include <QTRSensors.h>
#include <PID_v1.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Encoder.h>
#include <Servo.h>
#include <Wire.h>
#include <TimerOne.h>                                 // Header file for TimerOne library
#include <PinChangeInt.h>

#define SLAVE_ADDRESS 0x04



Servo servoup;  // create servo object to control a servo
Servo servoback;

QTRSensorsAnalog qtra((unsigned char[]) {0, 1, 2, 3, 4, 5,6,7}, 
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];


double Setpoint, Input, Output; //global variables used in PID control  .015,.0002,0.0035,
PID myPID(&Input, &Output, &Setpoint,.02,0.000001,0.000035, DIRECT); //creating object of PID class

unsigned int minimum[8] = {629,573,418,529,467,503,596,573};

unsigned int maximum[8] = {984,977,967,980,970,973,983,978};

#define RightPWM 7
#define RightDir 3
#define LeftPWM 5
#define LeftDir 4
Encoder knobLeft(18, 19);
 int OutR;
 int OutL;
int x;
 int i=0;
 int v;
 int z;
 int y;
 int sensorPin = 10; // IR 
 int sensorPin2 =11; // Line finder
int start;
 volatile int arry[60]={40,1,1,1,1,1,1,1,2,1,4,5,2,1,1,4,1,2,1,4,1,6};
//char arry[]={'U','O','B'};
volatile int index=-1;

#define RST_PIN        46          // Configurable, see typical pin layout above
#define SS_PIN         53
int state = 0;
volatile int number=1;
MFRC522 mfrc522(SS_PIN, RST_PIN);  
#define trigPin        12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define echoPin        10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 10 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define echo_int 10                                    // Interrupt id for echo pulse
#define TIMER_US 50                                   // 50 uS timer duration 
#define TICK_COUNTS 4000                              // 200 mS worth of timer ticks

volatile long echo_start = 0;                         // Records start of echo pulse 
volatile long echo_end = 0;                           // Records end of echo pulse
volatile long echo_duration = 0;                      // Duration - difference between end and start
volatile int trigger_time_count = 0;                  // Count down counter to trigger pulse time

void setup() {
Serial.begin(9600);
SPI.begin();        // Init SPI bus
mfrc522.PCD_Init(); // Init MFRC522 card
//Serial.print(("Ready for the tag"));
//Serial.println();
//Serial.println("hopa bsmallah");

Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
//Wire.onRequest(sendData);
Wire.onReceive(receiveData);

myPID.SetMode(AUTOMATIC);
qtra.calibratedMinimumOn = minimum;
qtra.calibratedMaximumOn = maximum;
myPID.SetOutputLimits(-10,10);
Setpoint = 3670;
myPID.SetSampleTime(50);
servoup.attach(8);
servoback.attach(9);
  pinMode(trigPin, OUTPUT);                           // Trigger pin set to output
  pinMode(echoPin, INPUT);                            // Echo pin set to input
  pinMode(13, OUTPUT);
 Timer1.initialize(TIMER_US);                        // Initialise timer 1
  Timer1.attachInterrupt( timerIsr );                 // Attach interrupt to the timer service routine 
  //PCintPort::attachInterrupt(echo_int, echo_interrupt, CHANGE);  // Attach interrupt to the sensor echo input
 
}
long positionLeft  = -999;
long positionRight = -999;
 long newLeft, newRight;
 
void loop(){

 // if (i==0){
down();
  //}
//if (index != -1){
//    arry[index]=number;
//}
//
//if (arry[index]==100){
//  index=-1;


 // Serial.println("eeeeeeeeeeeeeeeee");

 for (i = 1;i<arry[0]; i++){

  
  if(arry[i]==1){
    
      Timer1.attachInterrupt( timerIsr );
  while(arry[i]==1){ 
track_line();

//Serial.println("waleeeeeeeeeeeeeed");
}
  }
if(arry[i]==3){
  
      Timer1.attachInterrupt( timerIsr );
RotRight_180();
      Timer1.attachInterrupt( timerIsr );

      if  (arry[i + 1] == 5 || arry[i + 1] == 6) {
        i++ ;
      }
      else {
        while (arry[i] == 3) {
          track_line();
        }
      }

}

if(arry[i]==2){
   Timer1.detachInterrupt();                 // Attach interrupt to the timer service routine
   
RotRight_90();
  Timer1.attachInterrupt( timerIsr );

      if  (arry[i + 1] == 5 || arry[i + 1] == 6) {
        i++;
      }
      else {
        while (arry[i] == 2) {
          track_line();
        }
      }
}

if(arry[i]==4){
        Timer1.detachInterrupt();                 // Attach interrupt to the timer service routine

RotLeft_90();
     Timer1.attachInterrupt( timerIsr );

      if  (arry[i + 1] == 5 || arry[i + 1] == 6) {
        i++;
      }
      else {
        while (arry[i] == 4) {
          track_line();
        }
      }

}

if(arry[i]==5){
        Timer1.detachInterrupt();                 // Attach interrupt to the timer service routine

 // Serial.println (digitalRead(sensorPin));
 upload();
       Timer1.attachInterrupt( timerIsr );

}

if(arry[i]==6){
        Timer1.detachInterrupt();                 // Attach interrupt to the timer service routine

download();
back();
RotLeft_180();
i++;
      Timer1.attachInterrupt( timerIsr );

}
//if(arry[i]==(arry[0]-1)){
//  Timer1.detachInterrupt(timerIsr);
//}
//if(arry[i]=='B'){
//back();
//RotLeft_180();
//}

if (arry[i] !=0){
i--;
}


 // return;

//Serial.println(i);

// }
}
}

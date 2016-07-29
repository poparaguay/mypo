#include <Servo.h>
#include <MyoBridge.h>
#include <SoftwareSerial.h>

//SoftwareSerial connection to MyoBridge
SoftwareSerial bridgeSerial(2,3);

//initialize MyoBridge object with software serial connection
MyoBridge bridge(bridgeSerial);

//declare a function to handle pose data
void handlePoseData(MyoPoseData& data) {

  //convert pose data to MyoPose
  MyoPose pose;
  pose = (MyoPose)data.pose;

  //print the pose
  Serial.println(bridge.poseToString(pose));

  move_hand(pose);

   //delay(100);
}

//a function to inform us about the current state and the progess of the connection to the Myo.
void printConnectionStatus(MyoConnectionStatus status) {
  
  //print the status constant as string
  Serial.println(bridge.connectionStatusToString(status));
}


Servo servo_thumb;  // objeto servo pulgar
Servo servo_index_middle;  // objeto servo indice y medio
Servo servo_ring_pinkie;  // objeto servo anular y meñique

void setup() {
  //initialize both serial connections
  Serial.begin(115200);
  bridgeSerial.begin(115200);

  //wait until MyoBridge has found Myo and is connected. Make sure Myo is not connected to anything else and not in standby!
  Serial.println("Searching for Myo...");
  for (int i=0; i<10;i++){digitalWrite(13, HIGH);delay(50);
  digitalWrite(13, LOW);delay(50);} 
 //initiate the connection with the status callback function
  bridge.begin(printConnectionStatus);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  Serial.println("connected!");
  //declare a storage array for the hardware address
  byte address[6];
  //get the address and store it in our array
  bridge.getHardwareAddress(address);
  //print the hardware address in HEX format
  Serial.print("Hardware Address: 0x");
  for (int i=0;i<6;i++) {
    Serial.print(address[i], HEX);
  }
  Serial.println();
  
  //get the current battery level and print it
  byte batteryLevel = bridge.getBatteryLevel();
  Serial.print("Battery Level: ");
  Serial.println(batteryLevel);
  
  //short vibration to show we are ready
  bridge.vibrate(1);

  
  //set the function that handles pose events
  bridge.setPoseEventCallBack(handlePoseData);
  //tell the Myo we want Pose data
  bridge.enablePoseData();
  //make sure Myo is unlocked
  bridge.unlockMyo();

  //You have to perform the sync gesture to receive Pose data!

  servo_thumb.attach(9);  // attaches the servo on pin 3 to the servo object
  servo_index_middle.attach(6);  // attaches the servo on pin 5 to the servo object
  servo_ring_pinkie.attach(5);  // attaches the servo on pin 6 to the servo object
}

void loop()
{
  //update the connection to MyoBridge
  bridge.update();

  //MyoPose pose;
  //pose = (MyoPose)data.pose;
  //char a = bridge.poseToString(pose);

}

#define POS_THUMB_OPEN 150
#define POS_THUMB_CLOSE 40
#define POS_INDEX_MIDDLE_OPEN 150 // ya está
#define POS_INDEX_MIDDLE_CLOSE 40 // ya está
#define POS_RING_PINKIE_OPEN 170
#define POS_RING_PINKIE_CLOSE 30

int pos_thumb=0;
int pos_index_middle=0;
int pos_ring_pinkie=0;
int flag_openhand=0;

void move_hand(int pose)
{
  switch (pose) {
    case 0://MYO_POSE_REST
    //if (flag_openhand==1) {
    
     // }
      flag_openhand=0;
      LED_blink();
      break;
    case 1://MYO_POSE_FIST
      LED_blink();
      break;
    case 2://MYO_POSE_WAVE_IN
      pos_thumb = POS_THUMB_CLOSE;
      pos_index_middle = POS_INDEX_MIDDLE_CLOSE;
      pos_ring_pinkie = POS_RING_PINKIE_CLOSE;
      LED_blink();
      break;
    case 3://MYO_POSE_WAVE_OUT
      pos_thumb = POS_THUMB_OPEN;
      pos_index_middle = POS_INDEX_MIDDLE_OPEN;
      pos_ring_pinkie = POS_RING_PINKIE_OPEN;
      flag_openhand=1;
      LED_blink();
      break;
    case 4: //MYO_POSE_FINGERSPREAD
      LED_blink();
      break;
    case 5://MYO_POSE_DOUBLE_TAP
      LED_blink();
      break;
   }

 servo_thumb.write(pos_thumb);
 servo_index_middle.write(pos_index_middle);
 servo_ring_pinkie.write(pos_ring_pinkie);
}

void LED_blink ()
{
    digitalWrite(13, HIGH);delay(50);
    digitalWrite(13, LOW);delay(50);
}

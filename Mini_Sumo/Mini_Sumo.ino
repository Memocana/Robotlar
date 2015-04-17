int  motor1A=A0;
int  motor1B=A1;
int  motor1E=3;
int  motor2A=9;
int  motor2B=10;
int  motor2E=11;
int  sensorF=6;
int  sensorR=8;
int  sensorL=A5;
int  led1=0;
int  led2=1;
int  startModule = 2;
int  lastSeen = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1E, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2E, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensorF, INPUT);
  pinMode(sensorR, INPUT_PULLUP);
  pinMode(sensorL, INPUT_PULLUP);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);  
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);  
}

void movement(int leftMotor, int rightMotor) {
  if (leftMotor < 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,HIGH);
  } 
  else if (leftMotor == 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,LOW);
  } 
  else {
    digitalWrite(motor1A,HIGH);
    digitalWrite(motor1B,LOW);
  }
  //leftMotor E'yi buraya mı alsam?
  if (rightMotor < 0) {
    digitalWrite(motor2A,LOW);
    digitalWrite(motor2B,HIGH);
  } 
  else if (rightMotor == 0) {
    digitalWrite(motor2A,LOW);
    digitalWrite(motor2B,LOW);
  } 
  else {
    digitalWrite(motor2A,HIGH);
    digitalWrite(motor2B,LOW);
  }
  powerMotor(motor1E, abs(leftMotor));
  powerMotor(motor2E, abs(rightMotor));
}

void powerMotor(int port, int power) {
  analogWrite(port, power);
}
void stopper(){
  movement(0,0);
}
void forward(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void backward(int leftMotor, int rightMotor){
  movement(0-leftMotor, 0-rightMotor);
}
void leftOneWheel(int leftMotor){
  movement(leftMotor,0);
}
void rightOneWheel(int rightMotor){
  movement(0,rightMotor);
}
void leftReverse(int leftMotor, int rightMotor){
  movement(-leftMotor, rightMotor);

}
void rightReverse(int leftMotor, int rightMotor){
  movement(leftMotor, -rightMotor);
}

// the loop routine runs over and over again forever:
void loop() {
    if (digitalRead(sensorF)) {
      forward(230, 230);
      lastSeen = 0;
      delay(2);
    } 
    else if (!digitalRead(sensorR)) {
      rightReverse(100,100);
      lastSeen = 2;
      delay(2);
    } 
    else if (!digitalRead(sensorL)) {
      leftReverse(100,100);
      lastSeen = 1;
      delay(2);
    } else if (lastSeen == 1) {
      leftOneWheel(100);
      delay(2);
    } else {
      stopper(0);
      delay(2);
    }
   
}




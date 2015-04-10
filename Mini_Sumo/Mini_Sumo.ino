int  motor1A=A1;
int  motor1B=A0;
int  motor1E=5;
int  motor2A=10;
int  motor2B=9;
int  motor2E=11;
int  sensorF=8;
int  sensorR=6;
int  sensorL=7;
int  button=A2;
int  led1=0;
int  led2=1;
int  lastSensor = 0;

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
  pinMode(sensorR, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(qtrL, INPUT);
  pinMode(qtrR, INPUT);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
}

void movement(int leftMotor, int rightMotor) {
  if (leftMotor < 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,HIGH);
  } else if (leftMotor == 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,LOW);
  } else {
    digitalWrite(motor1A,HIGH);
    digitalWrite(motor1B,LOW);
  }
  //leftMotor E'yi buraya mı alsam?
  if (rightMotor < 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,HIGH);
  } else if (rightMotor == 0) {
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,LOW);
  } else {
    digitalWrite(motor1A,HIGH);
    digitalWrite(motor1B,LOW);
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
  movement(-leftMotor, -rightMotor);
}
void leftOneWheel(int leftMotor, int rightMotor){
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
  digitalWrite(led1, digitalRead(sensorF));
}



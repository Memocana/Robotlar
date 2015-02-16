int motor1A,motor1B, motor2A, motor2B, motor1E, motor2E, led1,led2, sensorF, sensorR, sensorL, qtrR, qtrL, butt1, butt2, butt3;
int lastSensor = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  motor1A=A3;
  motor1B=4;
  motor1E=9;
  motor2A=12;
  motor2B=7;
  motor2E=3;
  sensorF=A4;
  sensorR=A1;
  sensorL=A2;
  qtrR=A3;
  qtrL=0;
  butt1=8;
  butt2=9;
  butt3=A0;
  led1=11;
  led2=10;
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
  pinMode(butt1, INPUT);
  pinMode(butt2, INPUT);
  pinMode(butt3, INPUT);
}

int program(){
  int a=0;
  while(!digitalRead(butt3)){
    while(digitalRead(butt2)||digitalRead(butt1)){
      if(!digitalRead(butt2)&&a<10){
        a++;
      }
      else if(!digitalRead(butt3)){
        a=0;
      }
    }
    delay(200);
    for(int b=1; b<=a; b++){
      digitalWrite(led1, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
      delay(200);
    }
    delay(1000);
  }
  return a;
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
  powerMotor(9, abs(leftMotor));
  powerMotor(3, abs(rightMotor));
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
  movement(leftMotor,rightMotor);
}
void leftOneWheel(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void rightOneWheel(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void leftReverse(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void rightReverse(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(qtrL)) {
    backward(-255,255);
    delay(100);
    rightReverse(255,-255);
    delay(100);
  }
  if (digitalRead(qtrR)) {
    backward(-255,-255);
    delay(100);
    leftReverse(-255,255);
    delay(100);
  }
  if (digitalRead(sensorF)) {
    forward(255,255);
  } else if (digitalRead(sensorL)) {
    leftOneWheel(0,255);
    lastSensor = 1 ;//left
  } else if (digitalRead(sensorR)) {
    rightOneWheel(255,0);
    lastSensor = 2; //right
  } else if (lastSensor == 1) {
    leftReverse(-255,255);
  } else if (lastSensor == 2) {
    rightReverse(255,-255);
  }
  delay(5);
}



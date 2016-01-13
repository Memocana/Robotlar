int motor1A = 12;
int motor1B = 11;
int motor1E = 10;

int motor2A = A0;
int motor2B = A1;
int motor2E = 9;

int led1=0;
int led2=1;
int button=7;
int getRect = 0;

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1E, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2E, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led1, LOW);
  delay(100);
}

void loop() {
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
  analogWrite(motor1E, 100);
  analogWrite(motor2E, 100);
  delay(500);
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,LOW);
  analogWrite(motor1E, 0);
  analogWrite(motor2E, 0);
  digitalWrite(led1, HIGH);
  delay(500);
}

//Movement methods

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
  movement(-1*leftMotor,-1*rightMotor);
}
void leftOneWheel(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void rightOneWheel(int leftMotor, int rightMotor){
  movement(leftMotor,rightMotor);
}
void leftReverse(int leftMotor, int rightMotor){
  movement(-1*leftMotor,rightMotor);
}
void rightReverse(int leftMotor, int rightMotor){
  movement(leftMotor,-1*rightMotor);
}


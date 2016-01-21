int motorRA = 13; //Burayı güncelle baba
int motorRB = 12;
int motorRE = 10;
int motorLA = A1;
int motorLB = A0;
int motorLE = 11;
int sensorF = 7;
int sensorR = 8;
int sensorL = 6;
int qtrL = 5;
int qtrR = 9;
int button = A2;
int dip1 = A5;
int dip2 = A4;
int led1 = 0;//yeşil - sağ
int led2 = 1;//turuncu - sol
int getRect = 0;
int lastTurn = 0;
int mode = 4;
int turns = 0;

void setup() {
  //Burayı sen doldur baba ;)
  pinMode(motorRA, OUTPUT);
  pinMode(motorRB, OUTPUT);
  pinMode(motorRE, OUTPUT);
  pinMode(motorLA, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorLE, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensorF, INPUT);
  pinMode(sensorR, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(qtrR, INPUT);
  pinMode(qtrL, INPUT);
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(button, INPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(2000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  /* while (getRect == 0 && digitalRead(button) == LOW) { //button basılı değilse
   delay(1);
   }
   */
  //getRect = 1;

  //move test
  /*
    forward(150);
   delay(1000);
   forward(0);
   delay(500);
   backward(150);
   delay(1000);
   forward(0);
   delay(500);
   */

  //Sensor Testi
  /*
    if (digitalRead(sensorF)) {
   digitalWrite(led1 ,HIGH);
   } else {
   digitalWrite(led1 ,LOW);
   }
   if (digitalRead(sensorL)) {
   digitalWrite(led2 ,HIGH);
   } else {
   digitalWrite(led2 ,LOW);
   }
   */
  //Savaşma modu

  /*if (digitalRead(dip1) && digitalRead(dip2)) {
    mode = 1;
  } 
  else if (digitalRead(dip1)) {
    mode = 2;
    digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
  } 
  else if (digitalRead(dip2)) {
    mode = 3;
    digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
  } 
  else {
    mode = 4;
  }
  switch (mode){
    case 1:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      break;
    case 2:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      break;
    case 3:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      break;
    case 4:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      break;
    break;
    }*/

  if (!digitalRead(sensorF)) {
    forward(255);
    lastTurn *= 2;
  } 
  else if (!digitalRead(sensorR)) {
    right(130);
    lastTurn = 1;
  } 
  else if (!digitalRead(sensorL)) {
    left(130);
    lastTurn = -1;
  } 
  else if (!digitalRead(qtrR) && !digitalRead(qtrL)) {
    backward(250);
    delay(300);
    lastTurn = 0;
    //right(40);
  } 
  else if (!digitalRead(qtrR)) {
    backward(250);
    delay(300);
    lastTurn = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    
    //right(40);
  } 
  else if (!digitalRead(qtrL)) {
    backward(250);
    delay(300);
    lastTurn = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    //left(40);
  } 
  else if (lastTurn == -2) {
    right(150);
  } 
  else if (lastTurn == 2) {
    left(150);
  } 
  else if (lastTurn == -1) {
    left(150);
    lastTurn = -1;
  } 
  else if (lastTurn == 1) {
    right(150);
    lastTurn = 1;
  } 
  else {
    right(120);
    turns++;
    if (turns % 10 == 9) {
      forward(50);
    }
  }
  delay(8);

  // 30 forw, 250 back (d600), 25 l, 25 r
}

void forward(int powa) {
  digitalWrite(motorRA, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLA, HIGH);
  digitalWrite(motorLB, LOW);
  analogWrite(motorRE, powa);
  analogWrite(motorLE, powa);
}

void backward(int powa) {
  digitalWrite(motorRA, LOW);
  digitalWrite(motorRB, HIGH);
  digitalWrite(motorLA, LOW);
  digitalWrite(motorLB, HIGH);
  analogWrite(motorRE, powa);
  analogWrite(motorLE, powa);
}

void right(int powa) {
  digitalWrite(motorRA, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLA, LOW);
  digitalWrite(motorLB, HIGH);
  analogWrite(motorRE, powa + 5);
  analogWrite(motorLE, powa);
}

void left(int powa) {
  digitalWrite(motorRA, LOW);
  digitalWrite(motorRB, HIGH);
  digitalWrite(motorLA, HIGH);
  digitalWrite(motorLB, LOW);
  analogWrite(motorRE, powa);
  analogWrite(motorLE, powa + 5);
}
void slowright(int powa) {
  digitalWrite(motorRA, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLA, LOW);
  digitalWrite(motorLB, HIGH);
  analogWrite(motorRE, powa);
  analogWrite(motorLE, 0);
}

void slowleft(int powa) {
  digitalWrite(motorRA, HIGH);
  digitalWrite(motorRB, LOW);
  digitalWrite(motorLA, LOW);
  digitalWrite(motorLB, HIGH);
  analogWrite(motorRE, 0);
  analogWrite(motorLE, powa);
}



int motorRA = A5; //Burayı güncelle baba
int motorRB = A4;
int motorRE = 5;
int motorLA = A3;
int motorLB = A2;
int motorLE = 6;
int sensorF = 9;
int sensorR = 8;
int sensorL = 7;
int qtrL = 3;
int qtrR = 4;
int button = 12;
int dip1 = 11;
int dip2 = 10;
int led1 = 0;//yeşil - sağ
int led2 = 1;//turuncu - sol
int led3 = 2;
int getRect = 0;
int lastTurn = 0;
int mode = 4;
int turns = 0;

int power = 150; //sadece dönüşler için bu, Mr. Muscle Def. 150, Tesla Def, 100

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
    if (!digitalRead(qtrR) || !digitalRead(qtrL)) {
      backward(255);
      delay(power*2);
      forward(0);
      lastTurn = 0;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(1000);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      delay(1000);
      //right(40);
    } 
  } 
  else if (!digitalRead(sensorR)) {
    right(power);
    lastTurn = 1;
  } 
  else if (!digitalRead(sensorL)) {
    left(power);
    lastTurn = -1;
  } 
  else if (!digitalRead(qtrR) && !digitalRead(qtrL)) {
    backward(250);
    delay(power*2);
    lastTurn = 0;
    //right(40);
  } 
  else if (!digitalRead(qtrR)) {
    backward(250);
    delay(power*2);
    lastTurn = 0;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    //right(40);
  } 
  else if (!digitalRead(qtrL)) {
    backward(250);
    delay(power*2);
    lastTurn = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    //left(40);
  } 
  else if (lastTurn == -2) {
    right(power);
  } 
  else if (lastTurn == 2) {
    left(power);
  } 
  else if (lastTurn == -1) {
    left(power);
    lastTurn = -1;
  } 
  else if (lastTurn == 1) {
    right(power);
    lastTurn = 1;
  } 
  else {
    right(120);
    turns++;
    if (turns % 10 == 9) {
      forward(60);
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






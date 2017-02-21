int motorRA = 6; //Burayı güncelle baba
int motorRB = 7;
int motorRE = 5;
int motorLA = 4;
int motorLB = 2;
int motorLE = 3;
int sensorF = A1;
int sensorR = A0;
int sensorL = A2;
int qtrL = 12;
int qtrR = 11;
int button1 = A5;
int button2 = A4;
/*int dip1 = A5;
 int dip2 = A4;*/
int led1 = 0;//yeşil - sağ
int led2 = 1;//turuncu - sol
int getRect = false;
int wait = true
int lastTurn = 0;
int mode = 4;
int turns = 0;

int power = 60; //sadece dönüşler için bu, Mr. Muscle Def. 60, Tesla Def, 100

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

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(2000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {

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
    if (digitalRead(sensorR)) {
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
  /*
  if (digitalRead(dip1) && digitalRead(dip2)) {
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
   }
   */

  if (digitalRead(button1) == LOW) {
    getRect = !getRect;
  }

  if (getRect) {
    if (wait) {
      delay(1000);
      if (mode == 1) {
        backward(255);
        delay(30);
      }
      else if (mode == 2) {
        forward(255);
        delay(30);
      }
      else if (mode == 3) {
        forward(255);
        delay(30);
      }
      else if (mode == 4) {
        backward(255);
        delay(30);
      }
      wait = false;
    }
    getRect = true;
    if (!digitalRead(sensorF)) {
      forward(255);
      lastTurn *= 2;
      if (!digitalRead(qtrR) || !digitalRead(qtrL)) {
        backward(255);
        delay(power*2);
        forward(0);
        lastTurn = 0;
        //digitalWrite(led1, LOW);
        //digitalWrite(led2, LOW);
        delay(1000);
        //digitalWrite(led1, HIGH);
        //digitalWrite(led2, HIGH);
        delay(1000);
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
      //digitalWrite(led1, HIGH);
      //digitalWrite(led2, LOW);

      //right(40);
    } 
    else if (!digitalRead(qtrL)) {
      backward(250);
      delay(power*2);
      lastTurn = 0;
      //igitalWrite(led1, LOW);
      //digitalWrite(led2, HIGH);
      //left(40);
    } 
    else if (lastTurn == -2) {
      right(power-20);
    } 
    else if (lastTurn == 2) {
      left(power-20);
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
      right(power);
      turns++;
      if (turns % 20 == 0) {
        turns /= 20
       forward(power);
       }
    }
  } 
  else {
    getRect = false;
    wait = true;
    if (digitalRead(qtrR)) {
      digitalWrite(led1 ,HIGH);
    } 
    else {
      digitalWrite(led1 ,LOW);
    }
    if (digitalRead(qtrL)) {
      digitalWrite(led2 ,HIGH);
    } 
    else {
      digitalWrite(led2 ,LOW);
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










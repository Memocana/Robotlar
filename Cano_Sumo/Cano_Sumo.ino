int motor1A = 0; //Burayı güncelle baba
int motor1B = 0;
int motor1E = 0;
int motor2A = 0;
int motor2B = 0;
int motor2E = 0;
int sharpF= 0;
int sharpR = 0;
int sharpL = 0;
int qtr1 = 0;
int qtr2 = 0;
int button = 0;
int getRECT = 0;
int LED = 0;

void setup() {
  //Burayı sen doldur baba ;)
}

void loop() {
  while(getRect == 0 && digitalRead(button) == LOW) { //button basılı değilse
    digitalWrite(LED, !digitalRead(LED));
    delay(50);
  }
  getRect = 1;
  
  //Savaşma modu
  
  if (digitalRead(sharpF)) {
    forward(150);
  } else if (digitalRead(sharpR)) {
    right(150);
  } else if (digitalRead(sharpL)) {
    left(150);
  } else if (digitalRead(qtr1)) {
    backward(150);
    delay(200);
    right(150);
    delay(50);
  } else if (digitalRead(qtr2)) {
    backward(150);
    delay(200);
    left(150);
    delay(50);
  } else {
    forward(150);
  }
  delay(20);
}

void forward(int powa) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor1E, powa);
  digitalWrite(motor2E, powa);
}

void backward(int powa) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  digitalWrite(motor1E, powa);
  digitalWrite(motor2E, powa);
}

void right(int powa) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  digitalWrite(motor1E, powa);
  digitalWrite(motor2E, powa);
}

void left(int powa) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor1E, powa);
  digitalWrite(motor2E, powa);
}

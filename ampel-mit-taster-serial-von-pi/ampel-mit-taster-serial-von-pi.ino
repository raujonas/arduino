// minicom -b 9600 -o -D /dev/ttyACM0

int ROT = 5;
int GELB = 6;
int GRUEN = 7;

int F_ROT = 8;
int F_GRUEN = 9;

int TASTER = 13;
int tasterInput;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(ROT, OUTPUT);
  pinMode(GELB, OUTPUT);
  pinMode(GRUEN, OUTPUT);
  pinMode(F_ROT, OUTPUT);
  pinMode(F_GRUEN, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(F_ROT, HIGH);
  digitalWrite(GRUEN, HIGH);

  tasterInput = digitalRead(TASTER);

  if (tasterInput == LOW) {
    ampelSchalten();
  }

  if (Serial.available() > 0) {
    String message = Serial.readString();
    ampelSchalten();
  }
}

void ampelSchalten() {
    //delay(3000);
    digitalWrite(GRUEN, LOW);
    digitalWrite(GELB, HIGH);
    delay(500);
    digitalWrite(GELB, LOW);
    digitalWrite(ROT, HIGH);
    delay(500);

    digitalWrite(F_ROT, LOW);
    digitalWrite(F_GRUEN, HIGH);
    delay(1000);
    digitalWrite(F_GRUEN, LOW);
    digitalWrite(F_ROT, HIGH);
    delay(500);

    digitalWrite(GELB, HIGH);
    delay(500);
    digitalWrite(ROT, LOW);
    digitalWrite(GELB, LOW);
}

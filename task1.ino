#define enA 10
#define enB 11
#define rf 3
#define lf 5
#define rb 6
#define lb 9
#define ldr_left A0
#define ldr_right A1
#define ultraecho 12
#define trigger 13
#define mindist 10
char ch;
float t;
float a,b ;
void setup() {
    pinMode(ldr_left, INPUT);
    pinMode(ldr_right, INPUT);
    pinMode(ultraecho, INPUT);
    pinMode(trigger, OUTPUT);
    pinMode(rf, OUTPUT);
    pinMode(lf, OUTPUT);
    pinMode(rb, OUTPUT);
    pinMode(lb, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    digitalWrite(rf, LOW);
    digitalWrite(lf, LOW);
    digitalWrite(rb, LOW);
    digitalWrite(lb, LOW);
    Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
  ch = Serial.read();
  while(ch=='f')
  {
   digitalWrite(trigger,LOW);
   delayMicroseconds(2);
   digitalWrite(trigger,HIGH);
   delayMicroseconds(10);
   t = pulseIn(ultraecho, HIGH);
   float dist = (0.33 * t) /2;

   if(dist >= mindist)
   {
    a = analogRead(ldr_left);
    b = analogRead(ldr_right);
    digitalWrite(rf, HIGH);
    digitalWrite(lf, HIGH);
    digitalWrite(rb, LOW);
    digitalWrite(lb, LOW);
    int speed1 = map(a, 4, 448, 0, 255);
    int speed2 = map(b, 4, 448, 0, 255);

    analogWrite(enA, speed1);
    analogWrite(enB, speed2);
  }
  else
  {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
  
  }
  }
}


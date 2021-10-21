#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3

#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5

#define JOY_BUT 9
#define JOY_Y A1
#define JOY_X A0

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);

  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  pinMode(JOY_BUT, INPUT);
  pinMode(JOY_Y, INPUT);
  pinMode(JOY_X, INPUT);
}

void loop() {
  int joyY = analogRead(JOY_Y);
  int joyX = analogRead(JOY_X);
  
  Serial.println((String)"Joystick X: " + (joyX - 506) + ", Y: " + (joyY - 491));
  
  if (digitalRead(JOY_BUT) == HIGH) {
    Serial.println("button");
  }
  
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
}

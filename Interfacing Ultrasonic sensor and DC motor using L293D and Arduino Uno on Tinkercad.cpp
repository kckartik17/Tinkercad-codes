# define input_1 10
# define input_2 9
# define pwm A0
int cm = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(input_1,OUTPUT);
  pinMode(input_2,OUTPUT);
  pinMode(pwm,OUTPUT);
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  if(cm<20){
    digitalWrite(input_1,HIGH);
    digitalWrite(input_2,LOW);
    analogWrite(pwm,100);
  }else if(cm>19 && cm<=35){
  digitalWrite(input_1,LOW);
    digitalWrite(input_2,LOW);
  }else{
    digitalWrite(input_1,LOW);
    digitalWrite(input_2,HIGH);
    analogWrite(pwm,100);
  }
  
  delay(100); // Wait for 100 millisecond(s)
}

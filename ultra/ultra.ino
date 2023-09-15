 int trigPin = 5;
 int echoPin = 18;
 int duration;
 int distance;
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}
 void loop() 
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);
}

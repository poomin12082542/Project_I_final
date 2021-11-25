int dir1PinA = D1;
int dir2PinA = D2;
int speedPinA = D0;
void setup()
{
  Serial.begin(9600);
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
}
void loop()
{
  analogWrite(speedPinA, HIGH); 
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  Serial.println("motor forward");  
  delay(3000);
  analogWrite(speedPinA, HIGH); 
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  Serial.println("motor backward");  
  delay(3000);
}

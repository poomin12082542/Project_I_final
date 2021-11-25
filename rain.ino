int sensor_Pin = A0; 

void setup() {
  Serial.begin(9600);  
}
 
void loop() {
  int sensor_Value = analogRead(sensor_Pin);  
  Serial.print("Rain/Water Detection Sensor Value = ");  
  Serial.println(sensor_Value);  
  delay(500);  
 
}

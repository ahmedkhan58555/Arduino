// C++ code

int echopin = 9;
int triggerpin = 10;
int red_led = 6;
int green_led = 12;
float duration;
float distance;
void setup()
{
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
}

void loop()
{ 
  digitalWrite(triggerpin, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(triggerpin, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(triggerpin, LOW);

  duration =  pulseIn (echopin , HIGH);
  distance = duration * 0.034/2; 
  
 // digitalWrite(red_led, LOW);
 // digitalWrite(green_led, LOW);
  
  if (distance <= 10)
  {
    digitalWrite(red_led, HIGH);
    delay(100);
    digitalWrite(green_led, LOW);
    delay(100);
  }
  else if (distance >= 20)
  {
    digitalWrite(red_led, LOW);
    delay(100);
    digitalWrite(green_led, HIGH);
    delay(100);
  } 
  else
  {
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
  }
    
  Serial.print ("Distance :");
  Serial.print (distance);
  Serial.println("cm");        
}
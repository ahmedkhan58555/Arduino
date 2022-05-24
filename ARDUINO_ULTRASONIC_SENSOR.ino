//int echopin = 9;
//int triggerpin = 10;
////int red_led = 6;
////int green_led = 12;
////float duration;
////float distance;
//void setup()
//{
//  pinMode(triggerpin, OUTPUT);
//  pinMode(echopin, INPUT);
//  Serial.begin(9600);
//  //  pinMode(red_led, OUTPUT);
//  //  pinMode(green_led, OUTPUT);
//
//}
//
//void loop()
//{
//  digitalWrite(triggerpin, LOW);
//  delayMicroseconds(2); // Wait for 1000 millisecond(s)
//  digitalWrite(triggerpin, HIGH);
//  delayMicroseconds(10); // Wait for 1000 millisecond(s)
//  digitalWrite(triggerpin, LOW);
//  //252525
//  float duration =  pulseIn (echopin , HIGH);
//  float distance = duration * 0.034 / 2;
//  //
//  // // digitalWrite(red_led, LOW);
//  // // digitalWrite(green_led, LOW);
//  //
//  //  if (distance <= 10)
//  //  {
//  //    digitalWrite(red_led, HIGH);
//  //    delay(100);
//  //    digitalWrite(green_led, LOW);
//  //    delay(100);
//  //  }
//  //  else if (distance >= 20)
//  //  {
//  //    digitalWrite(red_led, LOW);
//  //    delay(100);
//  //    digitalWrite(green_led, HIGH);
//  //    delay(100);

int echopin = 9;
int triggerpin = 10;
int red_led = 6;
int led_2 = 12;
float duration;
float distance;
void setup()
{
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led_2, OUTPUT);
  pinMode(red_led, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(triggerpin, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(triggerpin, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(triggerpin, LOW);

  duration =  pulseIn (echopin , HIGH);
  distance = duration * 0.034 / 2;



  Serial.print ("Distance :");
  Serial.print (distance);
  Serial.println("cm");

  if (distance <= 10)
  {
    digitalWrite(red_led, HIGH);
    Serial.println("LED 1 is ON");
    digitalWrite(led_2, LOW);
    Serial.println("LED 2 is OFF");
  }
  else if (distance > 10 and distance <= 20)
  {
    digitalWrite(red_led, LOW);
    Serial.println("LED 2 is ON");
    digitalWrite(led_2, HIGH);
    Serial.println("LED 1 is OFF");
  }
  else
  {
    digitalWrite(red_led, LOW);
    Serial.println("Both LED's ARE OFF");
    digitalWrite(led_2, LOW);
  }
}

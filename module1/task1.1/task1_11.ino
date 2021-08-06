// C++ code
//
int val = 0;
int state = LOW;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(2);
  if(val == HIGH)
  {
    digitalWrite(13,HIGH);
    if(state == LOW){
     	Serial.println("Motion detected!");
      	state = HIGH;
    }
  }
  else
  {
    digitalWrite(13,LOW);
    if(state == HIGH){
      Serial.println("Motion Stoped!");
      state = LOW;
    }
  }
  

}
